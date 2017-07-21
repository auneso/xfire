#ifndef __JSON_XARP_LIST_H__
#define __JSON_XARP_LIST_H__

void Proc_XARP_Insert (struct json_object *request, struct json_object *response, void *info);
void Proc_XARP_Remove (struct json_object *request, struct json_object *response, void *info);
void Proc_XARP_Update (struct json_object *request, struct json_object *response, void *info);
void Proc_View_XARP_List (struct json_object *request, struct json_object *response, void *info);

#endif
