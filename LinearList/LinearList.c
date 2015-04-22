#include "utils.h"
#include "LinearList.h"

#include <string.h>

#define INCREASE_STEP 8

void LinearListInit(LinearList *list)
{
    list->length = 0;
    list->capacity = INCREASE_STEP;
    list->ElemBase = MALLOC(sizeof(ElemType) * list->capacity);
}

void LinearListClear(LinearList *list, void (*destroy)(ElemType))
{
    int i;

    for (i = 0; i < list->length; i ++) {
        if (destroy) {
            destroy(list->ElemBase[i]);
        }
    }

    list->length = 0;
}

void LinearListDestroy(LinearList *list, void (*destroy)(ElemType))
{
    int i;

    for (i = 0; i < list->length; i ++) {
        if (destroy) {
            destroy(list->ElemBase[i]);
        }
    }

    list->length = 0;
    list->capacity = 0;
    FREE(list->ElemBase);
}

void LinearListTraverse(LinearList *list, void (*traverse)(ElemType))
{
    int i;

    for (i = 0; i < list->length; i ++) {
        if (traverse) {
            traverse(list->ElemBase[i]);
        }
    }
}

int LinearListLength(LinearList *list)
{
    return list->length;
}

bool LinearListEmpty(LinearList *list)
{
    return list->length == 0;
}

static void _LinearListExpand(LinearList *list)
{
    ElemType *Base;

    list->capacity += INCREASE_STEP;
    Base = MALLOC(sizeof(ElemType) * list->capacity);
    memcpy(Base, list->ElemBase, sizeof(ElemType) * list->length);
    FREE(list->ElemBase); list->ElemBase = Base;
}

status_t LinearListInsert(LinearList *list, int pos, ElemType Elem)
{
    int i;

    if (pos < 0 || pos > list->length) {
        return ERROR_OUT_OF_INDEX;
    }

    if (list->length >= list->capacity) {
        _LinearListExpand(list);
    }

    for (i = list->length; i != pos; i --) {
        list->ElemBase[i] = list->ElemBase[i - 1];
    }

    list->length ++;
    list->ElemBase[i] = Elem;

    return OK;
}

status_t LinearListDelete(LinearList *list, int pos, ElemType *pDelElem)
{
    int i;

    if (pos < 0 || pos > list->length) {
        return ERROR_OUT_OF_INDEX;
    }

    list->length --;
    *pDelElem = list->ElemBase[pos];

    for (i = pos; i < list->length; i ++) {
        list->ElemBase[i] = list->ElemBase[i + 1];
    }

    return OK;
}

status_t LinearListGetElement(LinearList *list, int pos, ElemType *pOutElem)
{
    if (pos < 0 || pos > list->length) {
        return ERROR_OUT_OF_INDEX;
    }

    *pOutElem = list->ElemBase[pos];

    return OK;
}

void LinearListUnion(LinearList *aList, LinearList *bList, int (*compare)(ElemType, ElemType))
{
    int i;
    ElemType elem;

    for (i = 0; i < LinearListLength(bList); i ++) {
        LinearListGetElement(bList, i, &elem);
        if (! LinearListSearch(aList, elem, compare)) {
            LinearListInsert(aList, i, elem);
            LinearListDelete(bList, i, &elem);
        }
    }
}

ElemType LinearListSearch(LinearList *list, ElemType key, int (*compare)(ElemType, ElemType))
{
    int i;

    for (i = 0; i < list->length; i ++) {
        if (! compare(list->ElemBase[i], key)) {
            return list->ElemBase[i];
        }
    }

    return NULL;
}
