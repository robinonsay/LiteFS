#include "litefs_io.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

void LiteFS_PrintF(const char* cPtrFormat, ...)
{
    va_list args;
    va_start(args, cPtrFormat);
    vprintf(cPtrFormat, args);
    va_end(args);
}

void LiteFS_PError(const char* cPtrStr)
{
    perror(cPtrStr);
}

int LiteFS_Open(const char* restrict cPtrPathname, int iFlags)
{
    return open(cPtrPathname, iFlags);
}

int32 LiteFS_Read(int iFD, void* vPtrBuffer, uint32 count)
{
    int32 iRet = read(iFD, vPtrBuffer, count);
    if(iRet == -1 && errno == EINTR)
    {
        iRet = READ_INTR;
    }
    return iRet;
}

int32 LiteFS_Write(int iFD, void* vPtrBuffer, uint32 count)
{
    return write(iFD, vPtrBuffer, count);
}

int LiteFS_Close(int iFD)
{
    return close(iFD);
}

int64 LiteFS_FileSize(int iFD)
{
    struct stat statFile = {0};
    int32 iFSize = -1;
    if(fstat(iFD, &statFile) == -1)
    {
        goto exit;
    }
    iFSize = statFile.st_size;
exit:
    return iFSize;
}

