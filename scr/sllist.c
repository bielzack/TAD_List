#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"

typedef struct _sllist_{
    SLNode *first;
    SLNode *cur;
}SLList;

typedef struct _slnode_{
    void *data;
    struct _slnode_ *next;
} SlNode;


SLList *sllCreate(){
    SLList *l;
    l = (SLList*)malloc(sizeof(SLList));

    if(l!=NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}

int sllDestroy(SLList *l){
    if(l!=NULL){
        if(l->first == NULL){
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}

int sllInsertAsFirst(SLList *l, void *data){
    SLNode *newnode;
    
    if(l != NULL){
      newnode = (SLNode*)malloc(sizeof(SlNode));
      if(newnode != NULL){
        newnode->data = data;
        newnode->next = l->first;
        l->first = newnode;

        return TRUE;
      }
      return FALSE;
    }
    return FALSE;
}

int sllInsertAsLast(SLList *l, void *data){
    SLNode *newnode;
    SlNode *last;

    if(l != NULL){
        newnode = (SLNode *)malloc(sizeof(SLNode));
        if(newnode != NULL){
            newnode->data = data;
            newnode->next = NULL;

            if(l->first != NULL){
                last = l->first;
                while (last->next != NULL)
                {
                    last = last->next;
                }
                last->next = newnode; 
            } else {
                l->first = newnode;
            }
        }
        return TRUE;
    }
    return FALSE;
}

void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void*)){
    SlNode *spec;
    SLNode *anterior;
    SlNode *proximo;
    int stat;
    void *data;

    if(l != NULL){
        if(l->first != NULL){
            anterior = NULL;
            spec = l->first;
            stat = cmp(key, spec->data);
            while(stat != TRUE && spec->next != TRUE){
                anterior = spec;
                spec = spec->next;
                stat = cmp(key, spec->data);

            }
            if(stat == TRUE){
                proximo = spec->next;
                data = spec->data;

                if(anterior != NULL){
                    anterior->next = proximo;
                } else {
                    l->first = proximo;
                }
                free(spec);
                return data;


            }
        }
    }
    return NULL;
}

void *sllQuery(SLList *l,void *key, int(*cmp)(void *, void *)){
    SlNode *cur;
    int stat;

    if(l != NULL){
        if(l->first != NULL){
            cur = l->first;
            stat = cmp(key, cur->data);
            while(stat != TRUE && cur->next != TRUE){
                cur = cur->next;
                stat = cmp(key, cur->data);
            }
            if(stat == TRUE){
                return cur->data;
            }
        }
    }
    return NULL;
}

void *sllGetFirst(SLList *l){
    SLNode *spec;
    if(l != NULL){
        if(l->first != NULL){
            l->cur = l->first;
            spec = l->cur;
            return spec->data;
        }
    }
    return NULL;
}

void *sllGetNext(SLList *l){
    SLNode *atual;
    SLNode *proximo;
    if(l != NULL){
        if(l->cur != NULL){
            atual = l->cur;
            proximo = atual->next;
            l->cur = proximo;
            if(proximo != NULL){
                return proximo->data;
            }
        }
    }
    return NULL;
}








