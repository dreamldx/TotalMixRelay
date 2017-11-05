#include "stdafx.h"
#include "OSCThread.h"
#include <stdio.h>

OSCSendThread::OSCSendThread(UDPSocket* so) {
	arrEvent = new Event(L"OSCThreadArrialEvent");
	oscSocket = so;
}

OSCSendThread::~OSCSendThread() {
	delete arrEvent;
}

void OSCSendThread::AddOSCMessage(OSCMessage * message) {
	currentMessage = message;
	arrEvent->Set();
}

DWORD OSCSendThread::Run()
{
	while (1) {
		arrEvent->Wait();
		OSCMessage* tmpOSCMessage = currentMessage;
		currentMessage = NULL;
		if (tmpOSCMessage != NULL) {
			oscSocket->Send(tmpOSCMessage->GetByte(), tmpOSCMessage->Size());

			delete tmpOSCMessage;
			tmpOSCMessage = NULL;
		}
	}
	return 0;
}

OSCRecvThread::OSCRecvThread(UDPSocket* so, OSCController* c) {
	oscSocket = so;
	controller = c;
}

OSCRecvThread::~OSCRecvThread() {
}

DWORD OSCRecvThread::Run() {
	while (1) {
		char buffer[255];
		int s = oscSocket->Recieve(buffer, 255);
		controller->OnOSCMessage(buffer, s);
	}
}