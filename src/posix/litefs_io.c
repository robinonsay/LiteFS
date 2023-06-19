#include "litefs_io.h"
#include <stdio.h>
#include <stdarg.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void LiteFS_PrintF(const char* cPtrFormat, ...)
{
    va_list args;
    va_start(args, cPtrFormat);
    vprintf(cPtrFormat, args);
    va_end(args);
}

void LiteFS_PrintErr(const char* cPtrFormat, ...)
{
    va_list args;
    va_start(args, cPtrFormat);
    vfprintf(stderr, cPtrFormat, args);
    va_end(args);
}


int LiteFS_OpenDir(LITEFS_DIR_T* dir, const char* cPtrDirPath)
{
    int iStatus = 0;
    dir->path = cPtrDirPath;
    dir->vPtrDir = opendir(cPtrDirPath);
    if(dir->vPtrDir == NULL)
    {
        perror("ERROR: Could not open directory");
        iStatus = -1;
    }
    return iStatus;
}

int LiteFS_YieldFile(LITEFS_DIR_T* dir, char* cPtrBuffer, int32 iBuffSize)
{
    DIR* ptrDir = (DIR*) dir->vPtrDir;
    int iStatus = -1;
    struct dirent* entry = NULL;
    struct stat fStat = {0};
    entry = readdir(ptrDir);
    if(entry != NULL)
    {
        snprintf(cPtrBuffer, iBuffSize, "%s/%s", dir->path, entry->d_name);
        if(stat(cPtrBuffer, &fStat) == 0)
        {
            if(S_ISREG(fStat.st_mode))
            {
                iStatus = 1;
            }
            else
            {
                iStatus = 0;
            }
        }
    }
    return iStatus;
}

void LiteFS_CloseDir(LITEFS_DIR_T* dir)
{
    DIR* ptrDir = (DIR*) dir->vPtrDir;
    if(ptrDir)
    {
        closedir(ptrDir);
    }
}

