#ifndef LITEFS_IO_H
#define LITEFS_IO_H

#include "litefs_dtypes.h"

typedef struct LITEFS_DIR_TAG
{
    void* vPtrDir;
    const char* path;
}
LITEFS_DIR_T;

void LiteFS_PrintF(const char* cPtrFormat, ...);
void LiteFS_PrintErr(const char* cPtrFormat, ...);
int LiteFS_OpenDir(LITEFS_DIR_T* dir, const char* cPtrDirPath);
int LiteFS_YieldFile(LITEFS_DIR_T* dir, char* cPtrBuffer, int32 iBuffSize);
void LiteFS_CloseDir(LITEFS_DIR_T* dir);

#endif
