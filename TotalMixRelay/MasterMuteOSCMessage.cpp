#include "stdafx.h"
#include "MasterMuteOSCMessage.h"


MasterMuteOSCMessage::MasterMuteOSCMessage(bool mute) {
	muteStatus = mute;
}


MasterMuteOSCMessage::~MasterMuteOSCMessage()
{
}

char * MasterMuteOSCMessage::GetName() {
	return "/1/mainDim";
}

int MasterMuteOSCMessage::GetNameSize() {
	return 10;
}

char * MasterMuteOSCMessage::GetType() {
	return ",f";
}

int MasterMuteOSCMessage::GetTypeSize() {
	return 2;
}

char * MasterMuteOSCMessage::GetValue() {
	unsigned char* buf = (unsigned char*)&muteStatus;
	long r = (buf[3] << 0) | (buf[2] << 8) | (buf[1] << 16) | (buf[0] << 24);

	return (char*)&r;
}

int MasterMuteOSCMessage::GetValueSize()
{
	return 4;
}