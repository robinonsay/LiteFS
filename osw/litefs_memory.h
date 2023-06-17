#ifndef LITEFS_MEMORY_H
#define LITEFS_MEMORY_H

#include "litefs_dtypes.h"

void* LiteFS_Malloc(uint32 uiSize);
void LiteFS_Free(void* vPtrMemory);
void* LiteFS_Memset(void* vPtrDest, uint8 iVal, int32 iSize);
void* LiteFS_MemCpy(void* restrict vPtrDest, const void *restrict vPtrSrc, int32 iSize);

#endif
