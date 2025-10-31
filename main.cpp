#include "window/glWindow.hpp"
#include "renderer/glRenderer.hpp"
#include "image/glImageRenderer.hpp"
#include "glColor.hpp"
#include "shader/glShader.hpp"

#include <memory>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "load/glLoadModernGL.hpp"

#define DEBUG_MODE
#include "Debug.hpp"


bool flag = false;

cv::Mat m = cv::imread("C:/Users/nrkwd/cpp/semiar_graduate/image_edit/openglwrapper/glib/KadaKou1.jpg");
std::unique_ptr<gl::ImageRenderer> irenderer = nullptr;

std::unique_ptr<gl::Shader> shader;
void paint()
{
    gl::Renderer renderer;

    renderer.clear(1.0f, 1.0f, 1.0f, 1.0f);
    /*
    renderer.setColor(gl::Color::Chocolate());
    if(flag)
    {
        renderer.setColor(gl::Color::Pink());
    }
    renderer.drawTriangle(0.0f, 1.0f,
                               -1.0f, -1.0f,
                               1.0f, -1.0f);
    */
    if(irenderer)
    {
        //irenderer->render(-1.0f, -1.0f, 1.8f, 1.6f);
    }
    static GLuint VAO = 0, VBO = 0;
    // 頂点データ
    if(VAO == 0)
    {
        float vertices[] = {
            -0.5f, -0.5f, 0.0f, // 左下
            0.5f, -0.5f, 0.0f, // 右下
            0.0f,  0.5f, 0.0f  // 上
        };
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        // VAO をバインド
        glBindVertexArray(VAO);

        // VBO をバインドしてデータをアップロード
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // 頂点属性を設定
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // バインド解除
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

    }
    if(shader)
    {
        shader->use();
    }
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);

    SwapBuffers(wglGetCurrentDC());
    
    
}
void keyHandler(gl::KeyEvent event)
{
    /*
    if (event.action == gl::KeyEvent::KEY_DOWN)
    {
        flag = true;
        std::wcout << L"Key Down: " << event.getKeyChar() << std::endl;
    }
    else if (event.action == gl::KeyEvent::KEY_UP)
    {
        std::wcout << L"Key Up: " << event.getKeyChar() << std::endl;
    }
    else if (event.action == gl::KeyEvent::KEY_PRESS)
    {
        std::wcout << L"Key Press: " << event.getKeyChar() << std::endl;
    }
        */
}
void mouseHandler(gl::MouseEvent event)
{
    /*
    if(event.action == gl::MouseEvent::MOUSE_LBUTTON_DOWN)
    {
        int x, y;
        event.getMousePosition(x, y);
        std::wcout << L"Left Button Down at (" << x << L"," << y << L")" << std::endl;
    }
    else if(event.action == gl::MouseEvent::MOUSE_LBUTTON_UP)
    {
        int x, y;
        event.getMousePosition(x, y);
        std::wcout << L"Left Button Up at (" << x << L"," << y << L")" << std::endl;
    }
    else if(event.action == gl::MouseEvent::MOUSE_MOVE)
    {
        int x, y;
        event.getMousePosition(x, y);
        std::wcout << L"Mouse Move at (" << x << L"," << y << L")" << std::endl;
    }
        */
}
int main()
{

    Debug::attachConsole();
    Debug::log("TEST");

    if(m.empty()) 
    {
        Debug::err("Failed to load image");
    }else
    {
        Debug::log("Image Load Succeeded");
    }

    std::wcout << "Hello" << std::endl;

    std::unique_ptr<gl::Window> window = std::make_unique<gl::Window>(700, 1000, L"Hello", paint);
    // irenderer = std::make_unique<gl::ImageRenderer>(m);
    window->show();

    window->addKeyListener(keyHandler);
    window->addMouseListener(mouseHandler);
    irenderer = std::make_unique<gl::ImageRenderer>(m);

    shader = std::make_unique<gl::Shader>("sampleshader.vert", "sampleshader.frag");
    shader->use();

    MSG msg = {};
    while(GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }
}