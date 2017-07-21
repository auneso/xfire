/*
** 2014-12-24 HDS
*/
/*
  This is a maximally equidistributed combined Tausworthe generator
  based on code from GNU Scientific Library 1.5 (30 Jun 2004)

   x_n = (s1_n ^ s2_n ^ s3_n)

   s1_{n+1} = (((s1_n & 4294967294) <<12) ^ (((s1_n <<13) ^ s1_n) >>19))
   s2_{n+1} = (((s2_n & 4294967288) << 4) ^ (((s2_n << 2) ^ s2_n) >>25))
   s3_{n+1} = (((s3_n & 4294967280) <<17) ^ (((s3_n << 3) ^ s3_n) >>11))

   The period of this generator is about 2^88.

   From: P. L'Ecuyer, "Maximally Equidistributed Combined Tausworthe
   Generators", Mathematics of Computation, 65, 213 (1996), 203--213.

   This is available on the net from L'Ecuyer's home page,

   http://www.iro.umontreal.ca/~lecuyer/myftp/papers/tausme.ps
   ftp://ftp.iro.umontreal.ca/pub/simulation/lecuyer/papers/tausme.ps

   There is an erratum in the paper "Tables of Maximally
   Equidistributed Combined LFSR Generators", Mathematics of
   Computation, 68, 225 (1999), 261--269:
   http://www.iro.umontreal.ca/~lecuyer/myftp/papers/tausme2.ps

        ... the k_j most significant bits of z_j must be non-
        zero, for each j. (Note: this restriction also applies to the
        computer code given in [4], but was mistakenly not mentioned in
        that paper.)

   This affects the seeding procedure by imposing the requirement
   s1 > 1, s2 > 7, s3 > 15.

*/

#include <string.h>
#include <sys/time.h>
#include "xtypes.h"
#include "xalloc.h"
#include "xrand.h"

/*  2^63 + 2^61 - 2^57 + 2^54 - 2^51 - 2^18 + 1 */
#define GOLDEN_RATIO_PRIME 0x9e37fffffffc0001UL

static inline int __seed(unsigned int x, unsigned int m)
{
  return (x < m) ? x + m : x;
}

static void __init_rand(struct frand_state *state, unsigned int seed)
{
  int cranks = 6;

#define LCG(x, seed)  ((x) * 69069 ^ (seed))

  state->s1 = __seed(LCG((2^31) + (2^17) + (2^7), seed), 1);
  state->s2 = __seed(LCG(state->s1, seed), 7);
  state->s3 = __seed(LCG(state->s2, seed), 15);

  while (cranks--)
    __rand(state);
}

void xrand_init (struct frand_state *state)
{
  __init_rand(state, 1);
}

void xrand_seed_init (struct frand_state *state, unsigned int seed)
{
  __init_rand(state, seed);
}

void xrand_fill_buf_seed (void *buf, unsigned int len, unsigned long seed)
{
  long *ptr = buf;

  while ((void *) ptr - buf < len) {
    *ptr = seed;
    ptr++;
    seed *= GOLDEN_RATIO_PRIME;
    seed >>= 3;
  }
}

unsigned long xrand_fill_buf (struct frand_state *fs, void *buf, unsigned int len)
{
  unsigned long r = __rand(fs);

  if (sizeof(int) != sizeof(long *))
    r *= (unsigned long) __rand(fs);

  xrand_fill_buf_seed(buf, len, r);
  return r;
}

unsigned long xrand_fill_buf_percentage (struct frand_state *fs, void *buf, unsigned int percentage, unsigned int segment, unsigned int len)
{
  unsigned long r = __rand(fs);
  unsigned int this_len;

  if (percentage == 100) {
    memset(buf, 0, len);
    return 0;
  }

  if (segment > len)
    segment = len;

  if (sizeof(int) != sizeof(long *))
    r *= (unsigned long) __rand(fs);

  while (len) {
    /*
     * Fill random chunk
     */
    this_len = (segment * (100 - percentage)) / 100;
    if (this_len > len)
      this_len = len;

    xrand_fill_buf_seed(buf, this_len, r);

    len -= this_len;
    buf += this_len;

    if (this_len > len)
      this_len = len;

    memset(buf, 0, this_len);
    len -= this_len;
    buf += this_len;
  }

  return r;
}


#include <stdlib.h> // For random(), RAND_MAX

// Assumes 0 <= max <= RAND_MAX
// Returns in the closed interval [0, max]
long random_at_most(long max)
{
  unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;

  long x;
  do {
   x = random();
  }
  // This is carefully written not to overflow
  while (num_rand - defect <= (unsigned long)x);

  // Truncated division is intentional
  return x/bin_size;
}




/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0df   /* constant vector a */
#define UPPER_MASK 0x80000000 /* most significant w-r bits */
#define LOWER_MASK 0x7fffffff /* least significant r bits */

/* Tempering parameters */
#define TEMPERING_MASK_B 0x9d2c5680
#define TEMPERING_MASK_C 0xefc60000
#define TEMPERING_SHIFT_U(y)  (y >> 11)
#define TEMPERING_SHIFT_S(y)  (y << 7)
#define TEMPERING_SHIFT_T(y)  (y << 15)
#define TEMPERING_SHIFT_L(y)  (y >> 18)

struct _XRand
{
  ub32 mt[N]; /* the array for the state vector  */
  ub32 mti;
};


void
xrand_set_seed_array (XRand *rand, const ub32 *seed, int seed_length)
{
  int i, j, k;

  i=1; j=0;
  k = (N>seed_length ? N : seed_length);
  for (; k; k--) {
    rand->mt[i] = (rand->mt[i] ^ ((rand->mt[i-1] ^ (rand->mt[i-1] >> 30)) * 1664525UL)) + seed[j] + j; /* non linear */
    rand->mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
    i++; j++;
    if (i>=N) {
      rand->mt[0] = rand->mt[N-1];
      i=1;
    }
    if (j>=seed_length)
      j=0;
  }
  for (k=N-1; k; k--) {
    rand->mt[i] = (rand->mt[i] ^ ((rand->mt[i-1] ^ (rand->mt[i-1] >> 30)) * 1566083941UL)) - i; /* non linear */
    rand->mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
    i++;
    if (i>=N) {
      rand->mt[0] = rand->mt[N-1];
      i=1;
    }
  }

  rand->mt[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */
}

XRand*
xrand_new_with_seed_array (const ub32 *seed, int seed_length)
{
  XRand *rand = xzalloc (sizeof(XRand));
  xrand_set_seed_array (rand, seed, seed_length);
  return rand;
}


XRand *
xrand_new (void)
{
  ub32 seed[4];
  struct timeval now;

  gettimeofday(&now, NULL);
  seed[0] = now.tv_sec;
  seed[1] = now.tv_usec;
  seed[2] = getpid ();
  seed[3] = getppid ();

  return xrand_new_with_seed_array (seed, 4);
}


ub32
xrand_int (XRand *rand)
{
  ub32 y;
  static const ub32 mag01[2]={0x0, MATRIX_A};
  /* mag01[x] = x * MATRIX_A  for x=0,1 */

  if (rand->mti >= N) { /* generate N words at one time */
    int kk;
   
    for (kk = 0; kk < N - M; kk++) {
      y = (rand->mt[kk]&UPPER_MASK)|(rand->mt[kk+1]&LOWER_MASK);
      rand->mt[kk] = rand->mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1];
    }
    for (; kk < N - 1; kk++) {
      y = (rand->mt[kk]&UPPER_MASK)|(rand->mt[kk+1]&LOWER_MASK);
      rand->mt[kk] = rand->mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1];
    }
    y = (rand->mt[N-1]&UPPER_MASK)|(rand->mt[0]&LOWER_MASK);
    rand->mt[N-1] = rand->mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1];

    rand->mti = 0;
  }

  y = rand->mt[rand->mti++];
  y ^= TEMPERING_SHIFT_U(y);
  y ^= TEMPERING_SHIFT_S(y) & TEMPERING_MASK_B;
  y ^= TEMPERING_SHIFT_T(y) & TEMPERING_MASK_C;
  y ^= TEMPERING_SHIFT_L(y);

  return y;
}


/* transform [0..2^32] -> [0..1] */
#define X_RAND_DOUBLE_TRANSFORM 2.3283064365386962890625e-10

ub32
xrand_int_range (XRand *rand, ub32  begin, ub32  end)
{
  ub32 dist = end - begin;
  ub32 random;

  if (dist == 0) random = 0;
  else {
    /* maxvalue is set to the predecessor of the greatest
     * multiple of dist less or equal 2^32.
     */
    ub32 maxvalue;
    if (dist <= 0x80000000u) /* 2^31 */
    {
      /* maxvalue = 2^32 - 1 - (2^32 % dist) */
      ub32 leftover = (0x80000000u % dist) * 2;
      if (leftover >= dist) leftover -= dist;
        maxvalue = 0xffffffffu - leftover;
    }
    else
      maxvalue = dist - 1;

    do
      random = xrand_int (rand);
    while (random > maxvalue);

    random %= dist;
  }

  return begin + random;
}
