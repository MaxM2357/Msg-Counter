#include "dict.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Node_t{
    char *key;
    unsigned int value;
    struct Node_t *next;
} Node;


struct Dict_t {
    Node *first;
    unsigned int nkeys;
};


Dict *dictCreate(void){
    Dict *d = malloc(sizeof(Dict));
    d -> first = NULL;
    d -> nkeys = 0;
    return d;
}


void dictFree(Dict *d){
    Node *p = d -> first;
    while(p != NULL){
        d -> first = p;
        p = p -> next;
        free(d -> first);
    }
    free(d);
    return;
}


void dictInsert(Dict *d, char *key, int value){
    Node *p = d -> first;
    
    if(p == NULL){
        d -> first = malloc(sizeof(Node));
        p = d -> first;
        p -> value = value;
        p -> key = strdup(key);
        p -> next = NULL;
        return;
    }

    while(1){
        if(strcmp(p -> key, key) == 0){
            p -> value = value;
            return;
        }
        if(p -> next == NULL) break;
        p = p -> next;
    }
    p -> next = malloc(sizeof(Node));
    p = p -> next;
    p -> value = value;
    p -> key = strdup(key);
    p -> next = NULL;
    return;
}


void dictAdd(Dict *d, char *key, int inc){
    int val = dictSearch(d, key);
    if(val == -1) dictInsert(d, key, inc);
    else dictInsert(d, key, inc+val);
    return;
}


int dictSearch(Dict *d, char *key){
    if(d -> first == NULL) return -1;
    Node *p = d -> first;
    while(p != NULL){
        if(strcmp(p -> key, key) == 0){
            return p -> value;
        }
        p = p -> next;
    }
    return -1;
}


void dictPrint(Dict *d){

    for(Node *p = d -> first; p != NULL; p = p -> next)
        printf("%s\t%d\n", p -> key, p -> value);
    return;
}
