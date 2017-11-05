#include "stdafx.h"
#include "Thread.h"


Thread::Thread() {
}

Thread::~Thread() {
}

void Thread::Create() {
	handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread::threadProc, this, 0, &id);
}

void Thread::Initialize() {
}

DWORD Thread::Run() {
	return 0;
}

void Thread::Shutdown() {
}

DWORD Thread::threadProc(LPVOID lpThreadParameter) {
	Thread* thisThread = (Thread*)lpThreadParameter;
	thisThread->Initialize();
	DWORD r = thisThread->Run();
	thisThread->Shutdown();

	return r;
}
