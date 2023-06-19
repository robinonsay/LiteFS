#ifndef LITEFS_SOCKETS_H
#define LITEFS_SOCKETS_H

#include "litefs_dtypes.h"

typedef enum LITEFS_SOCKET_DOMAIN_TAG
{
    DOMAIN_LOCAL = 1,
    DOMAIN_INET = 2,
} LITEFS_SOCKET_DOMAIN;

typedef enum LITEFS_SOCKET_TYPE_TAG
{
    SOCKET_STREAM = 1,
    SOCKET_DGRAM = 2,
    SOCKET_SEQPACKET = 5,
    SOCKET_RAW = 3,
    SOCKET_RDM = 4
} LITEFS_SOCKET_TYPE;

typedef enum LITEFS_SOCKET_SHUTDOWN_HOW_TAG
{
    SOCKET_SHUT_RD = 0,
    SOCKET_SHUT_WR = 1,
    SOCKET_SHUT_RDWR = 2
} LITEFS_SOCKET_SHUTDOWN_HOW;

typedef struct LITEFS_SOCKET_TAG
{
    int iFD;
    LITEFS_SOCKET_DOMAIN domain;
    LITEFS_SOCKET_TYPE type;
} LITEFS_SOCKET_T;

typedef struct LITEFS_SOCKET_ADDR_TAG
{
    LITEFS_SOCKET_DOMAIN domain;
    union
    {
        struct
        {
            uint16 uiPort;
            uint32 uiAddr;
        } inet;
        struct
        {
            char cPtrPath[108];
        } local;
    } addr;
} LITEFS_SOCKET_ADDR_T;

int LiteFS_SocketInit(LITEFS_SOCKET_T* socket, LITEFS_SOCKET_DOMAIN domain, LITEFS_SOCKET_TYPE type, int protocol);
int LiteFS_SocketBind(LITEFS_SOCKET_T* socket, LITEFS_SOCKET_ADDR_T* ptrSocketAddr);
int LiteFS_SocketConnect(LITEFS_SOCKET_T* socket, LITEFS_SOCKET_ADDR_T* ptrSocketAddr);
int LiteFS_SocketListen(LITEFS_SOCKET_T* socket, int iBackLog);
int LiteFS_SocketAccept(LITEFS_SOCKET_T* socket, LITEFS_SOCKET_ADDR_T* ptrFromAddr);
int32 LiteFS_Send(LITEFS_SOCKET_T* socket, void* vPtrBuffer, uint32 uiLen, int iFlags);
int32 LiteFS_SendTo(LITEFS_SOCKET_T* socket, void* vPtrBuffer, uint32 uiLen, int iFlags, LITEFS_SOCKET_ADDR_T* ptrToAddr);
int32 LiteFS_Recv(LITEFS_SOCKET_T* socket, void* vPtrBuffer, uint32 uiLen, int iFlags, LITEFS_SOCKET_ADDR_T* ptrToAddr);
int32 LiteFS_RecvFrom(LITEFS_SOCKET_T* socket, void* vPtrBuffer, uint32 uiLen, int iFlags, LITEFS_SOCKET_ADDR_T* ptrFromAddr);
int LiteFS_SocketClose(LITEFS_SOCKET_T* socket);
int LiteFS_SocketShutdown(LITEFS_SOCKET_T* socket, LITEFS_SOCKET_SHUTDOWN_HOW how);
int LiteFS_GetInetAddr(LITEFS_SOCKET_ADDR_T* ptrSocketAddr, char* cPtrAddr, uint16 uiPort);
int LiteFS_GetLocalAddr(LITEFS_SOCKET_ADDR_T* ptrSocketAddr, char* cPtrPath);

#endif
