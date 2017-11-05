#include "stdafx.h"
#include "OSCMessage.h"


OSCMessage::OSCMessage() {

}

OSCMessage::~OSCMessage() {
}


int OSCMessage::GetQuadSize(int val)
{
	return ((val / 4) + 1) * 4;
}

void OSCMessage::Generate()
{
	int offset = 0;
	memset(buffer, 0, 255);

	memcpy(buffer + offset, GetName(), GetNameSize());
	offset += GetNameSize();
	offset = GetQuadSize(offset);

	memcpy(buffer + offset, GetType(), GetTypeSize());
	offset += GetTypeSize();
	offset = GetQuadSize(offset);

	memcpy(buffer + offset, GetValue(), GetValueSize());

	buffer_size = offset + GetValueSize();
}

char * OSCMessage::GetByte() {
	if (buffer_size == 0)
		Generate();
	return buffer;
}

int OSCMessage::Size() {
	if (buffer_size == 0)
		Generate();
	return buffer_size;
}

