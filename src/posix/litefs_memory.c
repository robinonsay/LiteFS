#include "litefs_memory.h"
#include <stdlib.h>

void* LiteFS_Malloc(int32 iSize)
{
    return malloc(iSize);   
}

void LiteFS_Free(void* vPtr)
{
    free(vPtr);
}

