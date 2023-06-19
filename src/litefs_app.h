#ifndef LITEFS_APP_H
#define LITEFS_APP_H

#include "litefs_dtypes.h"

typedef struct LITEFS_APP_TAG
{
    uint32 (*LiteFS_AppInit)();
    uint32 (*LiteFS_AppMain)();
    void (*LiteFS_AppExit)();
} LITEFS_APP_T;

#endif