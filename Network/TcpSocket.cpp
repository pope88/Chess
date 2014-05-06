#include "Config.h"
#include "TcpSocket.h"
#include "Utils.h"

#ifndef _WIN32
#include <errno.h>
#endif

namespace Network
{

TcpSocket::TcpSocket(): Socket(AF_INET, SOCK_STREAM, 0), _pendClose(false)
{
}

TcpSocket::TcpSocket( socket_t fd ): Socket(fd), _pendClose(false)
{
}

bool TcpSocket::connect( const char * addr, UInt16 port )
{
	UInt32 ipaddr = resolveAddress(addr);
	if(ipaddr == 0xFFFFFFFF)
		return false;
	return connect(ipaddr, port);
}

bool TcpSocket::connect( UInt32 ipaddr, UInt16 port )
{
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = htonl(ipaddr);
	saddr.sin_port = htons(port);
	if(::connect(_fd, (const struct sockaddr *)&saddr, sizeof(saddr)) == SOCKET_ERROR && (lastErr() != EINPROGRESS && lastErr() != EWOULDBLOCK))
		return false;
	return true;
}

int TcpSocket::read( void * buf, int len )
{
#ifdef _WIN32
	return ::recv(_fd, (char *)buf, len, 0);
#else
	return ::read(_fd, buf, len);
#endif
}

int TcpSocket::write( const void * buf, int len )
{
#ifdef _WIN32
	return ::send(_fd, (const char *)buf, len, 0);
#else
	return ::write(_fd, buf, len);
#endif
}

TcpListener::TcpListener( const char * addr, UInt16 port )
{
	if(!bind(addr, port))
		throw std::exception(/*"Unable to bind to address"*/);
	if(!listen(511))
		throw std::exception(/*"Unable to listen on port"*/);
}

TcpListener::TcpListener( UInt16 port )
{
	if(!bind(port))
		throw std::exception(/*"Unable to bind to address"*/);
	if(!listen(511))
		throw std::exception(/*"Unable to listen on port"*/);
}

TcpSocket * TcpListener::accept()
{
	struct sockaddr_in addr = {0};
	socklen_t l = sizeof(addr);
	socket_t sock = ::accept(_fd, (struct sockaddr *)&addr, &l);
	if(sock < 0)
		return NULL;
	return new(std::nothrow) TcpSocket(sock);
}

}
