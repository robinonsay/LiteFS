#include "litefs_io.h"
#include <stdio.h>
#include <stdarg.h>

void LiteFS_PrintF(const char* cPtrFormat, ...)
{
    va_list args;
    va_start(args, cPtrFormat);
    vprintf(cPtrFormat, args);
    va_end(args);
}
