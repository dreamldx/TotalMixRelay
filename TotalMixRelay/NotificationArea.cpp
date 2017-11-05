#include "stdafx.h"
#include "NotificationArea.h"
#include <Strsafe.h>
#include "Resource.h"
#include "UserDef.h"

extern HINSTANCE hInst;

NotificationArea::NotificationArea() {
}

NotificationArea::~NotificationArea() {
}

void NotificationArea::Create(HWND hWnd) {
	nid.cbSize = sizeof(nid);
	nid.hWnd = hWnd;
	nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
	nid.uCallbackMessage = WM_USER_SHELLICON;

	StringCchCopy(nid.szTip, ARRAYSIZE(nid.szTip), L"TotalMix Fx Synchronize");
	LoadIconMetric(hInst, MAKEINTRESOURCE(IDI_TRAY), LIM_SMALL, &(nid.hIcon));

	Shell_NotifyIcon(NIM_ADD, &nid) ? S_OK : E_FAIL;

	hMenu = LoadMenu(NULL, MAKEINTRESOURCE(IDR_POPUPMENU_TRAY));
	hMenu = GetSubMenu(hMenu, 0);
}

void NotificationArea::Popup(HWND hWnd) {
	POINT curPos;
	GetCursorPos(&curPos);

	TrackPopupMenu(hMenu, TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_BOTTOMALIGN, curPos.x, curPos.y, 0, hWnd, NULL);
}

void NotificationArea::Shutdown()
{
}
