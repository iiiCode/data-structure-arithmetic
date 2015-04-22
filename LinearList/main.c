#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LinearList.h"

#define SIZE 20

static void array_init(int *arr, int size)
{
    int i;

    for (i = 0; i < size; i ++) {
        arr[i] = rand() % 90 + 10;
    }
}

static void array_show(int *arr, int size)
{
    int i;

    for (i = 0; i < size; i ++) {
        printf("%d ", arr[i]);
    }

    putchar('\n');
}

static void traverse(void *data)
{
    printf("%d ", *((int *)data));
}

static void destroy(void *data)
{
    free(data);
}

void data_traverse(LinearList *list)
{
    int i;
    int *v;

    for (i = 0; i < LinearListLength(list); i ++) {
        LinearListGetElement(list, i, (void **)&v);
        printf("%d ", *v);
    }

    putchar('\n');
}

static int compare(void *first, void *second)
{
    int *f = first;
    int *s = second;

    return *f - *s;
}

int main(int argc, char *argv[])
{
    int pos;
    int i, *v;
    int arr[SIZE];
    LinearList list;

    srand(time(NULL));

    LinearListInit(&list);
    array_init(arr, SIZE);
    array_show(arr, SIZE);

    for (i = 0; i < SIZE; i ++) {
        v = malloc(sizeof(int));
        *v = arr[i];
        LinearListInsert(&list, 0, v);
    }

    LinearListTraverse(&list, traverse); putchar('\n');

    LinearListClear(&list, destroy);

    for (i = 0; i < SIZE; i ++) {
        v = malloc(sizeof(int));
        *v = arr[i];
        LinearListInsert(&list, LinearListLength(&list), v);
    }

    LinearListTraverse(&list, traverse); putchar('\n');

    while(! LinearListEmpty(&list)) {
        pos = rand() % LinearListLength(&list);
        LinearListGetElement(&list, pos, (void **)&v);
        printf("Delete: %d\n", *v);
        LinearListDelete(&list, pos, (void **)&v);
        data_traverse(&list);
    }

    LinearListDestroy(&list, destroy);

    //Test LinearListUnion
    int aArr[12], bArr[15];
    LinearList aList, bList;

    array_init(aArr, 12);
    array_init(bArr, 15);
    array_show(aArr, 12);
    array_show(bArr, 15);


    LinearListInit(&aList);
    LinearListInit(&bList);

    for (i = 0; i < 12; i ++) {
        v = malloc(sizeof(int));
        *v = aArr[i];
        LinearListInsert(&aList, 0, v);
    }

    for (i = 0; i < 15; i ++) {
        v = malloc(sizeof(int));
        *v = bArr[i];
        LinearListInsert(&bList, 0, v);
    }

    LinearListTraverse(&aList, traverse); putchar('\n');
    LinearListTraverse(&bList, traverse); putchar('\n');

    LinearListUnion(&aList, &bList, compare);
    LinearListTraverse(&aList, traverse); putchar('\n');


    LinearListDestroy(&aList, destroy);
    LinearListDestroy(&bList, destroy);
    return 0;
}

