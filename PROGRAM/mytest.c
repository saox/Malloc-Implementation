/*
 * Description:
 *
 * Save the address of the twilight zone.
 * First phase - allocate a MAXPOSTS number of memory blocks each
 *               of random size but of MAXSIZE/2.
 *              Check that zero size the returned pointer was NULL.
 *              Check that for non-zero size the pointer is not NULL.
 *              Fill the beginning of each block with a float.
 *
 * Computer memory usage
 *
 * Second phase - realloc randomly blocks requesting for sizes that either
 *		  can shrink or dilate the original block.
 *		  null blocks are allcated if necessary.
 *
 * Compute current break and used memory.
 * $Log: tstalgorithms.c,v $
 * Revision 1.3  1993/12/01  14:34:41  luis
 * Checks that NULL is returned for 0 bytes allocation, and that
 * non-zero is returned for non-zero bytes (trivial, but some malloc's
 * do it ...).
 *
 * Revision 1.2  1993/11/10  14:36:06  luis
 * Bug fixed. It didn't check that malloc returned NULL when size is zero.
 * An attempt to write on a NULL address generated SIGSEGV.
 *
 * Revision 1.1  1993/11/10  10:19:22  luis
 * Initial revision
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "malloc.h"
#include "tst.h"
#include "brk.h"

#define MAXPOSTS 2000
#define MAXSIZE  2048
#define MAXITERS 10000
#define ALLOCATED(i) (memPosts[i].size > 0)

typedef struct
{
  double *ptr;
  int size;
} allocpost;

allocpost memPosts[MAXPOSTS];

void calcMemUsage(int *max)
{
  int sum=0,i;
  for(i=0;i<MAXPOSTS;i++) sum += memPosts[i].size*sizeof(double);
  if(sum > *max) *max = sum;
}

int main(int argc, char *argv[])
{
  int i, maxMem=0;
  void *start, *end;
  char *progname;

  if (argc > 0)
    progname = argv[0];
  else
    progname = "";

#ifdef MMAP
  start = endHeap();
#else
  start = (void *)sbrk(0);
#endif

MESSAGE("\n");


void * cp = malloc(2);
free(cp);

char * c = malloc(1024);


free(c);


MESSAGE("\n");

#ifdef MMAP
  end = endHeap();
#else
  end = (void *) sbrk(0);
#endif

  return 0;
}