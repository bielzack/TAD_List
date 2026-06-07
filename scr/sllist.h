#ifndef _SLLIST_H
#define _SLLIST_H
#define TRUE 1
#define FALSE 0


typedef struct _sllist_ SLList;
typedef struct _slnode_ SLNode; 

SLList *sllCreate();

int sllDestroy(SLList *l);

int sllInsertAsFirst(SLList *l, void *data);

int sllInsertAsLast(SLList *l, void *data);

void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void*));

void *sllQuery(SLList *l,void *key, int(*cmp)(void *, void *));

void *sllGetFirst(SLList *l);

void *sllGetNext(SLList *l);

SLList* sllInterseccao(SLList *l1, SLList *l2, int(*cmp)(void*,void*));

SLList* sllUniao(SLList *l1, SLList *l2, int(*cmp)(void*,void*));

#endif
