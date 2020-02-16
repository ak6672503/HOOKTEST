// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"
#include <cstddef>

#pragma data_seg("MySec")
HWND g_hWnd=NULL;
#pragma data_set()

// 当使用预编译的头时，需要使用此源文件，编译才能成功。
HHOOK g_hKeyboard = NULL;
HHOOK g_hMouse = NULL;
//鼠标钩子过程
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
	return 1;
}

LRESULT CALLBACK KeyboardProc(int code, WPARAM wParam, LPARAM lParam) {


	if (VK_F2 == wParam) {
		::SendMessage(g_hWnd, WM_CLOSE, 0, 0);
		UnhookWindowsHookEx(g_hKeyboard);
		UnhookWindowsHookEx(g_hMouse);
	}
	return 1;
}


//安装鼠标钩子过程函数
void SetHook(HWND hwnd) {
	g_hWnd = hwnd;

	g_hMouse = SetWindowsHookEx(WH_MOUSE, MouseProc, GetModuleHandle(L"Hook"), 0);

	g_hKeyboard = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, GetModuleHandle(L"Hook"), 0);


}


