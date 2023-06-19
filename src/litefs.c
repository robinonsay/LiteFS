#include "litefs_dtypes.h"
#include "litefs_config.h"

static struct GLOBALS_TAG
{
    bool bIsRootProcess;
    LITEFS_CONFIG_T config;
} gGlobals = {0};

int main(int argc, char const *argv[])
{
    int32 iStatus = 0;

    if(argc == 1)
    {
        iStatus = LiteFS_LoadConfig(&gGlobals.config, "config.o");
    }
    else if(argc == 2)
    {
        iStatus = LiteFS_LoadConfig(&gGlobals.config, argv[1]);
    }
    else
    {
        goto exit;
    }
    if(iStatus == -1)
    {
        goto exit;
    }
    LiteFS_PrintF("Mission: %s\n", gGlobals.config.cPtrMissionName);
    LiteFS_PrintF("App Prefix: %s\n", gGlobals.config.cPtrAppPrefix);
exit:
    /* code */
    return iStatus;
}
