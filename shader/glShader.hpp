#ifndef GL_SHADER_HPP
#define GL_SHADER_HPP
#include <gl/GL.h>
#include <string>
namespace gl
{
    class Shader
    {
    public:
        Shader(const char* vertexSource, const char* fragmentSource);
        ~Shader();

        void use() const;
        GLuint getProgramID() const;

    private:
        GLuint programID;

        void initializeModernOpenGLFunctions();
        GLuint compileShader(GLenum type, const char* source);
        void checkCompileErrors(GLuint shader, const std::string& type);
        std::string readFile(const char* filePath);
    };
}

#endif