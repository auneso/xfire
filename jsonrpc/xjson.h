#ifndef __XJSON_H__
#define __XJSON_H__

#ifdef __cplusplus
extern "C"
{
#endif

/* XJSON Types: */
#define XJSON_False   0
#define XJSON_True    1
#define XJSON_NULL    2
#define XJSON_Number  3
#define XJSON_String  4
#define XJSON_Array   5
#define XJSON_Object  6
  
#define XJSON_IsReference 256

/* The XJSON structure: */
typedef struct XJSON {
  struct XJSON *next,*prev;  /* next/prev allow you to walk array/object chains. 
                                Alternatively, use GetArraySize/GetArrayItem/GetObjectItem */
  struct XJSON *child;       /* An array or object item will have a child pointer pointing 
                                to a chain of the items in the array/object. */

  int type;                  /* The type of the item, as above. */

  char *valuestring;         /* The item's string, if type==XJSON_String */
  int valueint;              /* The item's number, if type==XJSON_Number */
  double valuedouble;        /* The item's number, if type==XJSON_Number */

  char *string;              /* The item's name string, if this item is the child of, or is in the list of subitems of an object. */
} XJSON;

typedef struct XJSON_Hooks {
  void *(*malloc_fn)(size_t sz);
  void (*free_fn)(void *ptr);
} XJSON_Hooks;

/* Supply malloc, realloc and free functions to XJSON */
extern void XJSON_InitHooks (XJSON_Hooks* hooks);


/* Supply a block of JSON, and this returns a XJSON object you can interrogate. Call XJSON_Delete when finished. */
extern XJSON *XJSON_Parse (const char *value);

/* Render a XJSON entity to text for transfer/storage. Free the char* when finished. */
extern char  *XJSON_Print (XJSON *item);

/* Render a XJSON entity to text for transfer/storage without any formatting. Free the char* when finished. */
extern char  *XJSON_PrintUnformatted (XJSON *item);

/* Delete a XJSON entity and all subentities. */
extern void   XJSON_Delete (XJSON *c);

/* Returns the number of items in an array (or object). */
extern int    XJSON_GetArraySize (XJSON *array);

/* Retrieve item number "item" from array "array". Returns NULL if unsuccessful. */
extern XJSON *XJSON_GetArrayItem (XJSON *array,int item);

/* Get item "string" from object. Case insensitive. */
extern XJSON *XJSON_GetObjectItem (XJSON *object,const char *string);

/* For analysing failed parses. This returns a pointer to the parse error.
   You'll probably need to look a few chars back to make sense of it.
   Defined when XJSON_Parse() returns 0. 0 when XJSON_Parse() succeeds. */
extern const char *XJSON_GetErrorPtr ();
  
/* These calls create a XJSON item of the appropriate type. */
extern XJSON *XJSON_CreateNull ();
extern XJSON *XJSON_CreateTrue ();
extern XJSON *XJSON_CreateFalse ();
extern XJSON *XJSON_CreateBool (int b);
extern XJSON *XJSON_CreateNumber (double num);
extern XJSON *XJSON_CreateString (const char *string);
extern XJSON *XJSON_CreateArray ();
extern XJSON *XJSON_CreateObject ();

/* These utilities create an Array of count items. */
extern XJSON *XJSON_CreateIntArray (int *numbers,int count);
extern XJSON *XJSON_CreateFloatArray (float *numbers,int count);
extern XJSON *XJSON_CreateDoubleArray (double *numbers,int count);
extern XJSON *XJSON_CreateStringArray (const char **strings,int count);

/* Append item to the specified array/object. */
extern void XJSON_AddItemToArray (XJSON *array, XJSON *item);
extern void  XJSON_AddItemToObject (XJSON *object,const char *string,XJSON *item);

/* Append reference to item to the specified array/object.
  Use this when you want to add an existing XJSON to a new XJSON, but don't want to corrupt your existing XJSON. */
extern void XJSON_AddItemReferenceToArray (XJSON *array, XJSON *item);
extern void XJSON_AddItemReferenceToObject (XJSON *object,const char *string,XJSON *item);

/* Remove/Detatch items from Arrays/Objects. */
extern XJSON *XJSON_DetachItemFromArray (XJSON *array,int which);
extern void   XJSON_DeleteItemFromArray (XJSON *array,int which);
extern XJSON *XJSON_DetachItemFromObject (XJSON *object,const char *string);
extern void   XJSON_DeleteItemFromObject (XJSON *object,const char *string);
  
/* Update array items. */
extern void XJSON_ReplaceItemInArray (XJSON *array,int which,XJSON *newitem);
extern void XJSON_ReplaceItemInObject (XJSON *object,const char *string,XJSON *newitem);

/* rger: added helpers */

char *XJSON_print_number(XJSON *item);

#define XJSON_AddNullToObject(object,name)      XJSON_AddItemToObject(object, name, XJSON_CreateNull())
#define XJSON_AddTrueToObject(object,name)      XJSON_AddItemToObject(object, name, XJSON_CreateTrue())
#define XJSON_AddFalseToObject(object,name)     XJSON_AddItemToObject(object, name, XJSON_CreateFalse())
#define XJSON_AddNumberToObject(object,name,n)  XJSON_AddItemToObject(object, name, XJSON_CreateNumber(n))
#define XJSON_AddStringToObject(object,name,s)  XJSON_AddItemToObject(object, name, XJSON_CreateString(s))

#ifdef __cplusplus
}
#endif

#endif
