#include "stdafx.h"
#include "OSCController.h"
#include "MasterFaderOSCMessage.h"
#include "MasterMuteOSCMessage.h"


OSCController::OSCController() {
}

OSCController::~OSCController() {
}

void OSCController::Setup() {
	oscSocket.Open("127.0.0.1", 8001, 7001);

	sendThread = new OSCSendThread(&oscSocket);
	sendThread->Create();
	recvThread = new OSCRecvThread(&oscSocket, this);
	recvThread->Create();
}

void OSCController::SetMasterVolume(float val) {
	sendThread->AddOSCMessage(new MasterFaderOSCMessage(val));
}

void OSCController::SetMasterMute(bool muteStatus) {
	sendThread->AddOSCMessage(new MasterMuteOSCMessage(1));
}

void OSCController::OnOSCMessage(char * payload, int size) {
}
