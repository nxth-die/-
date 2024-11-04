#include <windows.h>
#include <iostream>

void sc() {

    int Wt = GetSystemMetrics(SM_CXSCREEN);
    int Ht = GetSystemMetrics(SM_CYSCREEN);

    HDC hScreenDC = GetDC(NULL);         
    HDC hMemoryDC = CreateCompatibleDC(hScreenDC);
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, Wt, Ht);
    HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemoryDC, hBitmap);

    BitBlt(hMemoryDC, 0, 0, Wt, Ht, hScreenDC, 0, 0, SRCCOPY);

    SelectObject(hMemoryDC, hOldBitmap);

    OpenClipboard(NULL);
    EmptyClipboard();

    SetClipboardData(CF_BITMAP, hBitmap);

    CloseClipboard();

    DeleteDC(hMemoryDC);
    ReleaseDC(NULL, hScreenDC);
    DeleteObject(hBitmap);

    std::cout << "Скриншот сделан и скопирован в буфер обмена.\n";
}
