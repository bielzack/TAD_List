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
} SLNode;


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
      newnode = (SLNode*)malloc(sizeof(SLNode));
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
    SLNode *last;

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
            return TRUE;
        }
        
    }
    return FALSE;
}

void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void*)){
    SLNode *spec;
    SLNode *anterior;
    SLNode *proximo;
    int stat;
    void *data;

    if(l != NULL){
        if(l->first != NULL){
            anterior = NULL;
            spec = l->first;
            stat = cmp(key, spec->data);
            while(stat != TRUE && spec->next != NULL){
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
    SLNode *cur;
    int stat;

    if(l != NULL){
        if(l->first != NULL){
            cur = l->first;
            stat = cmp(key, cur->data);
            while(stat != TRUE && cur->next != NULL){
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

SLList* sllInterseccao(SLList *l1, SLList *l2, int (*cmp)(void*, void*)){
    SLList *conjunto3;
    void *elemAtual;

    if(l1 != NULL && l2 != NULL){
        if(l1->first != NULL && l2->first != NULL){
            
            conjunto3 = sllCreate();
            if(conjunto3 != NULL){
                elemAtual = sllGetFirst(l1);

                while(elemAtual != NULL){
                    if (sllQuery(l2, elemAtual, cmp) != NULL && sllQuery(conjunto3, elemAtual, cmp) == NULL) {                
                        sllInsertAsLast(conjunto3, elemAtual);
                    }
                    elemAtual = sllGetNext(l1);
                }
                return conjunto3;
            }
        }
    }
    return NULL;
}
SLList* sllUniao(SLList *l1, SLList *l2, int (*cmp)(void*, void*)) {
    SLList *conjunto3;
    void *elemL1;
    void *elemL2;

    if(l1 != NULL && l2 != NULL){
        if(l1->first != NULL && l2->first != NULL){

            conjunto3 = sllCreate();
            if(conjunto3 != NULL){

                elemL1 = sllGetFirst(l1);
                while(elemL1 != NULL){
                    if(sllQuery(conjunto3, elemL1, cmp) == NULL) {
                        sllInsertAsLast(conjunto3, elemL1);
                    }
                    elemL1 = sllGetNext(l1);
                }
                elemL2 = sllGetFirst(l2);
                while(elemL2 != NULL){
                    if(sllQuery(conjunto3, elemL2, cmp) == NULL){
                        sllInsertAsLast(conjunto3, elemL2);
                    }
                    elemL2 = sllGetNext(l2);
                }
                return conjunto3;
            }
        }
    }
    return NULL;
}









