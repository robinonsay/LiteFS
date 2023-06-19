#include "litefs_dtypes.h"
#include "litefs_config.h"
#include "litefs_io.h"
#include "litefs_memory.h"

#define MAX_APP_PATH    (1024)

static struct GLOBALS_TAG
{
    bool bIsRootProcess;
    LITEFS_CONFIG_T config;
} gGlobals = {0};

int main(int argc, char const *argv[])
{
    int32 iStatus = 0;
    LITEFS_DIR_T appDir = {0};
    char cPtrAppPath[MAX_APP_PATH] = {0};
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
        LiteFS_PrintErr("ERROR: Could not load config", gGlobals.config.cPtrAppPrefix);
        goto exit;
    }
    LiteFS_PrintF("Mission: %s\n", gGlobals.config.cPtrMissionName);
    LiteFS_PrintF("App Prefix: %s\n", gGlobals.config.cPtrAppPrefix);
    if(LiteFS_OpenDir(&appDir, gGlobals.config.cPtrAppPrefix) == -1)
    {
        LiteFS_PrintErr("ERROR: Could not Open App Directory: %s", gGlobals.config.cPtrAppPrefix);
        goto exit;
    }
    int iYieldStatus = 0;
    while((iYieldStatus = LiteFS_YieldFile(&appDir, cPtrAppPath, sizeof(cPtrAppPath))) != -1)
    {
        if(iYieldStatus == 1)
        {
            LiteFS_PrintF("App Path: %s\n", cPtrAppPath);
            LiteFS_Memset(cPtrAppPath, 0, sizeof(cPtrAppPath));
        }
    }
exit:

    LiteFS_CloseDir(&appDir);
    /* code */
    return iStatus;
}
