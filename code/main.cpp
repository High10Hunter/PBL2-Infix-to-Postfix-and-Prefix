#include <bits/stdc++.h>
#include <windows.h>
#include <windowsx.h>
#include <winuser.h>
#include <stdio.h>
#include "Shlwapi.h"
#include "Expression.cpp"
#include "Infix.cpp"
#include "transcendentalFunc.h"
#define M_PI 3.14159265358979323846
#define endl "\n"

using namespace std;

#define MAX_SIZE 100000000
#define GENERATE_BUTTON 1
#define OPEN_FILE_BUTTON 2
char input[MAX_SIZE], postfixOutput[MAX_SIZE], prefixOutput[MAX_SIZE], evaluateOutput[MAX_SIZE];

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void AddControls(HWND);
void loadImages();

HWND hInput, hPostfix, hPrefix, hEvaluate;
HMENU hMenu;
HBITMAP hLogoImage, hGenerateButtonImage, hUploadFileButtonImage;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASSW wc = {0};
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc = WindowProcedure;

	if (!RegisterClassW(&wc))
		return -1;

	CreateWindowW(L"myWindowClass", L"Infix expression converter", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
				  300, 50, 900, 750, NULL, NULL, NULL, NULL);

	MSG msg = {0};

	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

void display_file(char *path)
{
	FILE *file;
	file = fopen(path, "rb");
	fseek(file, 0, SEEK_END);
	int _size = ftell(file);
	rewind(file);

	char *data = new char[_size + 1];
	fread(data, _size, 1, file);
	data[_size] = '\0';

	SetWindowText(hInput, data);
}

void open_file(HWND hWnd)
{
	OPENFILENAME ofn;

	char file_name[100];

	ZeroMemory(&ofn, sizeof(OPENFILENAME));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = file_name;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = 100;
	ofn.lpstrFilter = "Text Files\0*.TXT\0";
	ofn.nFilterIndex = 1;

	GetOpenFileName(&ofn);

	display_file(ofn.lpstrFile);
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_COMMAND:
	{
		switch (wp)
		{
		case GENERATE_BUTTON:
		{

			GetWindowText(hInput, input, MAX_SIZE);
			if (strcmp(input, "") == 0)
			{
				int choice = MessageBoxW(hWnd, L"You did not enter anything !", NULL, MB_ABORTRETRYIGNORE | MB_ICONERROR);
				switch (choice)

				{
				case IDABORT:
					DestroyWindow(hWnd);
					break;
				case IDRETRY:
					return 0;
				case IDIGNORE:
					break;

				default:
					break;
				}
			}

			// TODO: handle negative value of transcendental functions

			Edit_GetText(hInput, input, MAX_SIZE);

			string expr = input;
			Infix infix;
			expr = Expression::removeBlankSpace(expr);
			infix.setExpr(expr);

			try
			{
				strcpy(postfixOutput, infix.infixToPostfix().c_str());
				strcpy(prefixOutput, infix.infixToPrefix().c_str());
				strcpy(evaluateOutput, to_string(infix.evaluatePostfix()).c_str());
			}
			catch (const runtime_error &e)
			{
				wstring wsTmp(e.what(), e.what() + strlen(e.what()));
				const wchar_t *wc = wsTmp.c_str();

				int choice = MessageBoxW(hWnd, wc, NULL, MB_OK | MB_ICONERROR);
				switch (choice)
				{
				case IDOK:
					return 0;
					break;
				default:
					break;
				}
			}

			SetWindowText(hPostfix, postfixOutput);
			SetWindowText(hPrefix, prefixOutput);
			SetWindowText(hEvaluate, evaluateOutput);

			break;
		}

		case OPEN_FILE_BUTTON:
		{
			open_file(hWnd);
			break;
		}
		}
		break;
	}
	case WM_CREATE:
	{
		loadImages();
		AddControls(hWnd);
		break;
	}

	case WM_CLOSE:
	{
		int choice = MessageBoxW(hWnd, L"You're about to quit, are you sure ?", L"Wait!",
								 MB_YESNO | MB_ICONEXCLAMATION);
		if (choice == IDYES)
		{
			{
				DestroyWindow(hWnd);
			}
		}
		break;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void AddControls(HWND hWnd)
{
	HWND hLogo = CreateWindowW(L"Static", NULL,
							   WS_VISIBLE | WS_CHILD | SS_BITMAP, 80, 40, 700, 150, hWnd, NULL, NULL, NULL);
	SendMessageW(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLogoImage);

	CreateWindowW(L"static", L"Input infix expression: ",
				  WS_VISIBLE | WS_CHILD, 70, 50 + 170, 200, 38, hWnd, NULL, NULL, NULL);
	hInput = CreateWindowW(L"Edit", L"",
						   WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | WS_HSCROLL | ES_AUTOVSCROLL,
						   70, 70 + 170, 700, 50, hWnd, NULL, NULL, NULL);

	HWND hGenerateButton = CreateWindowW(L"Button", NULL,
										 WS_VISIBLE | WS_CHILD | BS_BITMAP,
										 375, 120 + 170, 140, 50, hWnd, (HMENU)GENERATE_BUTTON, NULL, NULL);
	SendMessageW(hGenerateButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hGenerateButtonImage);

	HWND hUploadFileButton = CreateWindowW(L"Button", NULL,
										   WS_VISIBLE | WS_CHILD | BS_BITMAP,
										   780, 70 + 170, 30, 30, hWnd, (HMENU)OPEN_FILE_BUTTON, NULL, NULL);
	SendMessageW(hUploadFileButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hUploadFileButtonImage);

	CreateWindowW(L"static", L"Prefix expression: ",
				  WS_VISIBLE | WS_CHILD, 70, 190 + 170, 98, 38, hWnd, NULL, NULL, NULL);
	hPrefix = CreateWindowW(L"Edit", L"",
							WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | WS_HSCROLL | ES_AUTOVSCROLL,
							70, 225 + 170, 700, 50, hWnd, NULL, NULL, NULL);

	CreateWindowW(L"static", L"Postfix expression: ",
				  WS_VISIBLE | WS_CHILD, 70, 290 + 170, 98, 38, hWnd, NULL, NULL, NULL);
	hPostfix = CreateWindowW(L"Edit", L"",
							 WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | WS_HSCROLL | ES_AUTOVSCROLL,
							 70, 325 + 170, 700, 50, hWnd, NULL, NULL, NULL);

	CreateWindowW(L"static", L"Evaluate expression: ",
				  WS_VISIBLE | WS_CHILD, 70, 390 + 170, 98, 38, hWnd, NULL, NULL, NULL);
	hEvaluate = CreateWindowW(L"Edit", L"",
							  WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | WS_HSCROLL | ES_AUTOVSCROLL,
							  70, 425 + 170, 700, 50, hWnd, NULL, NULL, NULL);
}

void loadImages()
{
	hLogoImage = (HBITMAP)LoadImageW(NULL, L"images\\Logo.bmp", IMAGE_BITMAP, 700, 150, LR_LOADFROMFILE);
	hGenerateButtonImage = (HBITMAP)LoadImageW(NULL, L"images\\button.bmp", IMAGE_BITMAP, 140, 50, LR_LOADFROMFILE);
	hUploadFileButtonImage = (HBITMAP)LoadImageW(NULL, L"images\\UploadFileLogo.bmp", IMAGE_BITMAP, 30, 30, LR_LOADFROMFILE);
}
