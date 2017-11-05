#pragma once
class Button
{
private:
	HWND hwndButton = NULL;
public:
	Button();
	~Button();

	void Create(HWND hWnd, TCHAR* text, TCHAR* note);
	virtual void Message(WPARAM wParam, LPARAM lParam);
};

