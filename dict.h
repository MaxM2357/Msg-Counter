#ifndef dict_h
#define dict_h

#include <stdio.h>

typedef struct Dict_t Dict;

Dict *dictCreate(void);
void dictFree(Dict *d);
void dictInsert(Dict *d, char *key, int value);
void dictAdd(Dict *d, char *key, int inc);
int dictSearch(Dict *d, char *key);
void dictPrint(Dict *d);

#endif /* dict_h */
