#ifndef LITEFS_LOADER_H
#define LITEFS_LOADER_H

void* LiteFS_DynLibOpen(const char* filename, int flags);
int LiteFS_DynLibClose(void* handle);
void* LiteFS_SymLoad(void* restrict handle, const char* restrict symbol);

#endif
