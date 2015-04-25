#include "utils.h"
#include "CircleDuLinkList.h"

void CircleDuLinkListInit(CircleDuLinkList *list)
{
    list->head = MALLOC(sizeof(struct node));
    list->head->next = list->head;
    list->head->prev = list->head;
}

void CircleDuLinkListDestroy(CircleDuLinkList *list, void (*destroy)(void *))
{
    struct node *n, *s;

    n = list->head->next;

    while(n != list->head) {

        s = n->next;

        if (destroy) {
            destroy(n->data);
        }

        FREE(n);
        n = s;
    }

    FREE(list->head);
}

bool CircleDuLinkListEmpty(CircleDuLinkList *list)
{
    return list->head->next == list->head;
}

static struct node * make_node(void *data)
{
    struct node *n;

    n = MALLOC(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;

    return n;
}

void CircleDuLinkListInsert(CircleDuLinkList *list, void *data)
{
    struct node *n, *s;

    n = make_node(data);
    s = list->head;

    while(s->next != list->head) {
        s = s->next;
    }

    s->next = n;
    n->prev = s;
    n->next = list->head;
    list->head->prev = n;
}

void * CircleDuLinkListSearch(CircleDuLinkList *list, void *key, int (*compare)(const void *, const void *))
{
    struct node *n;

    n = list->head;

    while(n->next != list->head) {
        if (! compare(n->next->data, key)) {
            return n->next->data;
        }

        n = n->next;
    }

    return NULL;
}

void * CircleDuLinkListDelete(CircleDuLinkList *list, void *key, int (*compare)(const void *, const void *))
{
    void *data;
    struct node *n, *s;

    n = list->head;

    while(n->next != list->head) {
        if (! compare(n->next->data, key)) {
            s = n->next;
            s->prev->next = s->next;
            s->next->prev = s->prev;
            data = s->data;
            FREE(s);
            return data;
        }

        n = n->next;
    }

    return NULL;
}

void CircleDuLinkListTraverse(CircleDuLinkList *list, int (*traverse)(void *))
{
    struct node *n;

    n = list->head;

    while(n->next != list->head) {
        traverse(n->next->data);
        n = n->next;
    }
}

