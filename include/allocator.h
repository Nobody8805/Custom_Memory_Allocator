#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h> //for size_t--> used to measure memory of a var
                    
char *alloc(size_t n); 

void afree(char *p);

void alloc_reset(void);

#endif


