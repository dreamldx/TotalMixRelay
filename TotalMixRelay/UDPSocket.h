#pragma once
#pragma comment(lib, "Ws2_32.lib")

class UDPSocket {
private:
	SOCKET so;
	WSADATA wsa;
	struct sockaddr_in si_self, si_other;
public:
	UDPSocket();
	~UDPSocket();

	void Open(char* ipAddrStr, int localPort, int port);
	void Send(char* message, int size);
	int Recieve(char* message, int size);
};

