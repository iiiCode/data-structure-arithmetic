#include "utils.h"
#include "DuLinkList.h"

void DuLinkListInit(DuLinkList *list)
{
    list->head = NULL;
}

bool DuLinkListEmpty(DuLinkList *list)
{
    return list->head == NULL;
}

void DuLinkListDestroy(DuLinkList *list, void (*destroy)(void *))
{
    struct node *n;

    while(list->head) {
        n = list->head;
        list->head = n->next;
        if (destroy) {
            destroy(n->data);
        }

        FREE(n);
    }
}

static struct node * make_node(void *data)
{
    struct node * n;

    n = MALLOC(sizeof(struct node));
    n->data = data;
    n->prev = NULL;
    n->next = NULL;

    return n;
}

void DuLinkListInsert(DuLinkList *list, void *data)
{
    struct node *n;

    n = make_node(data);

    if (! list->head) {
        list->head = n;
    } else {
        n->next = list->head;
        list->head->prev = n;
        list->head = n;
    }
}

void * DuLinkListSearch(DuLinkList *list, void *key, int (*compare)(const void *, const void *))
{
    struct node *n = list->head;

    while(n) {
        if (! compare(n->data, key)) {
            return n->data;
        }

        n = n->next;
    }

    return NULL;

}

void * DuLinkListDelete(DuLinkList *list, void *key, int (*compare)(const void *, const void *))
{
    void *data;
    struct node *n;
    
    n = list->head;

    if (! compare(n->data, key)) {
        data = n->data;
        list->head = n->next;
        n->next->prev = NULL;
        return data;
    }

    while(n) {
        if (! compare(n->data, key)) {
            data = n->data;
            n->prev->next = n->next;
            n->next->prev = n->prev;
            FREE(n);
            return data;
        }
        n = n->next;
    }

    return NULL;
}

void DuLinkListTraverse(DuLinkList *list, void (*traverse)(void *))
{
    struct node *n = list->head;

    while(n) {
        traverse(n->data);
        n = n->next;
    }
}


