#include "window/glWindow.hpp"
#include "load/glLoadModernGL.hpp"
#include <windows.h>
#include <iostream>
#include <GL/gl.h>


namespace gl
{
    Window::Window(int width, int height, std::wstring title, std::function<void()> callback)
    {
        WNDCLASSW wc = {};
        wc.lpfnWndProc = staticCallbackFunction;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = CLASS_NAME;
        
        if(!RegisterClassW(&wc))
        {
            throw std::runtime_error("Failed to register window class");
            exit(EXIT_FAILURE);
        }
        hwnd = CreateWindowExW(
            0, CLASS_NAME, title.c_str(),
            WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height,
            nullptr, nullptr, wc.hInstance, this
        );
        callbackFunction = callback;
        initializeOpenGL();
        InitModernGLFunctions();
        SetTimer(hwnd, 1, 16, nullptr); // 16ms（約60FPS）ごとに WM_TIMER を発生させる
    }
    Window::~Window()
    {
        cleanupOpenGL();
        DestroyWindow(hwnd);
    }
    LRESULT CALLBACK Window::staticCallbackFunction(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        if(uMsg == WM_NCCREATE)
        {
            //WM_NCCREATEとは：ウィンドウが作られる手前に来る。
            //
            CREATESTRUCTW* cs = reinterpret_cast<CREATESTRUCTW*>(lParam);
            Window* self = reinterpret_cast<Window*>(cs->lpCreateParams);
            SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(self));

            if(self)
            {
                self->hwnd = hwnd;
            }
        }

        Window* self = reinterpret_cast<Window*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));
        if(self)
        {
            return self->handleMessage(uMsg, wParam, lParam);
        }
        return DefWindowProcW(hwnd, uMsg, wParam, lParam);


    }

    LRESULT Window::handleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch(uMsg)
        {
            case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hwnd, &ps);
                if(callbackFunction)
                {
                    callbackFunction();
                }
                EndPaint(hwnd, &ps);
                return 0;
            }
            case WM_TIMER:
            {
                InvalidateRect(hwnd, nullptr, FALSE);
                return 0;
            }
            /*マウス関係*/
            case WM_MOUSEMOVE:
            {
                if(mousecallback)
                {
                    MouseEvent e(wParam, lParam, MouseEvent::MOUSE_MOVE);
                    mousecallback(e);
                }
                return 0;
            }
            case WM_RBUTTONDOWN:
            {
                if(mousecallback)
                {
                    MouseEvent e(wParam, lParam, MouseEvent::MOUSE_RBUTTON_DOWN);
                    mousecallback(e);
                }
                return 0;
            }
            case WM_RBUTTONUP:
            {
                if(mousecallback)
                {
                    MouseEvent e(wParam, lParam, MouseEvent::MOUSE_RBUTTON_UP);
                    mousecallback(e);
                }
                return 0;
            }
            case WM_LBUTTONDOWN:
            {
                if(mousecallback)
                {
                    MouseEvent e(wParam, lParam, MouseEvent::MOUSE_LBUTTON_DOWN);
                    mousecallback(e);
                }
                return 0;
            }
            case WM_LBUTTONUP:
            {
                if(mousecallback)
                {
                    MouseEvent e(wParam, lParam, MouseEvent::MOUSE_LBUTTON_UP);
                    mousecallback(e);
                }
                return 0;
            }
            case WM_MOUSEWHEEL:
            {
                if(mousecallback)
                {
                    MouseEvent e(wParam, lParam, MouseEvent::MOUSE_WHEEL);
                    mousecallback(e);
                }
                return 0;
            }
            /*キーボード関係*/
            case WM_KEYDOWN:
            {
                if(keycallback)
                {
                    KeyEvent e(wParam, lParam, KeyEvent::KEY_DOWN);
                    keycallback(e);
                }
                return 0;
            }
            case WM_KEYUP:
            {
                if(keycallback)
                {
                    KeyEvent e(wParam, lParam, KeyEvent::KEY_UP);
                    keycallback(e);
                }
                return 0;
            }
            case WM_DESTROY:
            {
                std::cout << "Window is being destroyed." << std::endl;
                PostQuitMessage(0);
                KillTimer(hwnd, 1);
                return 0;
            }
            default:
            {
                return DefWindowProcW(hwnd, uMsg, wParam, lParam);
            }
        }
    }

    void Window::show()
    {
        ShowWindow(hwnd, SW_SHOW);
    }
    std::string Window::ConvertWStrToStr(const std::wstring& src)
    {
        if( src.empty() ) return {};

        int size_needed = WideCharToMultiByte(CP_UTF8, 0, src.c_str(), -1, nullptr, 0, nullptr, nullptr);
        std::string result(size_needed - 1, 0); // -1 to exclude null terminator
        WideCharToMultiByte(CP_UTF8, 0, src.c_str(), -1, &result[0], size_needed, nullptr, nullptr);
        return result;
    }

    void Window::hide()
    {
        ShowWindow(hwnd, SW_HIDE);
    }

    void Window::initializeOpenGL()
    {
        // OpenGL初期化コードをここに記述
        hdc = GetDC(hwnd);

        PIXELFORMATDESCRIPTOR pfd = {};
        pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cDepthBits = 24;
        pfd.cStencilBits = 8;
        pfd.iLayerType = PFD_MAIN_PLANE;

        int pixelFormat = ChoosePixelFormat(hdc, &pfd);
        SetPixelFormat(hdc, pixelFormat, &pfd);

        //もしpixelFormatが0、すなわちピクセルフォーマットの選択に失敗した場合、例外を投げる
        if(pixelFormat == 0)
        {
            throw std::runtime_error("Failed to choose pixel format for OpenGL");
            exit(EXIT_FAILURE);
        }
        if(!SetPixelFormat(hdc, pixelFormat, &pfd))
        {
            throw std::runtime_error("Failed to set pixel format for OpenGL");
            exit(EXIT_FAILURE);
        }

        hglrc = wglCreateContext(hdc);
        if(!hglrc)
        {
            throw std::runtime_error("Failed to create OpenGL rendering context");
            exit(EXIT_FAILURE);
        }

        if(!wglMakeCurrent(hdc, hglrc))
        {
            throw std::runtime_error("Failed to make OpenGL context current");
            exit(EXIT_FAILURE);
        }
        std::cout << "OpenGL initialized successfully." << std::endl;
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glEnable(GL_DEPTH_TEST);

        RECT rect;
        GetClientRect(hwnd, &rect);
        glViewport(0, 0, rect.right - rect.left, rect.bottom - rect.top);

    }

    void Window::cleanupOpenGL()
    {
        // OpenGLクリーンアップコードをここに記述
        if(hglrc)
        {
            wglMakeCurrent(nullptr, nullptr);
            wglDeleteContext(hglrc);
            hglrc = nullptr;
        }
        if(hdc)
        {
            ReleaseDC(hwnd, hdc);
            hdc = nullptr;
        }
        std::cout << "OpenGL cleaned up successfully." << std::endl;
    }

    void Window::addMouseListener(std::function<void(MouseEvent)> callback)
    {
        mousecallback = callback;
    }
    void Window::addKeyListener(std::function<void(KeyEvent)> callback)
    {
        keycallback = callback;
    }
    
};