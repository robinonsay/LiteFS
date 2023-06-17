#ifndef LITEFS_STR_H
#define LITEFS_STR_H

#define FLAG_RDONLY        (0x0000)          /* open for reading only */
#define FLAG_WRONLY        (0x0001)          /* open for writing only */
#define FLAG_RDWR          (0x0002)          /* open for reading and writing */

#define FLAG_CREAT         (0x00000200)      /* create if nonexistant */
#define FLAG_TRUNC         (0x00000400)      /* truncate to zero length */
#define FLAG_EXCL          (0x00000800)      /* error if already exists */
#define FLAG_NONBLOCK      (0x00000004)      /* no delay */
#define FLAG_APPEND        (0x00000008)      /* set append mode */

#define READ_INTR          (-2)

#include "litefs_dtypes.h"

void LiteFS_PrintF(const char* cPtrFormat, ...);
void LiteFS_PError(const char* cPtrStr);
int LiteFS_Open(const char* restrict cPtrPathname, int iFlags);
int32 LiteFS_Read(int iFD, void* vPtrBuffer, uint32 count);
int32 LiteFS_Write(int iFD, void* vPtrBuffer, uint32 count);
int LiteFS_Close(int iFD);
int64 LiteFS_FileSize(int iFD);
#endif
