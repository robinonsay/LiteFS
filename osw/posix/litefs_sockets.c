#include "litefs_sockets.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int LiteFS_SocketInit(LITEFS_SOCKET_T* ptrSocket, LITEFS_SOCKET_DOMAIN domain, LITEFS_SOCKET_TYPE type, int protocol)
{
    ptrSocket->domain = domain;
    ptrSocket->type =type;
    ptrSocket->iFD = socket(domain, type, protocol);
    return ptrSocket->iFD;
}

int LiteFS_SocketBind(LITEFS_SOCKET_T* socket, LITEFS_SOCKET_ADDR_T* ptrSocketAddr)
{
    return bind(socket->iFD, (struct sockaddr *) ptrSocketAddr, sizeof(LITEFS_SOCKET_ADDR_T));
}

int LiteFS_SocketConnect(LITEFS_SOCKET_T* socket, LITEFS_SOCKET_ADDR_T* ptrSocketAddr)
{
    return connect(socket->iFD, (struct sockaddr *) ptrSocketAddr, sizeof(LITEFS_SOCKET_ADDR_T));
}

int LiteFS_SocketListen(LITEFS_SOCKET_T* socket, int iBackLog)
{
    return listen(socket->iFD, iBackLog);
}

int LiteFS_SocketAccept(LITEFS_SOCKET_T* socket, LITEFS_SOCKET_ADDR_T* ptrFromAddr)
{
    socklen_t length;
    return accept(socket->iFD, (struct sockaddr *) ptrFromAddr, &length);
}

int32 LiteFS_Send(LITEFS_SOCKET_T* socket, void* vPtrBuffer, uint32 uiLen, int iFlags)
{
    return send(socket->iFD, vPtrBuffer, uiLen, iFlags);
}

int32 LiteFS_SendTo(LITEFS_SOCKET_T* socket, void* vPtrBuffer, uint32 uiLen, int iFlags, LITEFS_SOCKET_ADDR_T* ptrToAddr)
{
    return sendto(socket->iFD, vPtrBuffer, uiLen, iFlags, (struct sockaddr *) ptrToAddr, sizeof(LITEFS_SOCKET_ADDR_T));
}

int32 LiteFS_Recv(LITEFS_SOCKET_T* socket, void* vPtrBuffer, uint32 uiLen, int iFlags, LITEFS_SOCKET_ADDR_T* ptrToAddr)
{
    return recv(socket->iFD, vPtrBuffer, uiLen, iFlags);
}

int32 LiteFS_RecvFrom(LITEFS_SOCKET_T* socket, void* vPtrBuffer, uint32 uiLen, int iFlags, LITEFS_SOCKET_ADDR_T* ptrFromAddr)
{
    socklen_t length;
    return recvfrom(socket->iFD, vPtrBuffer, uiLen, iFlags, (struct sockaddr *) ptrFromAddr, &length);
}

int LiteFS_SocketClose(LITEFS_SOCKET_T* socket)
{
    return close(socket->iFD);
}

int LiteFS_SocketShutdown(LITEFS_SOCKET_T* socket, LITEFS_SOCKET_SHUTDOWN_HOW how)
{
    return shutdown(socket->iFD, how);
}

int LiteFS_GetInetAddr(LITEFS_SOCKET_ADDR_T* ptrSocketAddr, char* cPtrAddr, uint16 uiPort)
{
    ptrSocketAddr->domain = DOMAIN_INET;
    ptrSocketAddr->addr.inet.uiPort = htons(uiPort);
    return inet_aton(cPtrAddr, (struct in_addr*) &ptrSocketAddr->addr.inet.uiAddr);
}

int LiteFS_GetLocalAddr(LITEFS_SOCKET_ADDR_T* ptrSocketAddr, char* cPtrPath)
{
    ptrSocketAddr->domain = DOMAIN_LOCAL;
    strcpy(&ptrSocketAddr->addr.local, cPtrPath);
    return 0;
}
