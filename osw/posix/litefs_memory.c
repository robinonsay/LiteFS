#include "litefs_memory.h"

#include <stdlib.h>
#include <string.h>

void* LiteFS_Malloc(uint32 uiSize)
{
    return malloc(uiSize);
}

void LiteFS_Free(void* vPtrMemory)
{
    free(vPtrMemory);
}

void* LiteFS_Memset(void* vPtrDest, uint8 iVal, int32 iSize)
{
    return memset(vPtrDest, iVal, iSize);
}

void* LiteFS_MemCpy(void* restrict vPtrDest, const void *restrict vPtrSrc, int32 iSize)
{
    return memcpy(vPtrDest, vPtrSrc, iSize);
}


