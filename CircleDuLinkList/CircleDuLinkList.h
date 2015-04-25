#ifndef _CIRCLE_DU_LINK_LIST_H_
#define _CIRCLE_DU_LINK_LIST_H_

#include <stdbool.h>

typedef struct node {
    void *data;
    struct node *prev;
    struct node *next;
} node;

typedef struct CircleDuLinkList {
    struct node *head;
} CircleDuLinkList;

extern void CircleDuLinkListInit(CircleDuLinkList *list);
extern void CircleDuLinkListDestroy(CircleDuLinkList *list, void (*destroy)(void *));
extern bool CircleDuLinkListEmpty(CircleDuLinkList *list);
extern void CircleDuLinkListInsert(CircleDuLinkList *list, void *data);
extern void * CircleDuLinkListSearch(CircleDuLinkList *list, void *key, int (*compare)(const void *, const void *));
extern void * CircleDuLinkListDelete(CircleDuLinkList *list, void *key, int (*compare)(const void *, const void *));
extern void CircleDuLinkListTraverse(CircleDuLinkList *list, void (*traverse)(void *));

#endif //_CIRCLE_DU_LINK_LIST_H_
