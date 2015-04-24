#ifndef _DOUBLE_DIRECTION_LINK_LIST_H_
#define _DOUBLE_DIRECTION_LINK_LIST_H_

#include <stdbool.h>

typedef struct node {
    void *data;
    struct node *prev;
    struct node *next;
} node;

typedef struct DuLinkList {
    struct node *head;
} DuLinkList;

extern void DuLinkListInit(DuLinkList *list);
extern bool DuLinkListEmpty(DuLinkList *list);
extern void DuLinkListInsert(DuLinkList *list, void *data);
extern void DuLinkListDestroy(DuLinkList *list, void (*destroy)(void *));
extern void DuLinkListTraverse(DuLinkList *list, void (*traverse)(void *));
extern void * DuLinkListSearch(DuLinkList *list, void *key, int (*compare)(const void *, const void *));
extern void * DuLinkListDelete(DuLinkList *list, void *key, int (*compare)(const void *, const void *));

#endif //_DOUBLE_DIRECTION_LINK_LIST_H_
