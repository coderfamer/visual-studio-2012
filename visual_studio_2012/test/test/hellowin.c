#include <windows.h>

LRESULT CALLBACK Wndproc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain3(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
				   PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppname[] = TEXT("hellowin");
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;

	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc	= Wndproc;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hInstance		= hInstance;
	wndclass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);//����ͼ�꣬������ʹ��
	wndclass.hCursor		= LoadCursor(NULL, IDC_ARROW);//��������꣬������ʹ��
	wndclass.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);//��ȡһ��ͼ�ζ���
	wndclass.lpszMenuName	= NULL;
	wndclass.lpszClassName	= szAppname;

	if (!RegisterClass(&wndclass))//ΪӦ�ó��򴰿�ע��һ��������
	{
		MessageBox(NULL, TEXT("this program require windows nt!"),//��ʾ��Ϣ��
			szAppname, MB_ICONERROR);
		return 0;
	}
	/*
	CreateWindowA(lpClassName, lpWindowName, dwStyle, x, y,\
	nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)\
	CreateWindowExA(0L, lpClassName, lpWindowName, dwStyle, x, y,\
	nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
	#define CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y,\
	nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)\
	CreateWindowExW(0L, lpClassName, lpWindowName, dwStyle, x, y,\
	nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
	*/
	hwnd = CreateWindow(szAppname,//���ڴ����ഴ��һ������
		TEXT("the hello program"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	ShowWindow(hwnd, iCmdShow);//����Ļ����ʾ����
	UpdateWindow(hwnd);//ָʾ���ڶ���������ػ�

	while (GetMessage(&msg, NULL, 0, 0))//����Ϣ���л�ȡ��Ϣ
	{
		TranslateMessage(&msg);//����һЩ������Ϣ
		DispatchMessage(&msg);//����Ϣ�������ڹ���
	}


	return msg.wParam;
}

LRESULT CALLBACK Wndproc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	switch (message)
	{
	case WM_CREATE:
		//PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);//���������ļ�
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);//��ȡ���ڿͻ����ĳߴ�
		DrawText(hdc, TEXT("hello, window 98"), -1, &rect, 
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);//��ʾһ���ı��ַ���
		EndPaint(hwnd, &ps);//�������ڻ���
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);//���Ƴ���Ϣ������Ϣ����
		return 0;
	}
	return DefWindowProc(hwnd, message, wparam, lparam);//ִ��Ĭ�ϵ���Ϣ����
}