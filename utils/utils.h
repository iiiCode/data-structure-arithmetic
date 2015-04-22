#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>

static inline void *MALLOC(size_t size)
{
    void *addr;

    if (! (addr = malloc(size))) {
        printf("malloc %u Bytes failed.\n", (unsigned int)size);
        exit(-1);
    }

    return addr;
}

#define FREE(ptr) \
    do { \
        free(ptr); \
        ptr = NULL; \
    } while(0)

#endif //_UTILS_H_
