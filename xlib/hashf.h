#ifndef __HASHF_H__
#define __HASHF_H__
#include "xtypes.h"

int prime_size (int size, int *idx);
int prime_next_size (int *idx);
ub32 Murmur_hash2 (ub8 *key, int len); 
ub32 Murmur_hash3 (const char* data, const int len);

#if 0
unsigned int MurmurHash2A (const void * key, int len, unsigned int seed);
unsigned int MurmurHashAligned2 (const void * key, int len, unsigned int seed);
unsigned int MurmurHashNeutral2 ( const void * key, int len, unsigned int seed);
int prime_size (int size, int *prime_offset);
#endif

#endif
