#ifndef LITEFS_JSON_H
#define LITEFS_JSON_H

#include "litefs_dtypes.h"

typedef enum JSON_TYPE_TAG
{
    JSON_NULL = 0,
    JSON_BOOLEAN = 1,
    JSON_NUMBER = 2,
    JSON_STRING = 3,
    JSON_ARRAY = 4,
    JSON_OBJECT = 5
} JSON_TYPE_T;

typedef struct JSON_OBJ_TAG
{
    JSON_TYPE_T type;
    union
    {
        bool bBoolean;
        float fNumber;
        char* cPtrString;
        struct
        {
            uint32 size;
            struct JSON_OBJ_TAG* values;
        } array;
        struct
        {
            uint32 size;
            char** cPtrKeys;
            struct JSON_OBJ_TAG* values;
        } obj;
    } as;
} JSON_OBJ_T;

int8 LiteFS_JsonInitFromFD(JSON_OBJ_T* obj, int iFD);
int8 LiteFS_JsonWriteToFD(JSON_OBJ_T* obj, int iFD);
JSON_OBJ_T* LiteFS_JsonGetObj(JSON_OBJ_T* obj, char* cPtrKey);

#endif
