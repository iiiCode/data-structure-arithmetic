#ifndef _LINEAR_LIST_H_
#define _LINEAR_LIST_H_

#include <stdbool.h>

typedef void * ElemType;

typedef struct LinearList {
    int length;
    int capacity;
    ElemType *ElemBase;
} LinearList;

typedef enum STATE {
    OK = 0,
    ERROR_OUT_OF_INDEX = -1,
    ERROR_CAN_NOT_FIND = -2
} status_t;

extern void LinearListInit(LinearList *list);
extern void LinearListDestroy(LinearList *list, void (*destroy)(ElemType));
extern void LinearListClear(LinearList *list, void (*destroy)(ElemType));
extern void LinearListTraverse(LinearList *list, void (*traverse)(ElemType));
extern int  LinearListLength(LinearList *list);
extern bool LinearListEmpty(LinearList *list);

/*
 * Insert element [Elem] into linear list at position [pos].
 * */
extern status_t LinearListInsert(LinearList *list, int pos, ElemType Elem);

/*
 * Delete Element from linear list, the deleted element's position is [pos].
 * [pDelElem] takes the deleted element.
 * */
extern status_t LinearListDelete(LinearList *list, int pos, ElemType *pDelElem);

extern status_t LinearListGetElement(LinearList *list, int pos, ElemType *pOutElem);
#endif //_LINEAR_LIST_H_
