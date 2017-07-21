#ifndef __JSON_SYSTEM_H__
#define __JSON_SYSTEM_H__

void Proc_System_Info (struct json_object *request, struct json_object *response, void *info);
void Proc_System_Upgrade (struct json_object *request, struct json_object *response, void *info);
void Proc_System_Reboot (struct json_object *request, struct json_object *response, void *info);
#endif

