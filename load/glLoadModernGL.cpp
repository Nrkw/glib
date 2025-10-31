#include <windows.h>
#include <gl/GL.h>
#include <GL/glext.h>
#include "load/glLoadModernGL.hpp"

// OpenGL 関数ポインタ実体（extern の定義）
PFNGLCREATESHADERPROC        glCreateShader       = nullptr;
PFNGLSHADERSOURCEPROC        glShaderSource       = nullptr;
PFNGLCOMPILESHADERPROC       glCompileShader      = nullptr;
PFNGLCREATEPROGRAMPROC       glCreateProgram      = nullptr;
PFNGLATTACHSHADERPROC        glAttachShader       = nullptr;
PFNGLLINKPROGRAMPROC         glLinkProgram        = nullptr;
PFNGLUSEPROGRAMPROC          glUseProgram         = nullptr;
PFNGLDELETESHADERPROC        glDeleteShader       = nullptr;
PFNGLDELETEPROGRAMPROC       glDeleteProgram      = nullptr;
PFNGLGETSHADERIVPROC         glGetShaderiv        = nullptr;
PFNGLGETSHADERINFOLOGPROC    glGetShaderInfoLog   = nullptr;
PFNGLGETPROGRAMIVPROC        glGetProgramiv       = nullptr;
PFNGLGETPROGRAMINFOLOGPROC   glGetProgramInfoLog  = nullptr;


PFNGLGENVERTEXARRAYSPROC     glGenVertexArrays    = nullptr;
PFNGLBINDVERTEXARRAYPROC     glBindVertexArray    = nullptr;
PFNGLDELETEVERTEXARRAYSPROC  glDeleteVertexArrays = nullptr;


PFNGLGENBUFFERSPROC           glGenBuffers         = nullptr;
PFNGLBINDBUFFERPROC          glBindBuffer         = nullptr;
PFNGLBUFFERDATAPROC          glBufferData         = nullptr;
PFNGLDELETEBUFFERSPROC       glDeleteBuffers      = nullptr;

PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer=nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = nullptr;
namespace gl
{
    void* GetAnyGLProcAddress(const char* name)
    {
        // 追加: 安全に関数アドレスを取得するヘルパ
        void* p = (void*)wglGetProcAddress(name);
        if (p == nullptr || p == (void*)0x1 || p == (void*)0x2 || p == (void*)0x3 || p == (void*)-1) {
            HMODULE mod = LoadLibraryA("opengl32.dll");
            if (mod) p = (void*)GetProcAddress(mod, name);
        }
        return p;

    }
    bool InitModernGLFunctions()
    {
        // シェーダ系
        glCreateShader       = (PFNGLCREATESHADERPROC)      GetAnyGLProcAddress("glCreateShader");
        glShaderSource       = (PFNGLSHADERSOURCEPROC)      GetAnyGLProcAddress("glShaderSource");
        glCompileShader      = (PFNGLCOMPILESHADERPROC)     GetAnyGLProcAddress("glCompileShader");
        glCreateProgram      = (PFNGLCREATEPROGRAMPROC)     GetAnyGLProcAddress("glCreateProgram");
        glAttachShader       = (PFNGLATTACHSHADERPROC)      GetAnyGLProcAddress("glAttachShader");
        glLinkProgram        = (PFNGLLINKPROGRAMPROC)       GetAnyGLProcAddress("glLinkProgram");
        glUseProgram         = (PFNGLUSEPROGRAMPROC)        GetAnyGLProcAddress("glUseProgram");
        glDeleteShader       = (PFNGLDELETESHADERPROC)      GetAnyGLProcAddress("glDeleteShader");
        glDeleteProgram      = (PFNGLDELETEPROGRAMPROC)     GetAnyGLProcAddress("glDeleteProgram");
        glGetShaderiv        = (PFNGLGETSHADERIVPROC)       GetAnyGLProcAddress("glGetShaderiv");
        glGetShaderInfoLog   = (PFNGLGETSHADERINFOLOGPROC)  GetAnyGLProcAddress("glGetShaderInfoLog");
        glGetProgramiv       = (PFNGLGETPROGRAMIVPROC)      GetAnyGLProcAddress("glGetProgramiv");
        glGetProgramInfoLog  = (PFNGLGETPROGRAMINFOLOGPROC) GetAnyGLProcAddress("glGetProgramInfoLog");

        // VAO/VBO
        glGenVertexArrays        = (PFNGLGENVERTEXARRAYSPROC)     GetAnyGLProcAddress("glGenVertexArrays");
        glBindVertexArray        = (PFNGLBINDVERTEXARRAYPROC)     GetAnyGLProcAddress("glBindVertexArray");
        glDeleteVertexArrays     = (PFNGLDELETEVERTEXARRAYSPROC)  GetAnyGLProcAddress("glDeleteVertexArrays");

        glGenBuffers             = (PFNGLGENBUFFERSPROC)          GetAnyGLProcAddress("glGenBuffers");
        glBindBuffer             = (PFNGLBINDBUFFERPROC)          GetAnyGLProcAddress("glBindBuffer");
        glBufferData             = (PFNGLBUFFERDATAPROC)          GetAnyGLProcAddress("glBufferData");
        glDeleteBuffers          = (PFNGLDELETEBUFFERSPROC)       GetAnyGLProcAddress("glDeleteBuffers");

        glVertexAttribPointer    = (PFNGLVERTEXATTRIBPOINTERPROC) GetAnyGLProcAddress("glVertexAttribPointer");
        glEnableVertexAttribArray= (PFNGLENABLEVERTEXATTRIBARRAYPROC)GetAnyGLProcAddress("glEnableVertexAttribArray");

        // 必須が全部取れているかチェック
        bool ok =
            glCreateShader && glShaderSource && glCompileShader && glCreateProgram &&
            glAttachShader && glLinkProgram && glUseProgram &&
            glGetShaderiv && glGetShaderInfoLog && glGetProgramiv && glGetProgramInfoLog &&
            glGenVertexArrays && glBindVertexArray && glDeleteVertexArrays &&
            glGenBuffers && glBindBuffer && glBufferData && glDeleteBuffers &&
            glVertexAttribPointer && glEnableVertexAttribArray;

        return ok;
    }
}