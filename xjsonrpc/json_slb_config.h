#ifndef __JSON_SLB_CONFIG_H__
#define __JSON_SLB_CONFIG_H__

void Proc_SLB_Config_Insert (struct json_object *request, struct json_object *response, void *info);
void Proc_SLB_Config_Remove (struct json_object *request, struct json_object *response, void *info);
void Proc_SLB_Config_Update (struct json_object *request, struct json_object *response, void *info);
void Proc_SLB_Config_Apply  (struct json_object *request, struct json_object *response, void *info);
void Proc_SLB_Config_View   (struct json_object *request, struct json_object *response, void *info);
void Proc_SLB_Config_Upload (struct json_object *request, struct json_object *response, void *info);

#endif
