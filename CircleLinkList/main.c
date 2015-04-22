#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"
#include "CircleLinkList.h"

static void traverse(const void *data)
{
    printf("%d ", *(int *)data);
}

static void destroy(const void *data)
{
    void *_data = (void *)data;

    FREE(_data);
}

int main(int argc, char *argv[])
{
    int i, *v;
    CircleLinkList list;

    srand(time(NULL));

    CircleLinkListInit(&list);

    for (i = 0; i < 20; i ++) {
        v = MALLOC(sizeof(int));
        *v = rand() % 90 + 10;
        printf("%d ", *v);
        CircleLinkListInsert(&list, v);
    }

    putchar('\n');
    CircleLinkListTraverse(&list, traverse);
    putchar('\n');

    CircleLinkListDestroy(&list, destroy);
    return 0;
}

