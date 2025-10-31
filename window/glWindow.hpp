#ifndef GLWINDOW_HPP
#define GLWINDOW_HPP

#include <string>
#include <windows.h>
#include <functional>

#include "glKeyEvent.hpp"
#include "glMouseEvent.hpp"
namespace gl
{
    class Window
    {
        public:
            Window(int width, int height, std::wstring title, std::function<void()> callback);
            ~Window();

            void show();
            void hide();
            void addMouseListener(std::function<void(MouseEvent)> callback);
            void addKeyListener(std::function<void(KeyEvent)> callback);
        private:
            HWND hwnd;
            HDC hdc;
            HGLRC hglrc;
            const wchar_t* CLASS_NAME = L"GLlibWindowClass";

            static LRESULT CALLBACK staticCallbackFunction(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
            LRESULT handleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
            std::function<void()> callbackFunction;



            //privateなメンバ関数
            // OpenGL初期化関数
            void initializeOpenGL();
            void cleanupOpenGL();

            //privateなメンバ変数

            std::function<void(KeyEvent)> keycallback;
            std::function<void(MouseEvent)> mousecallback;
            static std::string ConvertWStrToStr(const std::wstring& src);
    };
};

#endif