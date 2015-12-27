#ifdef _WIN32
#include "WinApp.hpp"


WinApp::WinApp(HINSTANCE hInstance){
    
    WNDCLASSEX windowClass;
    
    
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
}

LRESULT CALLBACK WinApp::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    
}


WinApp::~WinApp(){
    
}


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR cmdLine,
                   int cmdShow){
    std::unique_ptr<WinApp> app = std::unique_ptr<WinApp>(new WinApp(hInstance));
}
#endif