#ifndef __BMH_H__
#define __BMH_H__

unsigned char *bmh_cs_search (unsigned char *text, int n, unsigned char *pat, int m);
unsigned char *bmh_ci_search (unsigned char *text, int n, unsigned char *pat, int m);
unsigned char *bmh_csw_search (unsigned char *text, int n, unsigned char *pat, int m);
unsigned char *bmh_ciw_search (unsigned char *text, int n, unsigned char *pat, int m);


#define BM_ASIZE 256 /* Allowed character code values */

typedef struct
{
  int xsize;
  int *bmGs;
    
  int bmBc[BM_ASIZE];
  unsigned char *saved_x;
  int saved_m;

  int icase;
} BM;


extern int  bm_init(BM *bmp, unsigned char *x, int m, int icase);
extern int  bm_search(BM *bmp, unsigned char *y, int n, int (*mfun)(void *buf, int n, int pos));
extern void bm_destroy(BM *bmp);

#endif
