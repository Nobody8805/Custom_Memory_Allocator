#include "include/allocator.h"

#define ALLOCSIZE 10000

static char allocbuff[ALLOCSIZE]; //private memory area
static char *allocp = allocbuff; //next free byte

char *alloc(size_t n){
  if((size_t) (allocbuff + ALLOCSIZE - allocp) >= n){ //basically the new requested space fits.
    char *p = allocp;
    allocp += n;
    return p;
  }
  else {
    return 0;
  }
}

void afree(char *p){
  if (p >= allocbuff && p < allocbuff + ALLOCSIZE){
    allocp = p;
  }
}

void alloc_reset(void){
  allocp = allocbuff;
}


