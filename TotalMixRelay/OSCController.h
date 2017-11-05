#pragma once
#include "OSCThread.h"
#include "UDPSocket.h"
#include "OSCThread.h"

class OSCSendThread;
class OSCRecvThread;

class OSCController {
	UDPSocket oscSocket;
	OSCSendThread* sendThread;
	OSCRecvThread* recvThread;
public:
	OSCController();
	~OSCController();

	void Setup();

	void SetMasterVolume(float val);
	void SetMasterMute(bool muteStatus);
	void OnOSCMessage(char* payload, int size);
};
