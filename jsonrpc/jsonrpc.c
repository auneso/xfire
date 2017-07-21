/*
** 2011-06-17 HDS  int jsonrpc_service return check
** 2012-08-28 HDS  json_tokener_parse return check
** 2013-06-18 HDS  json upgrade (https://github.com/json-c/json-c)
** 2014-10-24 HDS  jsonrpc_service -> jsonrpc_request_method return check
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#include "json.h"
#include "arraylist.h"
#include "hashmap.h"
#include "cbuffer.h"
#include "jsonrpc.h"
#include "xalloc.h"


typedef struct jsonrpc_event {
  long    id;
  char   *type;
  time_t  tm; 
  struct  json_object *data;
} jsonrpc_event;

static hashmap methodMap = NULL;
static circular_buffer eventBus = NULL;
static jsonrpc_event *spareEvent = NULL;
static long eventIds = 0;


struct json_object *jsonrpc_clone_object (struct json_object* object)
{
  return json_tokener_parse(json_object_to_json_string(object));
}

void jsonrpc_add_method (char* name, jsonrpc_method method)
{
  if (!methodMap) methodMap = hashmap_create();
  hashmap_put(methodMap, name, method);  
}

void jsonrpc_system_list_methods (struct json_object *request, struct json_object *response)
{
  struct json_object *methods = json_object_new_array();
  
  if (methodMap) {
    char* key;
    hashmap_iterator it = hashmap_iterate(methodMap);
    while ((key = hashmap_next(&it)) != 0) {
      json_object_array_add( methods, json_object_new_string(key));
    }
    json_object_array_add(methods,  json_object_new_string("system.events"));
  }    
  json_object_object_add(response, "result", methods);
}

void jsonrpc_system_events (struct json_object *request, struct json_object *response)
{
  struct json_object *params = json_object_object_get(request, "params");

  int lastEvent = json_object_get_int(json_object_array_get_idx(params, 0));
  
  struct json_object *events = json_object_new_array();

  if (eventBus) {
    int count = circular_buffer_size(eventBus);
    for (int i = 0; i < count; ++i) {
      jsonrpc_event *event = (jsonrpc_event*) circular_buffer_get(eventBus, i);
      if (lastEvent >= event->id) continue;
      struct json_object *jevent = json_object_new_object();
      json_object_object_add(jevent, "id", json_object_new_int(event->id));
      json_object_object_add(jevent, "type", json_object_new_string(event->type));
      json_object_object_add(jevent, "data", jsonrpc_clone_object(event->data));
      
      char timestamp[128];
      strftime(timestamp, 128, "%x %X", localtime(&(event->tm)));      
      json_object_object_add(jevent, "time", json_object_new_string(timestamp));
      json_object_array_add(events, jevent);
    }
  }    

  json_object_object_add(response, "result", events);
}

const char *jsonrpc_request_method (struct json_object *request)
{
  struct json_object *value;
  value = json_object_object_get(request, "method");
  return json_object_get_string(value);
}

static int jsonrpc_service (struct json_object *request, struct json_object *response)
{
  const char *methodName = jsonrpc_request_method(request);
  
  if (methodName == NULL) {
    return 0;
  } 
#ifdef JSON_RPC_DEBUG
  printf("method name  = %s\n", methodName);
#endif

#ifdef JSON_RPC_STATUS
  if (strcmp(methodName, "system.listMethods") == 0) {
    jsonrpc_system_list_methods(request, response);
    return 1; 
  } else
  if (strcmp(methodName, "system.events") == 0) {
    jsonrpc_system_events(request, response);
    return 1; 
  } else
#endif

  if (methodMap) {
    jsonrpc_method method = hashmap_get(methodMap, methodName);
    if (method) {
      (*method)(request, response, NULL);
      return 1; 
    }
  }
  return 0;
} 

void jsonrpc_set_event_list_size (int size)
{
  if (eventBus) circular_buffer_free(eventBus);
  eventBus = circular_buffer_create(size);
}

void jsonrpc_add_event (char *eventType, struct json_object *eventData)
{
  if (!eventBus) jsonrpc_set_event_list_size(100);
  
  jsonrpc_event *event = spareEvent ?  spareEvent : (jsonrpc_event*)xmalloc(sizeof(jsonrpc_event));
  
  event->id   = ++eventIds;
  event->data = json_object_get(eventData);
  event->type = (char*)xmalloc(strlen(eventType) + 1);
  strcpy(event->type, eventType);
  event->tm = time(NULL);
  
  spareEvent = circular_buffer_push(eventBus, event);
  
  if (spareEvent) {
    json_object_put(event->data);
    xfree(event->type);
  }  
}

char *jsonrpc_process (char *request_text)
{
  char *response_text = NULL;
  struct json_object *request;
  struct json_object *response;

  if ((request = json_tokener_parse(request_text))) {
    response = json_object_new_object();

    if (jsonrpc_service(request, response)) {
      const char *text = json_object_to_json_string(response);
      response_text = xstrdup((char *)text);
    } 
  
    json_object_put(request);
    json_object_put(response);
  }
  
  return response_text;
}

