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
	
	SetCursorPos(1400, 22);  //�������λ��
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

	return 0;
}

//���ھ��: ���Windowsϵͳ��ÿһ�����ڵ�Ψһ��ʶ��
	//���ִ���  ��� ID
	//HWND hwnd; //������һ�����ڵ�ID
	//hwnd = FindWindow(L"TXGuiFoundation", L"����С��");
	//
	//int i = 0;
	//for (i = 0; i < 300; i++)
	//{
	//	SendMessage(hwnd, WM_PASTE, 0, 0);  //ĳһ�����ڷ���ָ��
	//	SendMessage(hwnd, WM_KEYDOWN, VK_RETURN, 0); //

	//}


	//�ڶ���
//HWND qqHwnd;
//
//int  i = 0;
//
//for (; i < 6; i++)
//{
//	qqHwnd = FindWindow(L"TXGuiFoundation", L"QQ");
//	SetForegroundWindow(qqHwnd); //��QQ����������Ϊ��ǰ  �߼��ϵ���ǰ �����������ϵ�
//
//	//ģ�ⰴ��
//
//	PressKey(VK_TAB);     //TAB - ��ϵ�˳������߿�          /*keybd_event(VK_TAB, 0, 0, 0);   keybd_event(VK_TAB, 0, 2, 0); */
//	PressKey(VK_TAB);      //TAB - �������������߿�         /*keybd_event(VK_TAB, 0, 0, 0);  keybd_event(VK_TAB, 0, 2, 0);*/
//
//	while (1)
//	{
//		//һֱ�� �� �س� ֱ������һ���Ի���
//		PressKey(VK_DOWN);
//		PressKey(VK_RETURN);
//
//		//��һ���Ի���
//		if (GetForegroundWindow() != qqHwnd)
//		{
//			break;
//		}
//	}
//
//
//	PressKey1(VK_CONTROL, 'V');  //ctrl + V  ճ��
//
//	PressKey(VK_RETURN);  // return    ����
//	PressKey(VK_ESCAPE);  // ESC       �˳�

	//1��ģ��ʲô��   ���ܼ���VK_SHIFT  VK_TAB  VK_RETURN   ���ּ�, 0-9
	//2������ 0
	//3��ģ��ʲô����  ����0  ����2
	//TAB TAB DOWN RETURN DOWN RETURN DOWN RETURN
//}
//��Ǹ��������