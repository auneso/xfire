/*
 * JSON RPC Bridge
 *
 * This provides a simple bridge implementation to process requests in JSON 
 * format and delegate to callback methods. It provide handling for system
 * methods although this is limited to the listMethods method.
 *
 * There is minimal error handling in this code.
 *
 * @author Marc G. Smith
 */
 
#ifndef __JSONRPC_H
#define __JSONRPC_H 1

struct jsonrpc_peer {
  long ip;
  int port;
};

/**
 * Prototype for user defined method handlers.
 * the request object should be returned with
 * only the "result" key and the user object.
 */
typedef void (*jsonrpc_method)(struct json_object *request, struct json_object *response, void *info);

/**
 * Register a method handler. 
 * @param name the lookup name of the method such as myobj.get
 * @param method pointer to method handling requests to this name.
 */
extern void jsonrpc_add_method (char* name, jsonrpc_method method);

/**
 * Set the number of events the bus should hold before old events start
 * getting discarded.
 * @param size the size of the event list.
 */
extern void jsonrpc_set_event_list_size (int size);

/**
 * Add an event to the event bus. The event type is an arbitary
 * name that clients can switch against. 
 * @param eventType the event type name.
 * @param eventData the data related to the event to be passed to client.
 *        
 */
extern void jsonrpc_add_event (char* eventType, struct json_object *eventData);


/**
 * Process a JSON format request and returns a JSON format response.
 * Typically the web server query is passed in and the response 
 * submitted to the client is the response from this method. The 
 * response must be freed using free() after it has been used.
 * @param request a JSON request string.
 * @return a JSON formatted response. This must be freed after use.
 */	
extern char* jsonrpc_process (char* request);

#endif /* __JSONRPC_H */
	
