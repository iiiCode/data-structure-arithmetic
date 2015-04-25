#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#include "utils.h"
#include "CircleDuLinkList.h"

static void destroy(void *data)
{
    free(data);
}

static void traverse(void *data)
{
    printf("%d ", *(int *)data);
}

static int compare(const void *f, const void *s)
{
    return *(int *)f - *(int *)s;
}


int main(int argc, char *argv[])
{
    int i, *v;
    CircleDuLinkList list;

    srand(time(NULL));
    CircleDuLinkListInit(&list);

    for (i = 0; i < 20; i ++) {
        v = MALLOC(sizeof(int));
        *v = rand() % 90 + 10;
        CircleDuLinkListInsert(&list, v);
    }

    CircleDuLinkListTraverse(&list, traverse); putchar('\n');

    while(! CircleDuLinkListEmpty(&list)) {
        i = rand() % 90 + 10;

        v = CircleDuLinkListSearch(&list, &i, compare);
        if (v) {
            printf("Delete: %d\n", *v); 
            CircleDuLinkListDelete(&list, v, compare);
            CircleDuLinkListTraverse(&list, traverse); putchar('\n');
            FREE(v);
        }
    }

    CircleDuLinkListDestroy(&list, destroy);
    return 0;
}

