#include "renderer/glRenderer.hpp"
#include <GL/gl.h>
#include <cmath>

namespace gl
{
    Renderer::Renderer()
    {
        
    }
    Renderer::~Renderer()
    {
        
    }

    void Renderer::setColor(float r, float g, float b, float a)
    {
        glColor4f(r, g, b, a); // OpenGL の glColor4f を呼び出す
    }
    void Renderer::setColor(Color color)
    {
        glColor3f(color.red, color.green, color.blue);
    }
    void Renderer::begin(GLenum mode)
    {
        glBegin(mode); // OpenGL の glBegin を呼び出す
    }
    void Renderer::end()
    {
        glEnd(); // OpenGL の glEnd を呼び出す
    }
    void Renderer::vertex(float x, float y, float z)
    {
        glVertex3f(x, y, z); // OpenGL の glVertex3f を呼び出す
    }
    void Renderer::clear(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a); // 背景色を設定
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // カラーバッファとデプスバッファをクリア
    }
    void Renderer::drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
    {
        begin(GL_TRIANGLES);
        vertex(x1, y1);
        vertex(x2, y2);
        vertex(x3, y3);
        end();
    }
    void Renderer::drawCircle(float centerX, float centerY, float radius, int segments)
    {
        begin(GL_TRIANGLE_FAN);
        vertex(centerX, centerY); // 中心点
        for(int i = 0; i <= segments; ++i)
        {
            float angle = 2.0f * 3.1415926f * float(i) / float(segments);
            float x = centerX + radius * cos(angle);
            float y = centerY + radius * sin(angle);
            vertex(x, y);
        }
        end();
    }
    void Renderer::drawRectangle(float x, float y, float width, float height)
    {
        begin(GL_QUADS);
        vertex(x, y); // 左上
        vertex(x + width, y); // 右上
        vertex(x + width, y + height); // 右下
        vertex(x, y + height); // 左下
        end();
    }
    void Renderer::drawLine(float x1, float y1, float x2, float y2)
    {
        begin(GL_LINES);
        vertex(x1, y1);
        vertex(x2, y2);
        end();
    }

}