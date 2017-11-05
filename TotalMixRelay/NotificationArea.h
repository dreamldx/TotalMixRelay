#pragma once
#pragma comment(lib, "Comctl32.lib")

class NotificationArea {
	NOTIFYICONDATA nid;
	HMENU hMenu;
public:
	NotificationArea();
	~NotificationArea();

	void Create(HWND hWnd);
	void Popup(HWND hWnd);
	void Shutdown();
};

