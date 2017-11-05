#pragma once
#include "Thread.h"
#include "UDPSocket.h"
#include "OSCMessage.h"
#include "Event.h"
#include "OSCController.h"

class OSCController;

class OSCSendThread :
	public Thread {
	UDPSocket* oscSocket;
	OSCMessage* currentMessage;
	Event* arrEvent;

public:
	OSCSendThread(UDPSocket* so);
	~OSCSendThread();

	void AddOSCMessage(OSCMessage* message);

	DWORD Run();
};

class OSCRecvThread :
	public Thread {
	UDPSocket* oscSocket;
	OSCController* controller;
public:
	OSCRecvThread(UDPSocket* so, OSCController* c);
	~OSCRecvThread();

	DWORD Run();
};