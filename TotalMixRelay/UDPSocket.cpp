#include "stdafx.h"
#include "UDPSocket.h"


UDPSocket::UDPSocket() {
	WSAStartup(MAKEWORD(2, 2), &wsa);
}


UDPSocket::~UDPSocket() {
	WSACleanup();
}

void UDPSocket::Open(char* ipAddrStr, int localPort, int remotePort) {
	so = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	memset((char *)&si_self, 0, sizeof(si_other));
	si_self.sin_family = AF_INET;
	si_self.sin_port = htons(localPort);
	si_self.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	int r = bind(so, (struct sockaddr *)&si_self, sizeof(si_self));
	int err = WSAGetLastError();

	memset((char *)&si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(remotePort);
	si_other.sin_addr.S_un.S_addr = inet_addr(ipAddrStr);
}

void UDPSocket::Send(char* message, int size) {
	sendto(so, message, size, 0, (struct sockaddr *) &si_other, sizeof(si_other));
}

int UDPSocket::Recieve(char * message, int size)
{
	struct sockaddr_in sockaddr_recv;
	memset((char *)&sockaddr_recv, 0, sizeof(sockaddr_recv));

	int sockaddr_size = 0, r=0;
	
	r = recvfrom(so, message, size, 0, NULL, NULL);

	int err = WSAGetLastError();
	
	return r;
}
