#include "litefs_loader.h"
#include <dlfcn.h>
#include <stdio.h>

#define LITEFS_API_NAME ("api")

int8 LiteFS_LoadApp(LITEFS_APP_T** app, char* cPtrAppPath)
{
    int8 iStatus = 0;
    void* vPtrHandle;
    vPtrHandle = dlopen(cPtrAppPath, RTLD_LAZY);
    if(vPtrHandle == NULL)
    {
        iStatus = -1;
        fprintf(stderr, "%s\n", dlerror());
        goto exit;
    }
    *app = (LITEFS_APP_T*) dlsym(vPtrHandle, LITEFS_API_NAME);
exit:
    if(vPtrHandle)
    {
        dlclose(vPtrHandle);
    }
    return iStatus;
}
