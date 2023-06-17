#include "litefs_loader.h"
#include <dlfcn.h>

void* LiteFS_DynLibOpen(const char* filename, int flags)
{
    return dlopen(filename, flags);
}

int LiteFS_DynLibClose(void* handle)
{
    return dlclose(handle);
}

void* LiteFS_SymLoad(void* restrict handle, const char* restrict symbol)
{
    return dlsym(handle, symbol);
}
