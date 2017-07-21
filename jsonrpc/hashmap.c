/*
** 2013-09-06 HDS xmalloc -> xzalloc
*/
#include "hashmap.h"
#include "xalloc.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct hashmap_obj;

typedef struct hashmap_entry
{
   char*        key;
   hashmap_any value;
   int         index;
   int         hash;
   struct hashmap_entry*  next;
   struct hashmap_obj*   map;
} hashmap_entry;

typedef struct hashmap_obj
{
   float       loadFactor;
   int         initialCapacity;
   int         count;
   int         threshold;
   int         size;
   int         tableSize;
   struct hashmap_entry** table;
   
} hashmap_obj, *hashmap_ref;

hashmap hashmap_create()
{
  hashmap_ref map = xzalloc(sizeof(hashmap_obj));   
  map->initialCapacity = 101;
  map->tableSize = map->initialCapacity;
  map->loadFactor = 0.75f;
  map->table = xzalloc(sizeof(hashmap_entry*) * map->tableSize);
  map->threshold = (int)(map->initialCapacity * map->loadFactor);
   
  return (hashmap) map;
}

void hashmap_free (hashmap m)
{
  hashmap_ref map = (hashmap_ref) m;

  for (int i = 0; i < map->tableSize ; ++i) {
    for (hashmap_entry *e = map->table[i] ; e; ) {
      hashmap_entry *c = e;
      e = c->next;
      xfree(c);
    }
  }

  xfree(map->table);
  xfree(map);
}

int hashmap_get_hash (const char *key)
{
  int h = 0;
   
  int off = 0;
  int len = strlen(key);
   
  if (len < 16) {
    for (int i = len ; i > 0; i--) {
      h = (h * 37) + key[off++];
    }
  } 
  else {
    // only sample some characters
    int skip = len / 8;
    for (int i = len ; i > 0; i -= skip, off += skip) {
      h = (h * 39) + key[off];
    }
  }
  return h;
}

void hashmap_rehash (hashmap_ref map) 
{
  int oldCapacity = map->tableSize;
  hashmap_entry** oldMap = map->table;
   
  int newCapacity = oldCapacity * 2 + 1;
  hashmap_entry** newMap = xzalloc(sizeof(hashmap_entry) * newCapacity);
   
  map->threshold = (int)(newCapacity * map->loadFactor);
  map->table = newMap;
  map->tableSize = newCapacity;

  for (int i = oldCapacity ; i-- > 0 ;) {
    for (hashmap_entry* old = oldMap[i] ; old; ) {
      hashmap_entry* e = old;
      old = old->next;
   
      int index = (e->hash & 0x7FFFFFFF) % newCapacity;
      e->next = newMap[index];
      e->index = index;
      newMap[index] = e;
    }
  }
  xfree(oldMap);
}

hashmap_any hashmap_get (hashmap m, const char* key)
{
  hashmap_ref map = (hashmap_ref) m;
  hashmap_entry** table = map->table;

  int hash = hashmap_get_hash(key);
  int index = (hash & 0x7FFFFFFF) % map->tableSize;
  for (hashmap_entry* e = table[index]; e; e = e->next) {
    if ((e->hash == hash) && strcmp(key, e->key) == 0) {
      return e->value;
    }
  }
  return 0;
}

hashmap_any hashmap_put (hashmap m, char* key, hashmap_any value)
{
  hashmap_ref map = (hashmap_ref) m;
  hashmap_entry** table = map->table;

  int hash = hashmap_get_hash(key);
  int index = (hash & 0x7FFFFFFF) % map->tableSize;
  for (hashmap_entry* e = table[index]; e; e = e->next) {
    if ((e->hash == hash) && strcmp(key, e->key) == 0) {
      void* old = e->value;
      e->value = value;
      return old;
    }
  }
 
  if (map->count >= map->threshold) {
    // Rehash the table if the threshold is exceeded
    hashmap_rehash(map);
    table = map->table;
    index = (hash & 0x7FFFFFFF) % map->tableSize;
  }
 
  // Creates the new entry.
  hashmap_entry *e = xmalloc(sizeof(hashmap_entry));
  e->hash = hash;
  e->key  = key;
  e->value = value;
  e->next  = table[index];
  e->index = index;
  e->map = map;
    
  map->count++;
  map->table[index] = e;
  
  return 0;
}

hashmap_iterator hashmap_iterate (hashmap m)
{
  hashmap_ref map = (hashmap_ref) m;

  for (int i = 0; i < map->tableSize ; ++i) {
    if (map->table[i]) {
      return (hashmap_iterator) map->table[i];
    }
  }
  return 0;
}

char* hashmap_next (hashmap_iterator *iterator)
{
  hashmap_entry* e  = (hashmap_entry*) *iterator;
  char* key = 0;
   
  if (e) {
    hashmap_ref map = e->map;
    key = e->key;
      
    if (e->next) {
      e = e->next;
    }
    else {
      for (int i = e->index + 1; i < map->tableSize ; ++i) {
        if ((e = map->table[i])) {
          break;
        }
      }
    }      
    *iterator = e;
   }
   return key;
}


