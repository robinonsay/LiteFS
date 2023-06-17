#include "litefs_time.h"
#include <unistd.h>

unsigned int LiteFS_Sleep(unsigned int uiSeconds)
{
    return sleep(uiSeconds);
}
