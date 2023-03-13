#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

void Test(HWND  Hwnd)
{

	while (true)
	{

		ShowWindow(Hwnd, SW_RESTORE);
	}

}
void TypeString(HWND hwnd, LPCSTR str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		SendMessage(hwnd, WM_CHAR, str[i], 0);
		Sleep(50);
	}
}


int main()
{
	// ��ȡ���ھ��
	HWND hwnd = FindWindow(L"TianLongBaBuHJ WndClass", 0);



	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Test, hwnd, 0, 0);

	// Type the account
	TypeString(hwnd, "gsfc412560");

	// Press Tab to move to the password field
	keybd_event(VK_TAB, 0, 0, 0);
	keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);

	// Type the password
	TypeString(hwnd, "edr123456");

	// Press Enter to submit the login
	keybd_event(VK_RETURN, 0, 0, 0);
	keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);









	return 0;
}


