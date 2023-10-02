#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h> 

void PressKey(BYTE vkey)
{
	keybd_event(vkey, 0, 0, 0);
	Sleep(50);
	keybd_event(vkey, 0, 2, 0);
	Sleep(50);
}

//ctrl + v
void PressKey1(BYTE vkey1, BYTE vkey2)
{
	keybd_event(vkey1, 0, 0, 0);
	Sleep(50);
	keybd_event(vkey2, 0, 0, 0);
	Sleep(50);
	keybd_event(vkey2, 0, 2, 0);
	Sleep(50);
	keybd_event(vkey1, 0, 2, 0);
	Sleep(50);
}

int main()
{
	
	SetCursorPos(1400, 22);  //设置鼠标位置
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

	return 0;
}

//窗口句柄: 标记Windows系统中每一个窗口的唯一标识符
	//区分窗口  编号 ID
	//HWND hwnd; //定义了一个窗口的ID
	//hwnd = FindWindow(L"TXGuiFoundation", L"快乐小子");
	//
	//int i = 0;
	//for (i = 0; i < 300; i++)
	//{
	//	SendMessage(hwnd, WM_PASTE, 0, 0);  //某一个窗口发送指令
	//	SendMessage(hwnd, WM_KEYDOWN, VK_RETURN, 0); //

	//}


	//第二种
//HWND qqHwnd;
//
//int  i = 0;
//
//for (; i < 6; i++)
//{
//	qqHwnd = FindWindow(L"TXGuiFoundation", L"QQ");
//	SetForegroundWindow(qqHwnd); //把QQ主界面设置为最前  逻辑上的最前 而不是物理上的
//
//	//模拟按键
//
//	PressKey(VK_TAB);     //TAB - 联系人出现虚线框          /*keybd_event(VK_TAB, 0, 0, 0);   keybd_event(VK_TAB, 0, 2, 0); */
//	PressKey(VK_TAB);      //TAB - 好友栏出现虚线框         /*keybd_event(VK_TAB, 0, 0, 0);  keybd_event(VK_TAB, 0, 2, 0);*/
//
//	while (1)
//	{
//		//一直按 下 回车 直到出现一个对话框
//		PressKey(VK_DOWN);
//		PressKey(VK_RETURN);
//
//		//打开一个对话框
//		if (GetForegroundWindow() != qqHwnd)
//		{
//			break;
//		}
//	}
//
//
//	PressKey1(VK_CONTROL, 'V');  //ctrl + V  粘贴
//
//	PressKey(VK_RETURN);  // return    发送
//	PressKey(VK_ESCAPE);  // ESC       退出

	//1、模拟什么键   功能键：VK_SHIFT  VK_TAB  VK_RETURN   数字键, 0-9
	//2、扯淡 0
	//3、模拟什么动作  按下0  弹起2
	//TAB TAB DOWN RETURN DOWN RETURN DOWN RETURN
//}
//抱歉，发错了