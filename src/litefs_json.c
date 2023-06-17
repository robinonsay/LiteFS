#include "litefs_json.h"
#include "litefs_io.h"

int8 LiteFS_JsonInitFromFD(JSON_OBJ_T* obj, int iFD)
{
    int64 iFSize = LiteFS_FileSize(iFD);
    char cPtrBuffer[iFSize];
    int32 iStatus = 0;
    do
    {
        iStatus = LiteFS_Read(iFD, cPtrBuffer, iFSize);
    } while(iStatus == -2);
    if(iStatus == -1)
    {
        LiteFS_PError("ERROR: Could not read JSON File Descriptor");
    }
    LiteFS_PrintF("Read JSON Success\n");
    return 0;
}

int8 LiteFS_JsonWriteToFD(JSON_OBJ_T* obj, int iFD)
{
    return 0;

}

JSON_OBJ_T* LiteFS_JsonGetObj(JSON_OBJ_T* obj, char* cPtrKey)
{
    return 0;

}
