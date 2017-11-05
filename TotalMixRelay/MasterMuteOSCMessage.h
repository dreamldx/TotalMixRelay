#pragma once
#include "OSCMessage.h"
class MasterMuteOSCMessage :
	public OSCMessage {
	float muteStatus;
public:
	MasterMuteOSCMessage(bool mute);
	~MasterMuteOSCMessage();

	char* GetName();
	int GetNameSize();
	char* GetType();
	int GetTypeSize();
	char* GetValue();
	int GetValueSize();
};

