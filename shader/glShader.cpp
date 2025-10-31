#include "shader/glShader.hpp"
#include <gl/GL.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "load/glLoadModernGL.hpp"

namespace gl
{
    Shader::Shader(const char* vertexSource, const char* fragmentSource)
    {


        std::string vertexCode = readFile(vertexSource);
        std::string fragmentCode = readFile(fragmentSource);
        GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexCode.c_str());
        GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentCode.c_str());

        programID = glCreateProgram();
        glAttachShader(programID, vertexShader);
        glAttachShader(programID, fragmentShader);
        glLinkProgram(programID);
        checkCompileErrors(programID, "PROGRAM");
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    Shader::~Shader()
    {
        glDeleteProgram(programID);
    }
    void Shader::use() const
    {
        glUseProgram(programID);
    }
    GLuint Shader::getProgramID() const
    {
        return programID;
    }
    GLuint Shader::compileShader(GLenum type, const char* source)
    {
        GLuint shader = glCreateShader(type);
        glShaderSource(shader, 1, &source, nullptr);
        glCompileShader(shader);
        checkCompileErrors(shader, (type == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT");
        return shader;
    }
    void Shader::checkCompileErrors(GLuint shader, const std::string& type)
    {
        GLint success;
        GLchar infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
                std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n"
                          << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
                std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n"
                          << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }

    std::string Shader::readFile(const char* filePath)
    {
        std::ifstream file;
        std::stringstream buffer;
        file.open(filePath);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file: " + std::string(filePath));
        
        }
        buffer << file.rdbuf();
        file.close();
        return buffer.str();
    }

}