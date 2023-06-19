#ifndef LITEFS_MEMORY_H
#define LITEFS_MEMORY_H

#include "litefs_dtypes.h"

void* LiteFS_Malloc(int32 iSize);
void LiteFS_Free(void* vPtr);

#endif
