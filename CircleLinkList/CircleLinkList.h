#ifndef CIRCLE_LINK_LIST_H_
#define CIRCLE_LINK_LIST_H_

struct node {
    void *data;
    struct node *next;
};

typedef struct CircleLinkList {
    struct node *list;
    struct node *first;
} CircleLinkList;

extern void CircleLinkListInit(CircleLinkList *list);
extern void CircleLinkListInit(CircleLinkList *list, void (*destroy)(void *));

#endif //CIRCLE_LINK_LIST_H_
