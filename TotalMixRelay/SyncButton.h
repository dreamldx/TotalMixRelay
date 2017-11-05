#pragma once
#include "Button.h"


class SyncButton :
	public Button {
	
public:
	SyncButton();
	~SyncButton();

	void Message(WPARAM wParam, LPARAM lParam);
};

