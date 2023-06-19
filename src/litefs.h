#ifndef LITEFS_H
#define LITEFS_H

#include "litefs_dtypes.h"

#include "litefs_app.h"

uint32 LiteFS_AppInit();
uint32 LiteFS_AppMain();
void LiteFS_AppExit();

void LiteFS_Register();
#ifndef LITEFS_APP_CUSTOM_REGISTER
LITEFS_APP_T api = {0};
void LiteFS_Register()
{
    api.LiteFS_AppInit = LiteFS_AppInit;
    api.LiteFS_AppMain = LiteFS_AppMain;
    api.LiteFS_AppExit = LiteFS_AppExit;
}
#endif
#endif
