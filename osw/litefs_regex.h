#ifndef LITEFS_REGEX_H
#define LITEFS_REGEX_H

#include "litefs_dtypes.h"

typedef struct LITEFS_REGEX_TAG LITEFS_REGEX_T;
typedef struct LITEFS_REGEX_MATCH_TAG LITEFS_REGEX_MATCH_T;

int LiteFS_RegCmp(LITEFS_REGEX_T* regexPtrPreg, const char* cPtrRegex);
int LiteFS_RegExec(LITEFS_REGEX_T* regexPtrPreg, const char* cPtrString, int32 iNMatch, LITEFS_REGEX_MATCH_T* ptrMatches);
int32 LiteFS_RegError(int errcode, LITEFS_REGEX_T* regexPtrPreg, char* cPtrErrBuf, int32 iErrBuffSize);
void LiteFS_RegFree(LITEFS_REGEX_T* regexPtrPreg);

#endif
