#include "litefs_config.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

int8 LiteFS_LoadConfig(LITEFS_CONFIG_T* ptrConfig, const char* cPtrPath)
{
    int8 iStatus = 0;
    int iConfigFd = open(cPtrPath, O_RDONLY);
    if(iConfigFd == -1)
    {
        iStatus = -1;
        perror("ERROR: Could not open config file");
        goto exit;
    }
    int32 iBytesRead = 0;
    do
    {
        iBytesRead = read(iConfigFd, ptrConfig + iBytesRead, sizeof(LITEFS_CONFIG_T));
        if(iBytesRead == -1 && errno != EINTR)
        {
            iStatus = -1;
            perror("ERROR: Could not read from config file");
            goto exit;
        }
    } while (iBytesRead == -1 && errno == EINTR);
exit:    
    return iStatus;
}
