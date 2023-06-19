#include "litefs_dtypes.h"
#include "litefs_io.h"
#include "litefs_config.h"

static struct GLOBALS_TAG
{
    bool bIsRootProcess;
    LITEFS_CONFIG_T config;
} gGlobals = {0};

int main(int argc, char const *argv[])
{
    void* app_handle = NULL;
    uint32 (*AppInit)() = NULL;
    uint32 (*AppMain)() = NULL;
    void (*AppExit)() = NULL;
    char* cPtrLdrErr = NULL;
    int iConfigFD = -1;
    uint8 uiNumApps =;
    char cPtrArrAppPaths[MAX_NUM_APPS][MAX_PATH_LEN] = {0};
    uint16 uiIndex = 0;
    int32 iStatus = 0;

    if(argc == 1)
    {
        iConfigFD = LiteFS_Open("config.o", FLAG_RDONLY);
    }
    else if(argc == 2)
    {
        iConfigFD = LiteFS_Open(argv[1], FLAG_RDONLY);
    }
    else
    {
        goto exit;
    }
    if(iConfigFD == -1)
    {
        LiteFS_PError("ERROR: Could not open config");
        goto exit;
    }
    do
    {
        iStatus = LiteFS_Read(iConfigFD, &gGlobals.config, sizeof(gGlobals.config));
    } while(iStatus == -2);
    if(iStatus == -1)
    {
        LiteFS_PError("ERROR: Could not read config");
    }
    LiteFS_PrintF("Mission: %s\n", gGlobals.config.cPtrMissionName);
    LiteFS_PrintF("App Prefix: %s\n", gGlobals.config.cPtrAppPrefix);
exit:
    if(iConfigFD != -1)
    {
        LiteFS_Close(iConfigFD);
    }
    /* code */
    return 0;
}
