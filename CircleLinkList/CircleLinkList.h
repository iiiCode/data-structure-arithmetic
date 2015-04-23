#ifndef CIRCLE_LINK_LIST_H_
#define CIRCLE_LINK_LIST_H_

#include <stdbool.h>

typedef struct node {
    const void *data;
    struct node *next;
} node;

typedef struct CircleLinkList {
    struct node *head;
} CircleLinkList;

extern void CircleLinkListInit(CircleLinkList *list);
extern void CircleLinkListDestroy(CircleLinkList *list, void (*destroy)(const void *));
extern void CircleLinkListInsert(CircleLinkList *list, const void *data);
extern bool CircleLinkListEmpty(CircleLinkList *list);
extern void CircleLinkListTraverse(CircleLinkList *list, void (*traverse)(const void *));
extern void CircleLinkListInfiniteTraverse(CircleLinkList *list, void (*traverse)(const void *));
extern const void *CircleLinkListSearch(CircleLinkList *list, const void *data, int (*compare)(const void *, const void *));
extern const void *CircleLinkListDelete(CircleLinkList *list, const void *data, int (*compare)(const void *, const void *));

#endif //CIRCLE_LINK_LIST_H_
