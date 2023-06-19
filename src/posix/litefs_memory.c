#include "litefs_memory.h"
#include <stdlib.h>
#include <string.h>

void* LiteFS_Malloc(int32 iSize)
{
    return malloc(iSize);   
}

void LiteFS_Free(void* vPtr)
{
    free(vPtr);
}

void LiteFS_Memset(void* vPtr, uint8 uiByte, uint32 uiSize)
{
    memset(vPtr, uiByte, uiSize);
}

