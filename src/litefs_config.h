#ifndef LITEFS_CONFIG_H
#define LITEFS_CONFIG_H

#define MAX_MISSION_NAME    (256)
#define MAX_PATH_LEN        (256)
#define SECRET_LENGTH       (32)

typedef struct LITEFS_CONFIG_TAG
{
    char cPtrMissionName[MAX_MISSION_NAME];
    char cPtrAppPrefix[MAX_PATH_LEN];
    char cPtrSecret[SECRET_LENGTH];
} LITEFS_CONFIG_T;

#endif
