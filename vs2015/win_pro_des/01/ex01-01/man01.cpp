#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

//sz��ʾ�����β���ַ���
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{

	MessageBox(NULL, TEXT("Hello win32"), TEXT("Hellomsg"), MB_CANCELTRYCONTINUE );
	//cout << "hello " << endl;
	return 0;
}

/*
int WINAPI WinMain(
	//ʵ�����
	_In_ HINSTANCE hInstance,
	//ͨ��ΪNULL
	_In_ HINSTANCE hPrevInstance,
	//���г����������
	_In_ LPSTR     lpCmdLine,
	//֪��������������ʾ
	_In_ int       nCmdShow
);
*/