#pragma once
class Thread {
	DWORD id;
	HANDLE handle;
public:
	Thread();
	~Thread();

	void Create();
	virtual void Initialize();
	virtual DWORD Run();
	virtual void Shutdown();

	static DWORD threadProc(LPVOID lpThreadParameter);
};

