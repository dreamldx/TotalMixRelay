#include "stdafx.h"
#include "Event.h"


Event::Event(TCHAR* name) {
	hEvent = CreateEvent(
		NULL,		// default security attributes
		FALSE,      // manual-reset event
		FALSE,      // initial state is nonsignaled
		name		// object name
	);
}

Event::~Event() {
}

void Event::Set() {
	SetEvent(hEvent);
}

DWORD Event::Wait() {
	DWORD dwWaitResult = WaitForSingleObject(
		hEvent,			// event handle
		INFINITE);		// indefinite wait
	switch (dwWaitResult) {
	case WAIT_OBJECT_0:
		return TRUE;
	default:
		return FALSE;
	}
}
