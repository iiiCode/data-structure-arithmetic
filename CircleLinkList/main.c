#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#include "utils.h"
#include "CircleLinkList.h"

static int compare(const void *first, const void *second)
{
    return *(int *)first - *(int *)second;
}

static void traverse(const void *data)
{
    printf("%d\n", *(int *)data);
    sleep(1);
}

static void destroy(const void *data)
{
    void *_data = (void *)data;

    FREE(_data);
}

static void * do_traverse(void *args)
{
    CircleLinkListInfiniteTraverse(args, traverse);
    return NULL;
}

int main(int argc, char *argv[])
{
    int i, *v;
    pthread_t ptid;
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
#if 0
    while(! CircleLinkListEmpty(&list)) {
        i = rand() % 90 + 10;
        
        const int *v = CircleLinkListSearch(&list, &i, compare);

        if (v) {
            printf("Delete: %d\n", *v);
            CircleLinkListDelete(&list, v, compare);
            CircleLinkListTraverse(&list, traverse);
            putchar('\n');
            int *vv = (int *)v;
            FREE(vv);
        }
    }
#else
    pthread_create(&ptid, NULL, do_traverse, &list);
    pthread_join(ptid, NULL);
#endif

    CircleLinkListDestroy(&list, destroy);
    return 0;
}

