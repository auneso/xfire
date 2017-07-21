#ifndef __JSON_ALERT_DATA_H__
#define __JSON_ALERT_DATA_H__

void Proc_View_Alert(struct json_object *request, struct json_object *response, void *info);
void Proc_View_Alert_List(struct json_object *request, struct json_object *response, void *info);
void Proc_View_Alert_List_Search(struct json_object *request, struct json_object *response, void *info);

#endif

