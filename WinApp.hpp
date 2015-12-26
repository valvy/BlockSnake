#ifdef _WIN32
#ifndef WIN_APP_HPP
#define WIN_APP_HPP
#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN
#include <windows.h>
#include <stdlib.h>
#include "Application.hpp"


class WinApp{
public:
    Winapp(HINSTANCE hInstance);
    ~WinApp();
private:
    Application* app;
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    
};



#endif
#endif