#ifndef GLRENDERER_HPP
#define GLRENDERER_HPP

#include <GL/gl.h>
#include "glColor.hpp"
namespace gl
{
    class Renderer
    {
        public:
            Renderer();
            ~Renderer();
            void setColor(Color color);
            void setColor(float r, float g, float b, float a = 1.0f);
            void begin(GLenum mode);
            void end();
            void vertex(float x, float y, float z = 0.0f);

            void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
            void drawRectangle(float x, float y, float width, float height);
            void drawCircle(float centerX, float centerY, float radius, int segments = 36);
            void drawLine(float x1, float y1, float x2, float y2);

            void clear(float r, float g, float b, float a = 1.0f);
        private:


            // OpenGL関連のプライベートメンバ変数
            GLuint vao, vbo, ebo;

    };
};
#endif