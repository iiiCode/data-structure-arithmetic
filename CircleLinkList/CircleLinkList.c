#include "utils.h"
#include "CircleLinkList.h"

static struct node * make_node(const void *data)
{
    struct node *n;

    n = MALLOC(sizeof(struct node));
    n->data = data;
    n->next = NULL;

    return n;
}

void CircleLinkListInit(CircleLinkList *list)
{
    list->head = NULL;
}

void CircleLinkListDestroy(CircleLinkList *list, void (*destroy)(const void *))
{
    struct node *n, *s;

    n = list->head;

    if (! list->head) {
        return;
    }

    while(n->next != list->head) {
        s = n->next;
        n->next = s->next;
        if (destroy) {
            destroy(s->data);
        }
        FREE(s);
    }

    if (destroy) {
        destroy(list->head->data);
    }

    FREE(list->head);
}

bool CircleLinkListEmpty(CircleLinkList *list)
{
    return list->head == NULL;
}

void CircleLinkListInsert(CircleLinkList *list, const void *data)
{
    struct node *n;

    n = make_node(data);

    if (! list->head) {
        list->head = n;
        n->next = n;
    } else {
        n->next = list->head->next;
        list->head->next = n;
    }
}

const void *CircleLinkListSearch(CircleLinkList *list, const void *data, 
        int (*compare)(const void *, const void *))
{
    struct node *n;

    n = list->head;

    if (! list->head) {
        return NULL;
    }

    if (n->next == list->head) {
        if (! compare(n->data, data)) {
            return n->data;
        }
    }

    while(n->next != list->head) {
        if (! compare(n->next->data, data)) {
            return n->next->data;
        }
        n = n->next;
    }

    return NULL;
}

const void * CircleLinkListDelete(CircleLinkList *list, const void *data, 
        int (*compare)(const void *, const void *))
{
    const void *del;
    struct node *n, *s;

    n = list->head;

    if (! list->head) {
        return NULL;
    }

    if (list->head->next == list->head) {
        if (! compare(list->head->data, data)) {
            del = list->head->data;
            FREE(list->head);
            return del;
        }
    }

    while(n->next != list->head) {
        if (! compare(n->next->data, data)) {
            s = n->next;
            n->next = s->next;
            del = s->data;
            FREE(s);
            return del;
        }

        n = n->next;
    }

    return NULL;
}

void CircleLinkListTraverse(CircleLinkList *list, void (*traverse)(const void *))
{
    struct node *n = list->head;

    if (list->head) {

        while(n->next != list->head) {
            traverse(n->data);
            n = n->next;
        }

        traverse(list->head->data);
    }
}

void CircleLinkListInfiniteTraverse(CircleLinkList *list, void (*traverse)(const void *))
{
        while(list->head) {
            traverse(list->head->data);
            list->head = list->head->next;
        }
}

