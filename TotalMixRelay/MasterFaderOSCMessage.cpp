#include "stdafx.h"
#include "MasterFaderOSCMessage.h"
#include "intrin.h"


MasterFaderOSCMessage::MasterFaderOSCMessage(float v) {
	vol = v;
}

MasterFaderOSCMessage::~MasterFaderOSCMessage() {
}

char * MasterFaderOSCMessage::GetName() {
	return "/1/mastervolume";
}

int MasterFaderOSCMessage::GetNameSize() {
	return 15;
}

char * MasterFaderOSCMessage::GetType() {
	return ",f";
}

int MasterFaderOSCMessage::GetTypeSize() {
	return 2;
}

char * MasterFaderOSCMessage::GetValue() {
	unsigned char* buf = (unsigned char*)&vol;
	long r = (buf[3] << 0) | (buf[2] << 8) | (buf[1] << 16) | (buf[0] << 24);

	return (char*) &r;
}

int MasterFaderOSCMessage::GetValueSize()
{
	return 4;
}
