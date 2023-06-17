#include "litefs_regex.h"
#include "regex.h"

struct LITEFS_REGEX_TAG
{
    regex_t regex;
};

struct LITEFS_REGEX_MATCH_TAG
{
    regmatch_t match;
};


int LiteFS_RegCmp(LITEFS_REGEX_T* regexPtrPreg, const char* cPtrRegex)
{
    return regcomp(&regexPtrPreg->regex, cPtrRegex, REG_EXTENDED);
}

int LiteFS_RegExec(LITEFS_REGEX_T* regexPtrPreg, const char* cPtrString, int32 iNMatch, LITEFS_REGEX_MATCH_T* ptrMatches)
{
    return regexec(&regexPtrPreg->regex, cPtrString, iNMatch, &ptrMatches->match, 0);
}

int32 LiteFS_RegError(int errcode, LITEFS_REGEX_T* regexPtrPreg, char* cPtrErrBuf, int32 iErrBuffSize)
{
    return regerror(errcode, &regexPtrPreg->regex, cPtrErrBuf, iErrBuffSize);
}

void LiteFS_RegFree(LITEFS_REGEX_T* regexPtrPreg)
{
    regfree(&regexPtrPreg->regex);
}

