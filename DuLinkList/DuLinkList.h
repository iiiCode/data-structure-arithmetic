#ifndef _DOUBLE_DIRECTION_LINK_LIST_H_
#define _DOUBLE_DIRECTION_LINK_LIST_H_

typedef struct node {
    const void *data;
    struct node *prev;
    struct node *next;
} node;

typedef struct DuLinkList {
    struct node *head;
} DuLinkList;

#endif //_DOUBLE_DIRECTION_LINK_LIST_H_
