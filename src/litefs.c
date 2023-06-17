#include "litefs_dtypes.h"
#include "litefs_io.h"
#include "litefs_json.h"

static struct GLOBALS_TAG
{
    bool bIsRootProcess;
    char** cPtrArrAppNames;
} gGlobals = {0};

int main(int argc, char const *argv[])
{
    void* app_handle;
    uint32 (*AppInit)();
    uint32 (*AppMain)();
    void (*AppExit)();
    char* cPtrLdrErr;
    int iConfigJsonFD;
    uint8 uiNumApps;
    char cPtrArrAppPaths[MAX_NUM_APPS][MAX_PATH_LEN] = {0};
    uint16 uiIndex = 0;
    JSON_OBJ_T tConfigJson = {0};

    iConfigJsonFD = LiteFS_Open("config.json", FLAG_RDONLY);
    if(iConfigJsonFD == -1)
    {
        LiteFS_PError("ERROR: Could not open config.json");
        goto exit;
    }
    LiteFS_JsonInitFromFD(&tConfigJson, iConfigJsonFD);
exit:
    if(iConfigJsonFD != -1)
    {
        LiteFS_Close(iConfigJsonFD);
    }
    /* code */
    return 0;
}
