#include "stdafx.h"
#include "Button.h"
#include "UserDef.h"


Button::Button() {
}


Button::~Button() {
}

void Button::Create(HWND hWnd, TCHAR* text, TCHAR* note) {
	hwndButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"OK",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_FLAT | BS_CENTER,  // Styles 
		10,         // x position 
		10,         // y position 
		200,        // Button width
		60,        // Button height
		hWnd,     // Parent window
		(HMENU)IDC_BTN_SYNC,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		0);      // Pointer not needed.

	SendMessage(hwndButton, WM_SETTEXT, 0, (LPARAM) text);
	SendMessage(hwndButton, BCM_SETNOTE, 0, (LPARAM) note);
	SetWindowLongPtr(hwndButton, GWLP_USERDATA, (LONG_PTR) this);
}

void Button::Message(WPARAM wParam, LPARAM lParam) {
}
