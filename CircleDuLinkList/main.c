#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#include "CircleDuLinkList.h"

int main(int argc, char *argv[])
{
    CircleDuLinkList list;

    CircleDuLinkListInit(&list);

    return 0;
}

