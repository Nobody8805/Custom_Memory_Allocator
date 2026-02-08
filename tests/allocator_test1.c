#include <stdio.h>
#include <string.h>
#include "allocator.h"

int main(){

  char *p = alloc(50);
  char *q = alloc(150);

  strcpy(p, "Hello world!");
  strcpy(q, "This is my custom memory allocator!");

  printf("%s \n %s \n", p, q);

  afree(q);
  afree(p);

  char *r = alloc(200);
  strcpy(r, "Memory was used and cleared successfully!");
  printf("%s \n", r);
  afree(r);

  return 0;
}
