#pragma once
class Event {
	HANDLE hEvent;
public:
	Event(TCHAR* name);
	~Event();

	void Set();
	DWORD Wait();
};

