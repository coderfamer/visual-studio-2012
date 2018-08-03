#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND		hwnd;
	MSG			msg;
	WNDCLASS	wndclass;

	//λ���
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	//���ڹ��̣� �ú��������ݸ����л��ڸô����ഴ���Ĵ��ڵ�������Ϣ
	wndclass.lpfnWndProc = WndProc;
	//��������ֶ���������ṹ��windows�ڲ�ά���Ĵ��ڽṹ��Ԥ��һЩ����Ŀռ�
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	//Ӧ�ó����ʵ�����
	wndclass.hInstance = hInstance;
	//Ϊ���л��ڸô����趨һ��ͼ��
	//�����windowsԤ����ͼ�꣬��һ����������ΪNULL
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//�������ָ��
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	//���ñ�����ɫ
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//ָ��������Ĳ˵�
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	//������� registerclass ��ע�ᴰ����
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT"),
			szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName,//����������
		TEXT("The hello Program"),//���ڱ���
		WS_OVERLAPPEDWINDOW,//���ڷ��
		CW_USEDEFAULT,//��ʼX����
		CW_USEDEFAULT,//��ʼY����
		CW_USEDEFAULT,//��ʼX����ߴ�
		CW_USEDEFAULT,//��ʼY����ߴ�
		NULL,//�����ھ��
		NULL,//���ڲ˵����
		hInstance,//����ʵ�����
		NULL);//��������

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
} 

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	switch (message)
	{
	case WM_CREATE:
		//PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);

		DrawText(hdc, TEXT("Hello, Window!!"), -1, &rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}