#ifndef LITEFS_LIST_H
#define LITEFS_LIST_H

typedef struct LITEFS_LIST_NODE_TAG
{
    void*   vPtrData;
    struct LITEFS_LIST_NODE_TAG* ptrNext;
    struct LITEFS_LIST_NODE_TAG* ptrPrev;
} LITEFS_LIST_NODE_T;

#endif
