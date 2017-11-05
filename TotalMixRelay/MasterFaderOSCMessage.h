#pragma once
#include "OSCMessage.h"
class MasterFaderOSCMessage :
	public OSCMessage {
	float vol;
public:
	MasterFaderOSCMessage(float v);
	~MasterFaderOSCMessage();

	char* GetName();
	int GetNameSize();
	char* GetType();
	int GetTypeSize();
	char* GetValue();
	int GetValueSize();
};

