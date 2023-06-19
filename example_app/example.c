#include "litefs.h"
#include "litefs_io.h"

uint32 LiteFS_AppInit()
{
    LiteFS_PrintF("Example Init\n");
    return 0;
}

uint32 LiteFS_AppMain()
{
    LiteFS_PrintF("Example Main\n");
    return 0;
}

void LiteFS_AppExit()
{
    LiteFS_PrintF("Example Exit\n");
}

