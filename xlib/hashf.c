/*
** 2003/10/17 - HDS add
** 2009/03/31 - HDS  Murmurhash
**
*/
#include <string.h>
#include "xtypes.h"
#include "hashf.h"

static const int primes[] = {
  13, 19, 29, 41, 59, 79, 107, 149, 197, 263, 347, 457, 599, 787, 1031,
  1361, 1777, 2333, 3037, 3967, 5167, 6719, 8737, 11369, 14783,
  19219, 24989, 32491, 42257, 54941, 71429, 92861, 120721, 156941,
  204047, 265271, 344857, 448321, 582821, 757693, 985003, 1280519,
  1664681, 2164111, 2813353, 3657361, 4754591, 6180989, 8035301,
  10445899, 13579681, 17653589, 22949669, 29834603, 38784989,
  50420551, 65546729, 85210757, 110774011, 144006217, 187208107,
  243370577, 316381771, 411296309, 534685237, 695090819, 903618083,
  1174703521, 1527114613, 1837299131, 2147483647
};
const  int prime_table_length = sizeof(primes)/sizeof(primes[0]);

int prime_size (int size, int *idx)
{
  int i;
  if (size < 0) size = -size;

  for (i = 0; i < prime_table_length; i++) 
    if (primes[i] >= size) break;
  *idx = i;
  return primes[i];
}

int prime_next_size (int *idx)
{
  if (*idx < prime_table_length - 1) (*idx)++;
  return primes[*idx];
}

int prime_prev_size (int *idx)
{
  if (*idx > 0) (*idx)--;
  return primes[*idx];
}

/* 
**  "Murmur" hash provided by Austin, tanjent@gmail.com
**  http://murmurhash.googlepages.com/
*/
ub32 Murmur_hash2 (ub8 *data, int len) 
{
  ub32  h, k;

  h = 0 ^ len;

  while (len >= 4) {
    k  = data[0];
    k |= data[1] << 8;
    k |= data[2] << 16;
    k |= data[3] << 24;

    k *= 0x5bd1e995;
    k ^= k >> 24;
    k *= 0x5bd1e995;

    h *= 0x5bd1e995;
    h ^= k;

    data += 4;
    len -= 4;
  }

  switch (len) {
  case 3:
    h ^= data[2] << 16;
  case 2:
    h ^= data[1] << 8;
  case 1:
    h ^= data[0];
    h *= 0x5bd1e995;
  }
    
  h ^= h >> 13;
  h *= 0x5bd1e995;
  h ^= h >> 15;
    
  return h;
}


/*
 * 32-bit hashes by Bob Jenkins.
 */

ub32 hash_jenkins_32a (ub32 a)
{
  a = (a+0x7ed55d16) + (a<<12);
  a = (a^0xc761c23c) ^ (a>>19);
  a = (a+0x165667b1) + (a<<5);
  a = (a+0xd3a2646c) ^ (a<<9);
  a = (a+0xfd7046c5) + (a<<3);
  a = (a^0xb55a4f09) ^ (a>>16);
  return a;
}

ub32 hash_jenkins_32b (ub32 a)
{
  a -= (a<<6);
  a ^= (a>>17);
  a -= (a<<9);
  a ^= (a<<4);
  a -= (a<<3);
  a ^= (a<<10);
  a ^= (a>>15);
  return a;
}




#if 0
{{{
//-----------------------------------------------------------------------------
// MurmurHash2, 64-bit versions, by Austin Appleby

// The same caveats as 32-bit MurmurHash2 apply here - beware of alignment 
// and endian-ness issues if used across multiple platforms.

typedef unsigned __int64 uint64_t;

// 64-bit hash for 64-bit platforms

uint64_t MurmurHash64A (const void *key, int len, unsigned int seed)
{
  const uint64_t m = 0xc6a4a7935bd1e995;
  const int r = 47;

  uint64_t h = seed ^ (len * m);

  const uint64_t * data = (const uint64_t *)key;
  const uint64_t * end = data + (len/8);

  while(data != end)
  {
    uint64_t k = *data++;

    k *= m; 
    k ^= k >> r; 
    k *= m; 
    
    h ^= k;
    h *= m; 
  }

  const unsigned char * data2 = (const unsigned char*)data;

  switch(len & 7)
  {
  case 7: h ^= uint64_t(data2[6]) << 48;
  case 6: h ^= uint64_t(data2[5]) << 40;
  case 5: h ^= uint64_t(data2[4]) << 32;
  case 4: h ^= uint64_t(data2[3]) << 24;
  case 3: h ^= uint64_t(data2[2]) << 16;
  case 2: h ^= uint64_t(data2[1]) << 8;
  case 1: h ^= uint64_t(data2[0]);
          h *= m;
  };
 
  h ^= h >> r;
  h *= m;
  h ^= h >> r;

  return h;
} 


// 64-bit hash for 32-bit platforms

uint64_t MurmurHash64B (const void *key, int len, unsigned int seed)
{
  const unsigned int m = 0x5bd1e995;
  const int r = 24;

  unsigned int h1 = seed ^ len;
  unsigned int h2 = 0;

  const unsigned int * data = (const unsigned int *)key;

  while (len >= 8)
  {
    unsigned int k1 = *data++;
    k1 *= m; k1 ^= k1 >> r; k1 *= m;
    h1 *= m; h1 ^= k1;
    len -= 4;

    unsigned int k2 = *data++;
    k2 *= m; k2 ^= k2 >> r; k2 *= m;
    h2 *= m; h2 ^= k2;
    len -= 4;
  }

  if(len >= 4)
  {
    unsigned int k1 = *data++;
    k1 *= m; k1 ^= k1 >> r; k1 *= m;
    h1 *= m; h1 ^= k1;
    len -= 4;
  }

  switch(len)
  {
  case 3: h2 ^= ((unsigned char*)data)[2] << 16;
  case 2: h2 ^= ((unsigned char*)data)[1] << 8;
  case 1: h2 ^= ((unsigned char*)data)[0];
      h2 *= m;
  };

  h1 ^= h2 >> 18; h1 *= m;
  h2 ^= h1 >> 22; h2 *= m;
  h1 ^= h2 >> 17; h1 *= m;
  h2 ^= h1 >> 19; h2 *= m;

  uint64_t h = h1;

  h = (h << 32) | h2;

  return h;
} 

/*-----------------------------------------------------------------------------
** MurmurHash2A, by Austin Appleby
**
** This is a variant of MurmurHash2 modified to use the Merkle-Damgard
** construction. Bulk speed should be identical to Murmur2, small-key speed
** will be 10%-20% slower due to the added overhead at the end of the hash.
**
** This variant fixes a minor issue where null keys were more likely to
** collide with each other than expected, and also makes the algorithm
** more amenable to incremental implementations. All other caveats from
** MurmurHash2 still apply.
*/

#define mmix(h,k) { k *= m; k ^= k >> r; k *= m; h *= m; h ^= k; }

unsigned int MurmurHash2A (const void * key, int len, unsigned int seed)
{
  const unsigned int m = 0x5bd1e995;
  const int r = 24;
  unsigned int l = len;

  const unsigned char * data = (const unsigned char *)key;

  unsigned int h = seed;

  while (len >= 4) {
    unsigned int k = *(unsigned int*)data;

    mmix(h,k);

    data += 4;
    len -= 4;
  }

  unsigned int t = 0;

  switch (len) {
  case 3: t ^= data[2] << 16;
  case 2: t ^= data[1] << 8;
  case 1: t ^= data[0];
  };

  mmix(h,t);
  mmix(h,l);

  h ^= h >> 13;
  h *= m;
  h ^= h >> 15;

  return h;
}



//-----------------------------------------------------------------------------
// MurmurHashAligned2, by Austin Appleby

// Same algorithm as MurmurHash2, but only does aligned reads - should be safer
// on certain platforms. 

// Performance will be lower than MurmurHash2

#define MIX(h,k,m) { k *= m; k ^= k >> r; k *= m; h *= m; h ^= k; }

unsigned int MurmurHashAligned2 (const void * key, int len, unsigned int seed)
{
  const unsigned int m = 0x5bd1e995;
  const int r = 24;

  const unsigned char *data = (const unsigned char *)key;

  unsigned int h = seed ^ len;

  int align = (int)data & 3;

  if (align && (len >= 4)) {
    // Pre-load the temp registers

    unsigned int t = 0, d = 0;

    switch (align) {
    case 1: t |= data[2] << 16;
    case 2: t |= data[1] << 8;
    case 3: t |= data[0];
    }

    t <<= (8 * align);

    data += 4-align;
    len -= 4-align;

    int sl = 8 * (4-align);
    int sr = 8 * align;

    // Mix
    while (len >= 4) {
      d = *(unsigned int *)data;
      t = (t >> sr) | (d << sl);

      unsigned int k = t;

      MIX(h,k,m);

      t = d;

      data += 4;
      len -= 4;
    }

    // Handle leftover data in temp registers
    d = 0;
    if (len >= align) {
      switch (align) {
      case 3: d |= data[2] << 16;
      case 2: d |= data[1] << 8;
      case 1: d |= data[0];
      }

      unsigned int k = (t >> sr) | (d << sl);
      MIX(h,k,m);

      data += align;
      len -= align;

      //----------
      // Handle tail bytes
      switch (len) {
      case 3: h ^= data[2] << 16;
      case 2: h ^= data[1] << 8;
      case 1: h ^= data[0];
          h *= m;
      };
    }
    else {
      switch (len) {
      case 3: d |= data[2] << 16;
      case 2: d |= data[1] << 8;
      case 1: d |= data[0];
      case 0: h ^= (t >> sr) | (d << sl);
          h *= m;
      }
    }

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
  }
  else {
    while (len >= 4) {
      unsigned int k = *(unsigned int *)data;

      MIX(h,k,m);

      data += 4;
      len -= 4;
    }

    //----------
    // Handle tail bytes
    switch (len) {
    case 3: h ^= data[2] << 16;
    case 2: h ^= data[1] << 8;
    case 1: h ^= data[0];
        h *= m;
    }

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
  }
}
//-----------------------------------------------------------------------------
// MurmurHashNeutral2, by Austin Appleby

// Same as MurmurHash2, but endian- and alignment-neutral.
// Half the speed though, alas.

unsigned int MurmurHashNeutral2 ( const void * key, int len, unsigned int seed )
{
  const unsigned int m = 0x5bd1e995;
  const int r = 24;

  unsigned int h = seed ^ len;

  const unsigned char * data = (const unsigned char *)key;

  while (len >= 4) {
    unsigned int k;

    k  = data[0];
    k |= data[1] << 8;
    k |= data[2] << 16;
    k |= data[3] << 24;

    k *= m; 
    k ^= k >> r; 
    k *= m;

    h *= m;
    h ^= k;

    data += 4;
    len -= 4;
  }
  
  switch (len) {
  case 3: h ^= data[2] << 16;
  case 2: h ^= data[1] << 8;
  case 1: h ^= data[0];
          h *= m;
  }

  h ^= h >> 13;
  h *= m;
  h ^= h >> 15;

  return h;
} 


/*
 * By Bart Massey, based on Knuth LCG.
 * Do an extra multiply to get the middle 32 bits
 * of the 64 bit product.
 */
unsigned int barthash (int k)
{
  /* 0x9e375365UL == 40499 * 65543 - both are prime;
     the result is ~0.68*(2^32) --Chuck Lever */

  return (0x9e37 * (k & 0xffff) + 0x5365 * (k >> 16));
}


/*
 * DJBX33A (Daniel J. Bernstein, Times 33 with Addition)
 *
 * This is Daniel J. Bernstein's popular `times 33' hash function as
 * posted by him years ago on comp.lang.c. It basically uses a function
 * like ``hash(i) = hash(i-1) * 33 + string[i]''. This is one of the
 * best hashing functions for strings. Because it is both computed very
 * fast and distributes very well.
 *
 * The magic of the number 33, i.e. why it works better than many other
 * constants, prime or not, has never been adequately explained by
 * anyone. So I try an own RSE-explanation: if one experimentally tests
 * all multipliers between 1 and 256 (as I did it) one detects that
 * even numbers are not useable at all. The remaining 128 odd numbers
 * (except for the number 1) work more or less all equally well. They
 * all distribute in an acceptable way and this way fill a hash table
 * with an average percent of approx. 86%. 
 *
 * If one compares the Chi/2 values resulting of the various
 * multipliers, the 33 not even has the best value. But the 33 and a
 * few other equally good values like 17, 31, 63, 127 and 129 have
 * nevertheless a great advantage over the remaining values in the large
 * set of possible multipliers: their multiply operation can be replaced
 * by a faster operation based on just one bit-wise shift plus either a
 * single addition or subtraction operation. And because a hash function
 * has to both distribute good and has to be very fast to compute, those
 * few values should be preferred and seems to be also the reason why
 * Daniel J. Bernstein also preferred it.
 */
unsigned int hash_djbx33a (const  *key, sb32 len)
{
  const ub8 *k = key;
  ub32 hash = 5381;

  /* the hash unrolled eight times */
  for (; len >= 8; len -= 8) {
    hash = ((hash << 5) + hash) + *k++;
    hash = ((hash << 5) + hash) + *k++;
    hash = ((hash << 5) + hash) + *k++;
    hash = ((hash << 5) + hash) + *k++;
    hash = ((hash << 5) + hash) + *k++;
    hash = ((hash << 5) + hash) + *k++;
    hash = ((hash << 5) + hash) + *k++;
    hash = ((hash << 5) + hash) + *k++;
  }
  switch (len) {
    case 7: hash = ((hash << 5) + hash) + *k++; /* fallthrough... */
    case 6: hash = ((hash << 5) + hash) + *k++; /* fallthrough... */
    case 5: hash = ((hash << 5) + hash) + *k++; /* fallthrough... */
    case 4: hash = ((hash << 5) + hash) + *k++; /* fallthrough... */
    case 3: hash = ((hash << 5) + hash) + *k++; /* fallthrough... */
    case 2: hash = ((hash << 5) + hash) + *k++; /* fallthrough... */
    case 1: hash = ((hash << 5) + hash) + *k++; break;
    default: /* case 0: */ break;
  }
  return hash;
}



/*
--------------------------------------------------------------------
mix -- mix 3 32-bit values reversibly.
For every delta with one or two bit set, and the deltas of all three
  high bits or all three low bits, whether the original value of a,b,c
  is almost all zero or is uniformly distributed,
* If mix() is run forward or backward, at least 32 bits in a,b,c
  have at least 1/4 probability of changing.
* If mix() is run forward, every bit of c will change between 1/3 and
  2/3 of the time.  (Well, 22/100 and 78/100 for some 2-bit deltas.)
mix() was built out of 36 single-cycle latency instructions in a 
  structure that could supported 2x parallelism, like so:
      a -= b; 
      a -= c; x = (c>>13);
      b -= c; a ^= x;
      b -= a; x = (a<<8);
      c -= a; b ^= x;
      c -= b; x = (b>>13);
      ...
  Unfortunately, superscalar Pentiums and Sparcs can't take advantage 
  of that parallelism.  They've also turned some of those single-cycle
  latency instructions into multi-cycle latency instructions.  Still,
  this is the fastest good hash I could find.  There were about 2^^68
  to choose from.  I only looked at a billion or so.
--------------------------------------------------------------------
*/
#define mix(a,b,c) { \
    a -= b; a -= c; a ^= (c>>13); \
    b -= c; b -= a; b ^= (a<< 8); \
    c -= a; c -= b; c ^= (b>>13); \
    a -= b; a -= c; a ^= (c>>12); \
    b -= c; b -= a; b ^= (a<<16); \
    c -= a; c -= b; c ^= (b>> 5); \
    a -= b; a -= c; a ^= (c>> 3); \
    b -= c; b -= a; b ^= (a<<10); \
    c -= a; c -= b; c ^= (b>>15); \
  }

/*
 * BJDDJ (Bob Jenkins, Dr. Dobbs Journal)
 *
 * This is a very complex but also very good hashing function, as
 * proposed in the March'97 issue of Dr. Dobbs Journal (DDJ) by Bob
 * Jenkins (see http://burtleburtle.net/bob/hash/doobs.html for online
 * version). He showed in his texts, that his hash function has both
 * very good distribution and performance and my own hash function
 * comparison confirmed this, too. The only difference to the original
 * function of B.J. here is that my version doesn't provide the `level'
 * (= previous hash) argument for consistency reasons with the other
 * hash functions (i.e. same function signature). It can be definitely
 * recommended as a very good general purpose hashing function.
 */
ub32 hash_bjddj (const ub8 *key, sb32  length)
{
  ub32 c = length;
  const ub8 *k = key;
  ub32 a,b,len;

  /* setup the internal state */
  len = length;
  a = b = 0x9e3779b9;  /* the golden ratio; an arbitrary value */

  /* handle most of the key */
  while (len >= 12) {
    a += (k[0] +((ub32)k[1]<<8) +((ub32)k[ 2]<<16) +((ub32)k[ 3]<<24));
    b += (k[4] +((ub32)k[5]<<8) +((ub32)k[ 6]<<16) +((ub32)k[ 7]<<24));
    c += (k[8] +((ub32)k[9]<<8) +((ub32)k[10]<<16) +((ub32)k[11]<<24));
    mix(a,b,c);
    k += 12; len -= 12;
  }

  /* handle the last 11 bytes */
  c += length;
  switch (len) { 
    /* all the case statements fall through */
    case 11: c += ((ub32)k[10]<<24);
    case 10: c += ((ub32)k[ 9]<<16);
    case 9 : c += ((ub32)k[ 8]<< 8);
    /* the first byte of c is reserved for the length */
    case 8 : b += ((ub32)k[ 7]<<24);
    case 7 : b += ((ub32)k[ 6]<<16);
    case 6 : b += ((ub32)k[ 5]<< 8);
    case 5 : b += k[4];
    case 4 : a += ((ub32)k[ 3]<<24);
    case 3 : a += ((ub32)k[ 2]<<16);
    case 2 : a += ((ub32)k[ 1]<< 8);
    case 1 : a += k[0];
    /* case 0: nothing left to add */
  }
  mix(a,b,c);

  /* report the result */
  return c;
}

/*
--------------------------------------------------------------------
 This is identical to hash2() on little-endian machines (like Intel 
 x86s or VAXen).  It gives nondeterministic results on big-endian
 machines.  It is faster than hash2(), but a little slower than 
 hash22(), and it requires
 -- that all your machines be little-endian
--------------------------------------------------------------------
*/
ub32 hash_func21 (const ub8 *key, sb32  length)
{
  ub32 c = length;
  const ub8 *k = key;
  ub32 a,b,len;

  /* setup the internal state */
  len = length;
  a = b = 0x9e3779b9;  /* the golden ratio; an arbitrary value */

   /*---------------------------------------- handle most of the key */
   if (((ub32)k)&3) {
      while (len >= 12)    /* unaligned */
      {
         a += (k[0] +((ub32)k[1]<<8) +((ub32)k[2]<<16) +((ub32)k[3]<<24));
         b += (k[4] +((ub32)k[5]<<8) +((ub32)k[6]<<16) +((ub32)k[7]<<24));
         c += (k[8] +((ub32)k[9]<<8) +((ub32)k[10]<<16)+((ub32)k[11]<<24));
         mix(a,b,c);
         k += 12; len -= 12;
      }
   }
   else {
      while (len >= 12)    /* aligned */
      {
         a += *(ub32 *)(k+0);
         b += *(ub32 *)(k+4);
         c += *(ub32 *)(k+8);
         mix(a,b,c);
         k += 12; len -= 12;
      }
   }

  /* handle the last 11 bytes */
  c += length;
  switch(len) {
    /* all the case statements fall through */
    case 11: c += ((ub32)k[10]<<24);
    case 10: c += ((ub32)k[ 9]<<16);
    case 9 : c += ((ub32)k[ 8]<< 8);
    /* the first byte of c is reserved for the length */
    case 8 : b += ((ub32)k[ 7]<<24);
    case 7 : b += ((ub32)k[ 6]<<16);
    case 6 : b += ((ub32)k[ 5]<< 8);
    case 5 : b += k[4];
    case 4 : a += ((ub32)k[ 3]<<24);
    case 3 : a += ((ub32)k[ 2]<<16);
    case 2 : a += ((ub32)k[ 1]<< 8);
    case 1 : a += k[0];
    /* case 0: nothing left to add */
  }
  mix(a,b,c);

  /* report the result */
  return c;
}

/*
--------------------------------------------------------------------
 This works on all machines.  hash2() is identical to hash() on 
 little-endian machines, except that the length has to be measured
 in ub4s instead of bytes.  It is much faster than hash().  It 
 requires
 -- that the key be an array of ub4's, and
 -- that all your machines have the same endianness, and
 -- that the length be the number of ub4's in the key
--------------------------------------------------------------------
*/
ub32 hash_func22 (const ub32 *k, sb32  length)
{
  register ub32 c = length;
  register ub32 a,b,len;

   /* Set up the internal state */
   len = length;
   a = b = 0x9e3779b9;  /* the golden ratio; an arbitrary value */

   /*---------------------------------------- handle most of the key */
   while (len >= 3) {
      a += k[0];
      b += k[1];
      c += k[2];
      mix(a,b,c);
      k += 3; len -= 3;
   }

   /*-------------------------------------- handle the last 2 ub4's */
   c += length;
   switch(len)              /* all the case statements fall through */
   {
     /* c is reserved for the length */
   case 2 : b+=k[1];
   case 1 : a+=k[0];
     /* case 0: nothing left to add */
   }
   mix(a,b,c);
   /*-------------------------------------------- report the result */
   return c;
}


/*
 * MACRC32 (Mark Adler, Cyclic Redundancy Check 32-Bit)
 *
 * This hash function is based on the good old CRC-32 (Cyclic Redundancy
 * Check with 32 Bit) algorithm as invented by Mark Adler. It is one
 * of the hash functions with medium performance but with very good
 * distribution. So it can be considered as a rock solid general purpose
 * hash function. It should be used if good distribution is more
 * important than high performance.
 */
ub32
hash_macrc32 (const ub8 *key, sb32 len)
{
  /* the CRC-32 table */
  static unsigned long tab[256] = {
    0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL, 0x076dc419L,
    0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0x0edb8832L, 0x79dcb8a4L,
    0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L,
    0x90bf1d91L, 0x1db71064L, 0x6ab020f2L, 0xf3b97148L, 0x84be41deL,
    0x1adad47dL, 0x6ddde4ebL, 0xf4d4b551L, 0x83d385c7L, 0x136c9856L,
    0x646ba8c0L, 0xfd62f97aL, 0x8a65c9ecL, 0x14015c4fL, 0x63066cd9L,
    0xfa0f3d63L, 0x8d080df5L, 0x3b6e20c8L, 0x4c69105eL, 0xd56041e4L,
    0xa2677172L, 0x3c03e4d1L, 0x4b04d447L, 0xd20d85fdL, 0xa50ab56bL,
    0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L, 0xacbcf940L, 0x32d86ce3L,
    0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L, 0x26d930acL, 0x51de003aL,
    0xc8d75180L, 0xbfd06116L, 0x21b4f4b5L, 0x56b3c423L, 0xcfba9599L,
    0xb8bda50fL, 0x2802b89eL, 0x5f058808L, 0xc60cd9b2L, 0xb10be924L,
    0x2f6f7c87L, 0x58684c11L, 0xc1611dabL, 0xb6662d3dL, 0x76dc4190L,
    0x01db7106L, 0x98d220bcL, 0xefd5102aL, 0x71b18589L, 0x06b6b51fL,
    0x9fbfe4a5L, 0xe8b8d433L, 0x7807c9a2L, 0x0f00f934L, 0x9609a88eL,
    0xe10e9818L, 0x7f6a0dbbL, 0x086d3d2dL, 0x91646c97L, 0xe6635c01L,
    0x6b6b51f4L, 0x1c6c6162L, 0x856530d8L, 0xf262004eL, 0x6c0695edL,
    0x1b01a57bL, 0x8208f4c1L, 0xf50fc457L, 0x65b0d9c6L, 0x12b7e950L,
    0x8bbeb8eaL, 0xfcb9887cL, 0x62dd1ddfL, 0x15da2d49L, 0x8cd37cf3L,
    0xfbd44c65L, 0x4db26158L, 0x3ab551ceL, 0xa3bc0074L, 0xd4bb30e2L,
    0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL, 0xd3d6f4fbL, 0x4369e96aL,
    0x346ed9fcL, 0xad678846L, 0xda60b8d0L, 0x44042d73L, 0x33031de5L,
    0xaa0a4c5fL, 0xdd0d7cc9L, 0x5005713cL, 0x270241aaL, 0xbe0b1010L,
    0xc90c2086L, 0x5768b525L, 0x206f85b3L, 0xb966d409L, 0xce61e49fL,
    0x5edef90eL, 0x29d9c998L, 0xb0d09822L, 0xc7d7a8b4L, 0x59b33d17L,
    0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL, 0xedb88320L, 0x9abfb3b6L,
    0x03b6e20cL, 0x74b1d29aL, 0xead54739L, 0x9dd277afL, 0x04db2615L,
    0x73dc1683L, 0xe3630b12L, 0x94643b84L, 0x0d6d6a3eL, 0x7a6a5aa8L,
    0xe40ecf0bL, 0x9309ff9dL, 0x0a00ae27L, 0x7d079eb1L, 0xf00f9344L,
    0x8708a3d2L, 0x1e01f268L, 0x6906c2feL, 0xf762575dL, 0x806567cbL,
    0x196c3671L, 0x6e6b06e7L, 0xfed41b76L, 0x89d32be0L, 0x10da7a5aL,
    0x67dd4accL, 0xf9b9df6fL, 0x8ebeeff9L, 0x17b7be43L, 0x60b08ed5L,
    0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L, 0x4fdff252L, 0xd1bb67f1L,
    0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL, 0xd80d2bdaL, 0xaf0a1b4cL,
    0x36034af6L, 0x41047a60L, 0xdf60efc3L, 0xa867df55L, 0x316e8eefL,
    0x4669be79L, 0xcb61b38cL, 0xbc66831aL, 0x256fd2a0L, 0x5268e236L,
    0xcc0c7795L, 0xbb0b4703L, 0x220216b9L, 0x5505262fL, 0xc5ba3bbeL,
    0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L, 0xc2d7ffa7L, 0xb5d0cf31L,
    0x2cd99e8bL, 0x5bdeae1dL, 0x9b64c2b0L, 0xec63f226L, 0x756aa39cL,
    0x026d930aL, 0x9c0906a9L, 0xeb0e363fL, 0x72076785L, 0x05005713L,
    0x95bf4a82L, 0xe2b87a14L, 0x7bb12baeL, 0x0cb61b38L, 0x92d28e9bL,
    0xe5d5be0dL, 0x7cdcefb7L, 0x0bdbdf21L, 0x86d3d2d4L, 0xf1d4e242L,
    0x68ddb3f8L, 0x1fda836eL, 0x81be16cdL, 0xf6b9265bL, 0x6fb077e1L,
    0x18b74777L, 0x88085ae6L, 0xff0f6a70L, 0x66063bcaL, 0x11010b5cL,
    0x8f659effL, 0xf862ae69L, 0x616bffd3L, 0x166ccf45L, 0xa00ae278L,
    0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L, 0xa7672661L, 0xd06016f7L,
    0x4969474dL, 0x3e6e77dbL, 0xaed16a4aL, 0xd9d65adcL, 0x40df0b66L,
    0x37d83bf0L, 0xa9bcae53L, 0xdebb9ec5L, 0x47b2cf7fL, 0x30b5ffe9L,
    0xbdbdf21cL, 0xcabac28aL, 0x53b39330L, 0x24b4a3a6L, 0xbad03605L,
    0xcdd70693L, 0x54de5729L, 0x23d967bfL, 0xb3667a2eL, 0xc4614ab8L,
    0x5d681b02L, 0x2a6f2b94L, 0xb40bbe37L, 0xc30c8ea1L, 0x5a05df1bL,
    0x2d02ef8dL
  };
  const ub8 *k = key;
  ub32 hash;
    
  /* compute hash with the help of the table */
  hash = 0xffffffff;
  while (len-- > 0)
    hash = tab[(hash ^ *k++) & 0xff] ^ (hash >> 8);
  hash ^= 0xffffffff;

  /* return the calculated hash value */
  return hash;
}

/* CRC16 implementation acording to CCITT standards */
static const unsigned short crc16tab[256]= {
  0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,
  0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef,
  0x1231,0x0210,0x3273,0x2252,0x52b5,0x4294,0x72f7,0x62d6,
  0x9339,0x8318,0xb37b,0xa35a,0xd3bd,0xc39c,0xf3ff,0xe3de,
  0x2462,0x3443,0x0420,0x1401,0x64e6,0x74c7,0x44a4,0x5485,
  0xa56a,0xb54b,0x8528,0x9509,0xe5ee,0xf5cf,0xc5ac,0xd58d,
  0x3653,0x2672,0x1611,0x0630,0x76d7,0x66f6,0x5695,0x46b4,
  0xb75b,0xa77a,0x9719,0x8738,0xf7df,0xe7fe,0xd79d,0xc7bc,
  0x48c4,0x58e5,0x6886,0x78a7,0x0840,0x1861,0x2802,0x3823,
  0xc9cc,0xd9ed,0xe98e,0xf9af,0x8948,0x9969,0xa90a,0xb92b,
  0x5af5,0x4ad4,0x7ab7,0x6a96,0x1a71,0x0a50,0x3a33,0x2a12,
  0xdbfd,0xcbdc,0xfbbf,0xeb9e,0x9b79,0x8b58,0xbb3b,0xab1a,
  0x6ca6,0x7c87,0x4ce4,0x5cc5,0x2c22,0x3c03,0x0c60,0x1c41,
  0xedae,0xfd8f,0xcdec,0xddcd,0xad2a,0xbd0b,0x8d68,0x9d49,
  0x7e97,0x6eb6,0x5ed5,0x4ef4,0x3e13,0x2e32,0x1e51,0x0e70,
  0xff9f,0xefbe,0xdfdd,0xcffc,0xbf1b,0xaf3a,0x9f59,0x8f78,
  0x9188,0x81a9,0xb1ca,0xa1eb,0xd10c,0xc12d,0xf14e,0xe16f,
  0x1080,0x00a1,0x30c2,0x20e3,0x5004,0x4025,0x7046,0x6067,
  0x83b9,0x9398,0xa3fb,0xb3da,0xc33d,0xd31c,0xe37f,0xf35e,
  0x02b1,0x1290,0x22f3,0x32d2,0x4235,0x5214,0x6277,0x7256,
  0xb5ea,0xa5cb,0x95a8,0x8589,0xf56e,0xe54f,0xd52c,0xc50d,
  0x34e2,0x24c3,0x14a0,0x0481,0x7466,0x6447,0x5424,0x4405,
  0xa7db,0xb7fa,0x8799,0x97b8,0xe75f,0xf77e,0xc71d,0xd73c,
  0x26d3,0x36f2,0x0691,0x16b0,0x6657,0x7676,0x4615,0x5634,
  0xd94c,0xc96d,0xf90e,0xe92f,0x99c8,0x89e9,0xb98a,0xa9ab,
  0x5844,0x4865,0x7806,0x6827,0x18c0,0x08e1,0x3882,0x28a3,
  0xcb7d,0xdb5c,0xeb3f,0xfb1e,0x8bf9,0x9bd8,0xabbb,0xbb9a,
  0x4a75,0x5a54,0x6a37,0x7a16,0x0af1,0x1ad0,0x2ab3,0x3a92,
  0xfd2e,0xed0f,0xdd6c,0xcd4d,0xbdaa,0xad8b,0x9de8,0x8dc9,
  0x7c26,0x6c07,0x5c64,0x4c45,0x3ca2,0x2c83,0x1ce0,0x0cc1,
  0xef1f,0xff3e,0xcf5d,0xdf7c,0xaf9b,0xbfba,0x8fd9,0x9ff8,
  0x6e17,0x7e36,0x4e55,0x5e74,0x2e93,0x3eb2,0x0ed1,0x1ef0
};
  
unsigned short crc16_ccitt (const void *buf, int len)
{
  register int counter;
  register unsigned short crc = 0;
  for (counter = 0; counter < len; counter++)
    crc = (crc<<8) ^ crc16tab[((crc>>8) ^ *(char *)buf++)&0x00FF];
  return crc;
}

/*
 *  Ozan Yigit's original sdbm hash.
 *
 * Ugly, but fast.  Break the string up into 8 byte units.  On the first time
 * through the loop get the "leftover bytes" (strlen % 8).  On every other
 * iteration, perform 8 HASHC's so we handle all 8 bytes.  Essentially, this
 * saves us 7 cmp & branch instructions.
 *
 */
ub32
hash_Yigit (const ub8 *key, sb32 len)
{
  const ub8 *k;
  ub32 n, loop;

  if (len == 0)
    return (0);

#define  HASHC  n = *k++ + 65599 * n
  n = 0;
  k = key;

  loop = (len + 8 - 1) >> 3;
  switch (len & (8 - 1)) {
  case 0:
    do {
      HASHC;
  case 7:
      HASHC;
  case 6:
      HASHC;
  case 5:
      HASHC;
  case 4:
      HASHC;
  case 3:
      HASHC;
  case 2:
      HASHC;
  case 1:
      HASHC;
    } while (--loop);
  }
  return (n);
}

/*
 *  Chris Torek's hash function.  Although this function performs only
 *  slightly worse than hash_func4 on strings, it performs horribly on
 *  numbers.
 *
 */
ub32
hash_Torek (const ub8 *key, sb32 len)
{
  const ub8 *k;
  ub32 h, loop;

  if (len == 0)
    return (0);

#define  HASH4a  h = (h << 5) - h + *k++;
#define  HASH4b  h = (h << 5) + h + *k++;
#define  HASH4  HASH4b
  h = 0;
  k = key;

  loop = (len + 8 - 1) >> 3;
  switch (len & (8 - 1)) {
  case 0:
    do {
      HASH4;
  case 7:
      HASH4;
  case 6:
      HASH4;
  case 5:
      HASH4;
  case 4:
      HASH4;
  case 3:
      HASH4;
  case 2:
      HASH4;
  case 1:
      HASH4;
    } while (--loop);
  }
  return (h);
}

/*
 * Fowler/Noll/Vo hash
 *
 * The basis of this hash algorithm was taken from an idea sent
 * as reviewer comments to the IEEE POSIX P1003.2 committee by:
 *
 *      Phong Vo (http://www.research.att.com/info/kpv/)
 *      Glenn Fowler (http://www.research.att.com/~gsf/)
 *
 * In a subsequent ballot round:
 *
 *      Landon Curt Noll (http://www.isthe.com/chongo/)
 *
 * improved on their algorithm.  Some people tried this hash
 * and found that it worked rather well.  In an EMail message
 * to Landon, they named it the ``Fowler/Noll/Vo'' or FNV hash.
 *
 * FNV hashes are designed to be fast while maintaining a low
 * collision rate. The FNV speed allows one to quickly hash lots
 * of data while maintaining a reasonable collision rate.  See:
 *
 *      http://www.isthe.com/chongo/tech/comp/fnv/index.html
 *
 * for more details as well as other forms of the FNV hash.
 *
 */
ub32
hash_FNV (const ub8 *key, sb32 len)
{
  unsigned char *bp = (unsigned char *)key;/* start of buffer */
  unsigned char *be = bp + len;            /* beyond end of buffer */
  ub32 hval = len;                         /* 0x811c9dc5 */

  /*
   * FNV-1a hash each octet in the buffer
   */
  while (bp < be) {

    /* xor the bottom with the current octet */
    hval ^= (ub32)*bp++;

    /* multiply by the 32 bit FNV magic prime mod 2^32 */
    hval += (hval<<1) + (hval<<4) + (hval<<7) + (hval<<8) + (hval<<24);
  }

  /* return our new hash value */
  return hval;
}



/*
 *  Phong Vo's linear congruential hash.
 *
 */
#define  DCHARHASH(h, c)  ((h) = 0x63c63cd9*(h) + 0x9c39c33d + (c))

ub32
hash_Phong (const ub8 *key, sb32 len)
{
  const ub8 *e, *k;
  ub32 h;
  ub8 c;

  k = key;
  e = k + len;
  for (h = 0; k != e;) {
    c = *k++;
    if (!c && k > e)
      break;
    DCHARHASH(h, c);
  }
  return (h);
}



/* One-at-a-time hash (found in a web article from ddj), this is the
 * standard hash function.
 *
 * See http://burtleburtle.net/bob/hash/doobs.html
 * for the hash functions used here.
 */
ub32 hash_OAAT (const ub8 *key, sb32 len)
{
  ub32 h = 0;
  const ub8 *k = (ub8 *)key;
  int i;

  for (i = 0; i < len; ++i) {
    h += k[i];
    h += (h << 10);
    h ^= (h >> 6);
  }
  h += (h << 3);
  h ^= (h >> 11);
  h += (h << 15);

  return h;
}

ub32 hash_ASU (const ub8 *key, sb32 len)
{
  int cnt;
  ub32 hval, g;

  /* Compute the hash value for the given string.  The algorithm
     is taken from [Aho,Sethi,Ullman].  */
  cnt = 0;
  hval = len;
  while (cnt < len) {
    hval <<= 4;
    hval += (ub32) *(((char *) key) + cnt++);
    g = hval & ((ub32)0xf << (32 - 4));
    if (g != 0)
    {
      hval ^= g >> (32 - 8);
      hval ^= g;
    }
  }
  return hval != 0 ? hval : ~((ub32) 0);
}



/*
 * Some useful hash function.
 * It's not a particularly good hash function (<< 5 would be better than << 4),
 * but people believe in it because it comes from Dragon book.
*/
ub32 hash_pjw (const ub8 *x, sb32 len) 
{
  unsigned int h = 0;
  unsigned int g;

  for (; len > 0; len--) {
    h = (h << 4) + *x++;
    if ((g = h & 0xf0000000) != 0)
      h = (h ^ (g >> 24)) ^ g;
  }
  return h;
}

/* is a t_hash_code_proc.
   This algorithm is taken from dragon book, p.436.
   Returns a hash code */
ub32 hash_code_dragon (const ub8 *buf, sb32 len)
{
  ub32 hash_code;
  ub32 carry;

  hash_code = 0;
  for ( ; len > 0; buf++, len--) 
  {
    hash_code = (hash_code << 4) + (*buf);
    if ((carry = (hash_code & 0xf0000000))) 
    {
      hash_code ^= (carry >> 24);
      hash_code ^= carry;
    }
  }
  return (hash_code);
}

ub32 hash_gdbm (const ub8 *x, sb32 len)
{
  unsigned int value;  /* Used to compute the hash value.  */
  int   index;    /* Used to cycle through random values. */


  /* Set the initial value from key. */
  value = 0x238F13AF * len;
  for (index = 0; index < len; index++)
    value = (value + (x[index] << (index*5 % 24))) & 0x7FFFFFFF;

  value = (1103515243 * value + 12345) & 0x7FFFFFFF;  

  /* Return the value. */
  return(value);
}


ub32 hash_awk (const ub8 *s, sb32 len)
{
  unsigned long h = 0;

  /*
   * This is INCREDIBLY ugly, but fast.  We break the string up into
   * 8 byte units.  On the first time through the loop we get the
   * "leftover bytes" (strlen % 8).  On every other iteration, we
   * perform 8 HASHC's so we handle all 8 bytes.  Essentially, this
   * saves us 7 cmp & branch instructions.  If this routine is
   * heavily used enough, it's worth the ugly coding.
   *
   * OZ's original sdbm hash, copied from Margo Seltzers db package.
   */

  /*
   * Even more speed:
   * #define HASHC   h = *s++ + 65599 * h
   * Because 65599 = pow(2, 6) + pow(2, 16) - 1 we multiply by shifts
   */
#define HASHAWK   htmp = (h << 6);  \
  h = *s++ + htmp + (htmp << 10) - h

  unsigned long htmp;

  h = 0;
  if (len > 0) {
    register size_t loop = (len + 8 - 1) >> 3;

    switch (len & (8 - 1)) {
      case 0:
        do {    /* All fall throughs */
              HASHAWK;
      case 7: HASHAWK;
      case 6: HASHAWK;
      case 5: HASHAWK;
      case 4: HASHAWK;
      case 3: HASHAWK;
      case 2: HASHAWK;
      case 1: HASHAWK;
        } while (--loop);
    }
  }
  return h;
}

ub32 hash_gst (const ub8 *str, sb32 len)
{
  ub32 hashVal = 1497032417;    /* arbitrary value */
  sb32 y;

  while (len--) {
    hashVal += *str++;
    hashVal += (hashVal << 10);
    hashVal ^= (hashVal >> 6);
  }

  y = ~hashVal;

  hashVal += (y << 10) | (y >> 22);
  hashVal += (hashVal << 6)  | (hashVal >> 26);
  hashVal -= (hashVal << 16) | (hashVal >> 16);

  return hashVal;
}

/* string hash function by Peter Weinberger */
int
gfarm_hash_default (const void *key, int keylen)
{
  int i;
  unsigned int hash = 0, g;

  for (i = 0; i < keylen; i++) {
    hash = (hash << 4) + ((unsigned char *)key)[i];
    /* this assumes size of `int' is 32 bit */
    if ((g = hash & 0xf0000000) != 0) {
      hash ^= g >> 24;
      hash ^= g;
    }
  }
  return (hash);
}

int
gfarm_hash_casefold(const void *key, int keylen)
{
  int i;
  unsigned int hash = 0, g;

  for (i = 0; i < keylen; i++) {
    hash = (hash << 4) + tolower(((unsigned char *)key)[i]);
    /* this assumes size of `int' is 32 bit */
    if ((g = hash & 0xf0000000) != 0) {
      hash ^= g >> 24;
      hash ^= g;
    }
  }
  return (hash);
}


/*
**--------------------------------------------------------------------
** checksum() -- hash a variable-length key into a 256-bit value
**   k     : the key (the unaligned variable-length array of bytes)
**   len   : the length of the key, counting by bytes
**   state : an array of CHECKSTATE 4-byte values (256 bits)
** The state is the checksum.  Every bit of the key affects every bit of
** the state.  There are no funnels.  About 112+6.875len instructions.
** 
** If you are hashing n strings (ub1 **)k, do it like this:
**   for (i=0; i<8; ++i) state[i] = 0x9e3779b9;
**   for (i=0, h=0; i<n; ++i) checksum( k[i], len[i], state);
** 
** (c) Bob Jenkins, 1996.  bob_jenkins@burtleburtle.net.  You may use this
** code any way you wish, private, educational, or commercial, as long
** as this whole comment accompanies it.
** 
** See http://burtleburtle.net/bob/hash/evahash.html
** Use to detect changes between revisions of documents, assuming nobody
** is trying to cause collisions.  Do NOT use for cryptography.
** --------------------------------------------------------------------
*/
/*
 *--------------------------------------------------------------------
 * mixc -- mixc 8 4-bit values as quickly and thoroughly as possible.
 * Repeating mix() three times achieves avalanche.
 * Repeating mix() four times eliminates all funnels and all
 *  characteristics stronger than 2^{-11}.
 *--------------------------------------------------------------------
*/
#define mixc(a,b,c,d,e,f,g,h) \
{ \
   a^=b<<11; d+=a; b+=c; \
   b^=c>>2;  e+=b; c+=d; \
   c^=d<<8;  f+=c; d+=e; \
   d^=e>>16; g+=d; e+=f; \
   e^=f<<10; h+=e; f+=g; \
   f^=g>>4;  a+=f; g+=h; \
   g^=h<<8;  b+=g; h+=a; \
   h^=a>>9;  c+=h; a+=b; \
}

void checksum (register ub8 *k, register ub32 len, register ub32 *state)
{
  register ub32 a,b,c,d,e,f,g,h,length;

  /* Use the length and level; add in the golden ratio. */
  length = len;
  a = state[0]; b = state[1]; c = state[2]; d = state[3];
  e = state[4]; f = state[5]; g = state[6]; h = state[7];

  /*---------------------------------------- handle most of the key */
  while (len >= 32) {
    a += (k[0] +(k[1]<<8) +(k[2]<<16) +(k[3]<<24));
    b += (k[4] +(k[5]<<8) +(k[6]<<16) +(k[7]<<24));
    c += (k[8] +(k[9]<<8) +(k[10]<<16)+(k[11]<<24));
    d += (k[12]+(k[13]<<8)+(k[14]<<16)+(k[15]<<24));
    e += (k[16]+(k[17]<<8)+(k[18]<<16)+(k[19]<<24));
    f += (k[20]+(k[21]<<8)+(k[22]<<16)+(k[23]<<24));
    g += (k[24]+(k[25]<<8)+(k[26]<<16)+(k[27]<<24));
    h += (k[28]+(k[29]<<8)+(k[30]<<16)+(k[31]<<24));
    mixc(a,b,c,d,e,f,g,h);
    mixc(a,b,c,d,e,f,g,h);
    mixc(a,b,c,d,e,f,g,h);
    mixc(a,b,c,d,e,f,g,h);
    k += 32; len -= 32;
  }

  /*------------------------------------- handle the last 31 bytes */
  h += length;
  switch (len) {
    case 31: h+=(k[30]<<24);
    case 30: h+=(k[29]<<16);
    case 29: h+=(k[28]<<8);
    case 28: g+=(k[27]<<24);
    case 27: g+=(k[26]<<16);
    case 26: g+=(k[25]<<8);
    case 25: g+=k[24];
    case 24: f+=(k[23]<<24);
    case 23: f+=(k[22]<<16);
    case 22: f+=(k[21]<<8);
    case 21: f+=k[20];
    case 20: e+=(k[19]<<24);
    case 19: e+=(k[18]<<16);
    case 18: e+=(k[17]<<8);
    case 17: e+=k[16];
    case 16: d+=(k[15]<<24);
    case 15: d+=(k[14]<<16);
    case 14: d+=(k[13]<<8);
    case 13: d+=k[12];
    case 12: c+=(k[11]<<24);
    case 11: c+=(k[10]<<16);
    case 10: c+=(k[9]<<8);
    case 9 : c+=k[8];
    case 8 : b+=(k[7]<<24);
    case 7 : b+=(k[6]<<16);
    case 6 : b+=(k[5]<<8);
    case 5 : b+=k[4];
    case 4 : a+=(k[3]<<24);
    case 3 : a+=(k[2]<<16);
    case 2 : a+=(k[1]<<8);
    case 1 : a+=k[0];
  }
  mixc(a,b,c,d,e,f,g,h);
  mixc(a,b,c,d,e,f,g,h);
  mixc(a,b,c,d,e,f,g,h);
  mixc(a,b,c,d,e,f,g,h);

  /*-------------------------------------------- report the result */
  state[0] = a; state[1] = b; state[2] = c; state[3] = d;
  state[4] = e; state[5] = f; state[6] = g; state[7] = h;
}

unsigned int chash_hash (unsigned int a)
{
  /* This function is one of Bob Jenkins' full avalanche hashing
   * functions, which when provides quite a good distribution for little
   * input variations. The result is quite suited to fit over a 32-bit
   * space with enough variations so that a randomly picked number falls
   * equally before any server position.
   * Check http://burtleburtle.net/bob/hash/integer.html for more info.
   */
  a = (a+0x7ed55d16) + (a<<12);
  a = (a^0xc761c23c) ^ (a>>19);
  a = (a+0x165667b1) + (a<<5);
  a = (a+0xd3a2646c) ^ (a<<9);
  a = (a+0xfd7046c5) + (a<<3);
  a = (a^0xb55a4f09) ^ (a>>16);

  /* ensure values are better spread all around the tree by multiplying
   * by a large prime close to 3/4 of the tree.
   */
  return a * 3221225473U;
}

ub32 hash6432shift (ub64 key)
{
  key = (~key) + (key << 18); // key = (key << 18) - key - 1;
  key = key ^ (key >> 31);
  key = key * 21; // key = (key + (key << 2)) + (key << 4);
  key = key ^ (key >> 11);
  key = key + (key << 6);
  key = key ^ (key >> 22);
  return (ub32) key;
}

/* Redefine this if you want another hash size. Should work ;-).
 * The number of hash buckets is computed as power of two;
 * so, e.g. HASH_SZ set to 10 yields 1024 hash rows (2^10 or 1<<10).
 * Only powers of two are possible conveniently. 
 * HASH_SZ may not be bigger than 32 (if you set it even close to that value,
 * you are nuts.) */ 
#define HASH_SZ       10 
#define HASH_NUM_BUCKETS (1<<HASH_SZ)
#define HASH_BITMASK     (HASH_NUM_BUCKETS-1)
/*
 * Hash a dns name (length-byte string format) to HASH_SZ bit.
 * *rhash is set to a long int hash.
 */
unsigned dns_hash (const unsigned char *str, unsigned long *rhash)
{
  unsigned s,i,lb,c;
  unsigned long r;
  s = 0; r = 0;
  i = 0;
  while ((lb = str[i])) {
    s += lb << (i%(HASH_SZ-5));
    r += ((unsigned long)lb) << (i%(8*sizeof(unsigned long)-7));
    ++i;
    do {
      c = toupper(str[i]);
      s += c << (i%(HASH_SZ-5));
      r += ((unsigned long)c) << (i%(8*sizeof(unsigned long)-7));
      ++i;
    } while (--lb);
  }
  s = (s & HASH_BITMASK) + ((s & (~HASH_BITMASK)) >> HASH_SZ);
  s = (s & HASH_BITMASK) + ((s & (~HASH_BITMASK)) >> HASH_SZ);
  s &= HASH_BITMASK;
  if (rhash) *rhash=r;
  return s;
}


/*
 * Integer hashing tests. These functions work with 32-bit integers, so are
 * perfectly suited for IPv4 addresses. A few tests show that they may also
 * be chained for larger keys (eg: IPv6), this way :
 *   f(x[0-3]) = f(f(f(f(x[0])^x[1])^x[2])^x[3])
 *
 * See also bob jenkin's site for more info on hashing, and check perfect
 * hashing for constants (eg: header names).
 */

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <math.h>

#define NSERV   8
#define MAXLINE 1000


int counts_id[NSERV][NSERV];
uint32_t hash_id( uint32_t a)
{
  return a;
}

/* Full-avalanche integer hashing function from Thomas Wang, suitable for use
 * with a modulo. See below, worth a read !
 * http://www.concentric.net/~Ttwang/tech/inthash.htm
 *
 * See also tests performed by Bob Jenkins (says it's faster than his) :
 * http://burtleburtle.net/bob/hash/integer.html
 *
 * This function is small and fast. It does not seem as smooth as bj6 though.
 * About 0x40 bytes, 6 shifts.
 */
int counts_tw1[NSERV][NSERV];
uint32_t hash_tw1(uint32_t a)
{
  a += ~(a<<15);
  a ^=  (a>>10);
  a +=  (a<<3);
  a ^=  (a>>6);
  a += ~(a<<11);
  a ^=  (a>>16);
  return a;
}

/* Thomas Wang's mix function. The multiply is optimized away by the compiler
 * on most platforms.
 * It is about equivalent to the one above.
 */
int counts_tw2[NSERV][NSERV];
uint32_t hash_tw2(uint32_t a)
{
  a = ~a + (a << 15);
  a = a ^ (a >> 12);
  a = a + (a << 2);
  a = a ^ (a >> 4);
  a = a * 2057;
  a = a ^ (a >> 16);
  return a;
}

/* Thomas Wang's multiplicative hash function. About 0x30 bytes, and it is
 * extremely fast on recent processors with a fast multiply. However, it
 * must not be used on low bits only, as multiples of 0x00100010 only return
 * even values !
 */
int counts_tw3[NSERV][NSERV];
uint32_t hash_tw3(uint32_t a)
{
  a = (a ^ 61) ^ (a >> 16);
  a = a + (a << 3);
  a = a ^ (a >> 4);
  a = a * 0x27d4eb2d;
  a = a ^ (a >> 15);
  return a;
}


/* Full-avalanche integer hashing function from Bob Jenkins, suitable for use
 * with a modulo. It has a very smooth distribution.
 * http://burtleburtle.net/bob/hash/integer.html
 * About 0x50 bytes, 6 shifts.
 */
int counts_bj6[NSERV][NSERV];
int counts_bj6x[NSERV][NSERV];
uint32_t hash_bj6(uint32_t a)
{
  a = (a+0x7ed55d16) + (a<<12);
  a = (a^0xc761c23c) ^ (a>>19);
  a = (a+0x165667b1) + (a<<5);
  a = (a+0xd3a2646c) ^ (a<<9);
  a = (a+0xfd7046c5) + (a<<3);
  a = (a^0xb55a4f09) ^ (a>>16);
  return a;
}

/* Similar function with one more shift and no magic number. It is slightly
 * slower but provides the overall smoothest distribution.
 * About 0x40 bytes, 7 shifts.
 */
int counts_bj7[NSERV][NSERV];
int counts_bj7x[NSERV][NSERV];
uint32_t hash_bj7(uint32_t a)
{
  a -= (a<<6);
  a ^= (a>>17);
  a -= (a<<9);
  a ^= (a<<4);
  a -= (a<<3);
  a ^= (a<<10);
  a ^= (a>>15);
  return a;
}


void count_hash_results(unsigned long hash, int counts[NSERV][NSERV]) {
  int srv, nsrv;
    
  for (nsrv = 0; nsrv < NSERV; nsrv++) {
    srv = hash % (nsrv + 1);
    counts[nsrv][srv]++;
  }
}

void dump_hash_results(char *name, int counts[NSERV][NSERV]) {
  int srv, nsrv;
  double err, total_err, max_err;

  printf("%s:\n", name);
  for (nsrv = 0; nsrv < NSERV; nsrv++) {
    total_err = 0.0;
    max_err = 0.0;
    printf("%02d srv: ", nsrv+1);
    for (srv = 0; srv <= nsrv; srv++) {
      err = 100.0*(counts[nsrv][srv] - (double)counts[0][0]/(nsrv+1)) / (double)counts[0][0];
      //printf("%6d ", counts[nsrv][srv]);
      printf("% 3.1f%%%c ", err,
             counts[nsrv][srv]?' ':'*');  /* display '*' when a server is never selected */
      err = fabs(err);
      total_err += err;
      if (err > max_err)
        max_err = err;
    }
    total_err /= (double)(nsrv+1);
    for (srv = nsrv+1; srv < NSERV; srv++)
      printf("       ");
    printf("  avg_err=%3.1f, max_err=%3.1f\n", total_err, max_err);
  }
  printf("\n");
}

int main() {
  int nr;
  unsigned int address = 0;
  unsigned int mask = ~0;

  memset(counts_id, 0, sizeof(counts_id));
  memset(counts_tw1, 0, sizeof(counts_tw1));
  memset(counts_tw2, 0, sizeof(counts_tw2));
  memset(counts_tw3, 0, sizeof(counts_tw3));
  memset(counts_bj6, 0, sizeof(counts_bj6));
  memset(counts_bj7, 0, sizeof(counts_bj7));

  address = 0x10000000;
  mask = 0xffffff00;  // user mask to apply to addresses
  for (nr = 0; nr < 0x10; nr++) {
    //address += ~nr;  // semi-random addresses.
    //address += 1;
    address += 0x00000100;
    //address += 0x11111111;
    //address += 7;
    //address += 8;
    //address += 256;
    //address += 65536;
    //address += 131072;
    //address += 0x00100010;   // this increment kills tw3 !
    count_hash_results(hash_id (address & mask), counts_id);   // 0.69s / 100M
    count_hash_results(hash_tw1(address & mask), counts_tw1);  // 1.04s / 100M
    count_hash_results(hash_tw2(address & mask), counts_tw2);  // 1.13s / 100M
    count_hash_results(hash_tw3(address & mask), counts_tw3);  // 1.01s / 100M
    count_hash_results(hash_bj6(address & mask), counts_bj6);  // 1.07s / 100M
    count_hash_results(hash_bj7(address & mask), counts_bj7);  // 1.20s / 100M
    /* adding the original address after the hash reduces the error
     * rate in in presence of very small data sets (eg: 16 source
     * addresses for 8 servers). In this case, bj7 is very good.
     */
    count_hash_results(hash_bj6(address & mask)+(address&mask), counts_bj6x); // 1.07s / 100M
    count_hash_results(hash_bj7(address & mask)+(address&mask), counts_bj7x); // 1.20s / 100M
  }

  dump_hash_results("hash_id", counts_id);
  dump_hash_results("hash_tw1", counts_tw1);
  dump_hash_results("hash_tw2", counts_tw2);
  dump_hash_results("hash_tw3", counts_tw3);
  dump_hash_results("hash_bj6", counts_bj6);
  dump_hash_results("hash_bj6x", counts_bj6x);
  dump_hash_results("hash_bj7", counts_bj7);
  dump_hash_results("hash_bj7x", counts_bj7x);
  return 0;
}


#define ROL64(x, b)     (((x) << b) | ((x) >> (64 - b)))
#define ROR64(x, b)     (((x) >> b) | ((x) << (64 - b)))

/*
 * Thomas Wang's 64-bit hash function from
 *   www.concentric.net/~Ttwang/tech/inthash.htm
 */
ub64 hash_64 (ub64 key)
{
  key += ~(key << 32);
  key ^= ROR64(key, 22);
  key += ~(key << 13);
  key ^= ROR64(key, 8);
  key += (key << 3);
  key ^= ROR64(key, 15);
  key += ~(key << 27);
  key ^= ROR64(key, 31);
  return key;
}

int hash_32 (int key)
{
  key = ~key + (key << 15);
  key = key ^ (key >> 12);
  key = key + (key << 2);
  key = key ^ (key >> 4);
  key = key * 2057;
  key = key ^ (key >> 16);
  return key;
}

int hash_64_32 (ub64 key)
{
  key = (~key) + (key << 18);
  key = key ^ (key >> 31);
  key = key * 21;
  key = key ^ (key >> 11);
  key = key + (key << 6);
  key = key ^ (key >> 22);
  return (int) key;
}




/**
 * Make hash for element
 */
#define rot(x,k) (((x)<<(k)) ^ ((x)>>(32-(k))))
#define mix(a,b,c) \
{ \
  a -= c;  a ^= rot(c, 4);  c += b; \
  b -= a;  b ^= rot(a, 6);  a += c; \
  c -= b;  c ^= rot(b, 8);  b += a; \
  a -= c;  a ^= rot(c,16);  c += b; \
  b -= a;  b ^= rot(a,19);  a += c; \
  c -= b;  c ^= rot(b, 4);  b += a; \
}
#define final(a,b,c) \
{ \
  c ^= b; c -= rot(b,14); \
  a ^= c; a -= rot(c,11); \
  b ^= a; b -= rot(a,25); \
  c ^= b; c -= rot(b,16); \
  a ^= c; a -= rot(c,4);  \
  b ^= a; b -= rot(a,14); \
  c ^= b; c -= rot(b,24); \
}

/*
 *    The hash function used here is by Bob Jenkins, 1996:
 *    <http://burtleburtle.net/bob/hash/doobs.html>
 *       "By Bob Jenkins, 1996.  bob_jenkins@burtleburtle.net.
 *       You may use this code any way you wish, private, educational,
 *       or commercial.  It's free."
 *
 */
ub32 kv_elt_hash_func (void *ptr, ub32 len)
{
  ub32 a, b, c;
  ub32 length = len;

  /* Set up the internal state */
  a = b = c = 0xdeadbeef + length;

  if (((len & 0x3) == 0)) {
    const ub32 *k = (const ub32 *)ptr; /* read 32-bit chunks */

    /*------ all but last block: aligned reads and affect 32 bits of (a,b,c) */
    while (length > 12) {
      a += k[0];
      b += k[1];
      c += k[2];
      mix (a,b,c);
      length -= 12;
      k += 3;
    }
    /*----------------------------- handle the last (probably partial) block */
    /*
     * "k[2]&0xffffff" actually reads beyond the end of the string, but
     * then masks off the part it's not allowed to read.  Because the
     * string is aligned, the masked-off tail is in the same word as the
     * rest of the string.  Every machine with memory protection I've seen
     * does it on word boundaries, so is OK with this.  But VALGRIND will
     * still catch it and complain.  The masking trick does make the hash
     * noticably faster for short strings (like English words).
     */
    switch (length)
    {
    case 12: c+=k[2]; b+=k[1]; a+=k[0]; break;
    case 11: c+=k[2]&0xffffff; b+=k[1]; a+=k[0]; break;
    case 10: c+=k[2]&0xffff; b+=k[1]; a+=k[0]; break;
    case 9 : c+=k[2]&0xff; b+=k[1]; a+=k[0]; break;
    case 8 : b+=k[1]; a+=k[0]; break;
    case 7 : b+=k[1]&0xffffff; a+=k[0]; break;
    case 6 : b+=k[1]&0xffff; a+=k[0]; break;
    case 5 : b+=k[1]&0xff; a+=k[0]; break;
    case 4 : a+=k[0]; break;
    case 3 : a+=k[0]&0xffffff; break;
    case 2 : a+=k[0]&0xffff; break;
    case 1 : a+=k[0]&0xff; break;
    case 0 : return c;  /* zero length strings require no mixing */
    }
  } else if (((len & 0x1) == 0)) {
    const ub16 *k = (const ub16 *)ptr;                           /* read 16-bit chunks */
    const ub8  *k8;

    /*--------------- all but last block: aligned reads and different mixing */
    while (length > 12) {
      a += k[0] + (((ub32)k[1])<<16);
      b += k[2] + (((ub32)k[3])<<16);
      c += k[4] + (((ub32)k[5])<<16);
      mix (a,b,c);
      length -= 12;
      k += 6;
    }

    /*----------------------------- handle the last (probably partial) block */
    k8 = (const ub8 *)k;
    switch (length)
    {
    case 12:
      c += k[4]+(((ub32)k[5])<<16);
      b += k[2]+(((ub32)k[3])<<16);
      a += k[0]+(((ub32)k[1])<<16);
      break;
    case 11:
      c += ((ub32)k8[10])<<16;     /* @fallthrough */
    case 10:
      c += k[4];                       /* @fallthrough@ */
      b += k[2]+(((ub32)k[3])<<16);
      a += k[0]+(((ub32)k[1])<<16);
      break;
    case 9 :
      c += k8[8];                      /* @fallthrough */
    case 8 :
      b += k[2]+(((ub32)k[3])<<16);
      a += k[0]+(((ub32)k[1])<<16);
      break;
    case 7 :
      b += ((ub32)k8[6])<<16;      /* @fallthrough */
    case 6 :
      b += k[2];
      a += k[0]+(((ub32)k[1])<<16);
      break;
    case 5 :
      b += k8[4];                      /* @fallthrough */
    case 4 :
      a += k[0]+(((ub32)k[1])<<16);
      break;
    case 3 :
      a += ((ub32)k8[2])<<16;      /* @fallthrough */
    case 2 :
      a += k[0];
      break;
    case 1 :
      a += k8[0];
      break;
    case 0 :
      return c;  /* zero length strings require no mixing */
    }
  } else {                        /* need to read the key one byte at a time */
    const ub8 *k = (ub8 *)ptr;

    /*--------------- all but the last block: affect some 32 bits of (a,b,c) */
    while (length > 12)
    {
      a += k[0];
      a += ((ub32)k[1])<<8;
      a += ((ub32)k[2])<<16;
      a += ((ub32)k[3])<<24;
      b += k[4];
      b += ((ub32)k[5])<<8;
      b += ((ub32)k[6])<<16;
      b += ((ub32)k[7])<<24;
      c += k[8];
      c += ((ub32)k[9])<<8;
      c += ((ub32)k[10])<<16;
      c += ((ub32)k[11])<<24;
      mix(a,b,c);
      length -= 12;
      k += 12;
    }
    /*-------------------------------- last block: affect all 32 bits of (c) */
    switch (length)                   /* all the case statements fall through */
    {
    case 12: c += ((ub32)k[11])<<24;
    case 11: c += ((ub32)k[10])<<16;
    case 10: c += ((ub32)k[9])<<8;
    case 9 : c += k[8];
    case 8 : b += ((ub32)k[7])<<24;
    case 7 : b += ((ub32)k[6])<<16;
    case 6 : b += ((ub32)k[5])<<8;
    case 5 : b += k[4];
    case 4 : a += ((ub32)k[3])<<24;
    case 3 : a += ((ub32)k[2])<<16;
    case 2 : a += ((ub32)k[1])<<8;
    case 1 : a += k[0];
    break;
    case 0 : return c;  /* zero length strings require no mixing */
    }
  }

  final (a,b,c);
  return c;             /* zero length strings require no mixing */
}
}}}
#endif

/* This is MurmurHash3. The original C++ code was placed in the public domain
 * by its author, Austin Appleby. */

static inline ub32 fmix (ub32 h)
{
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;

    return h;
}

static inline ub32 rotl32(ub32 x, int8_t r)
{
    return (x << r) | (x >> (32 - r));
}

ub32 Murmur_hash3 (const char* data, const int len)
{
    const int nblocks = len / 4;

    ub32 h1 = 0xc062fb4a;

    ub32 c1 = 0xcc9e2d51;
    ub32 c2 = 0x1b873593;

    //----------
    // body

    const ub32 * blocks = (const ub32*) (data + nblocks * 4);

    int i;
    for (i = -nblocks; i; i++)
    {
        ub32 k1 = blocks[i];

        k1 *= c1;
        k1 = rotl32(k1, 15);
        k1 *= c2;

        h1 ^= k1;
        h1 = rotl32(h1, 13);
        h1 = h1*5+0xe6546b64;
    }

    //----------
    // tail

    const ub8 * tail = (const ub8*)(data + nblocks*4);

    ub32 k1 = 0;

    switch (len & 3)
    {
        case 3: k1 ^= tail[2] << 16;
        case 2: k1 ^= tail[1] << 8;
        case 1: k1 ^= tail[0];
              k1 *= c1; k1 = rotl32(k1,15); k1 *= c2; h1 ^= k1;
    }

    //----------
    // finalization

    h1 ^= len;

    h1 = fmix(h1);

    return h1;
}

/*
 * How to use it? Well, string is the null-terminated character string
 * you need to hash. Buckets is the number of hash buckets you want to
 * use, which should be a PRIME NUMBER. This helps distribute the hash
 * values more evenly. Alphabet_size is the length of all the possible
 * characters that may be in your string. For your basic signed char type,
 * this would be 127, but you may (as I have) special purpose strings
 * which use a shorter alphabet. An example of this would be domain names,
 * which I always force to lower case, and are limited to these
 * characters: [a-z0-9.-]. The length in that case is 38. Hash_limit is
 * the maximum number of characters in the string you want to hash.
 * Generally, this should be 8 or 9. 
 * http://www.octavian.org/cs/software.html
 */

unsigned int str_hash (unsigned char *string, unsigned int buckets, unsigned int alphabet_size, int hash_limit)
{
   int i = 0;
   unsigned int accum;

   while ((string[i] != 0) && (i < hash_limit))
      i++;

   if (i < hash_limit)
      hash_limit = i;

   accum = (unsigned int) string[hash_limit - 1];

   for (i = hash_limit - 2; i >= 0; i--)
      accum = string[i] + (accum * alphabet_size);

   return accum % buckets;
}
