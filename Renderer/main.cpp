#include <windows.h>
#include <string>
#include <iostream>

#include "ReadObjFile.h"
#include "Render.h"

using namespace std;

static const int screenHeight = 800;
static const int screenWidth = 1500;

HDC hdc;
Mesh mesh;
Camera camera;
Renderer * renderer;

void GenerateConsole();
void Render();

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    //Handle msg
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);	//Quit window
            return 0;
        default:
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
            break;
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nShowCmd)
{
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Render window",               // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return -1;
    }

    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);
    hdc = GetDC(hwnd);

    GenerateConsole();
    
    ReadObjFile("C:\\Users\\u1482656\\Renderer\\Models\\Cube.obj", mesh);
    Render();

    //Main message loop
    //define msg structure
    MSG msg = { 0 };

    while (msg.message != WM_QUIT) {
        if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);	//键盘按键转换，将虚拟键消息转换为字符消息
            DispatchMessage(&msg);	//把消息分派给相应的窗口过程
        }
        //Render window
        else {
            
        }
    }

	return 0;
}


void Render()
{
    renderer = new Renderer(hdc, screenWidth, screenHeight, camera);
    renderer->DrawMesh(&mesh);
    cout << "is here" << endl;
}


void GenerateConsole()
{
    AllocConsole();
    FILE* file;
    freopen_s(&file, "CONOUT$", "w", stdout);
}