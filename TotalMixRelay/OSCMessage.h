#pragma once
class OSCMessage {
private:
	char buffer[255];
	char buffer_size = 0;
	int GetQuadSize(int val);
	void Generate();
protected:
	virtual char* GetName() = 0;
	virtual int GetNameSize() = 0;
	virtual char* GetType() = 0;
	virtual int GetTypeSize() = 0;
	virtual char* GetValue() = 0;
	virtual int GetValueSize() = 0;
public:
	OSCMessage();
	~OSCMessage();

	char* GetByte();
	int Size();
};

