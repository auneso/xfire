#ifndef __JSON_BLACK_HOLE_H__
#define __JSON_BLACK_HOLE_H__

void Proc_View_Black_Hole(struct json_object *request, struct json_object *response, void *info);

void Proc_Add_Black_List(struct json_object *request, struct json_object *response, void *info);
void Proc_Del_Black_List(struct json_object *request, struct json_object *response, void *info);
void Proc_View_Black_List(struct json_object *request, struct json_object *response, void *info);

#endif

