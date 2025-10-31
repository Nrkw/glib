#ifndef GL_LOAD_MODERN_OPENGL_HPP
#define GL_LOAD_MODERN_OPENGL_HPP

#include <gl/GL.h>
#include <GL/glext.h>
/*
// OpenGL 関数ポインタの型定義
typedef GLuint(APIENTRY* PFNGLCREATESHADERPROC)(GLenum type);
// typedef void(APIENTRY* PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar** string, const GLint* length);
typedef void(APIENTRY* PFNGLCOMPILESHADERPROC)(GLuint shader);
typedef GLuint(APIENTRY* PFNGLCREATEPROGRAMPROC)();
typedef void(APIENTRY* PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
typedef void(APIENTRY* PFNGLLINKPROGRAMPROC)(GLuint program);
typedef void(APIENTRY* PFNGLUSEPROGRAMPROC)(GLuint program);
typedef void(APIENTRY* PFNGLDELETESHADERPROC)(GLuint shader);
typedef void(APIENTRY* PFNGLDELETEPROGRAMPROC)(GLuint program);
typedef void(APIENTRY* PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint* params);
typedef void(APIENTRY* PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void(APIENTRY* PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint* params);
typedef void(APIENTRY* PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);

//Buffer関連
typedef void(APIENTRY* PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays);
typedef void(APIENTRY* PFNGLBINDVERTEXARRAYPROC)(GLuint array);
typedef void(APIENTRY* PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
typedef void(APIENTRY* PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);

typedef void (APIENTRY* PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint* arrays);
*/
// OpenGL 関数ポインタの宣言
extern PFNGLCREATESHADERPROC glCreateShader;
extern PFNGLSHADERSOURCEPROC glShaderSource;
extern PFNGLCOMPILESHADERPROC glCompileShader;
extern PFNGLCREATEPROGRAMPROC glCreateProgram;
extern PFNGLATTACHSHADERPROC glAttachShader;
extern PFNGLLINKPROGRAMPROC glLinkProgram;
extern PFNGLUSEPROGRAMPROC glUseProgram;
extern PFNGLDELETESHADERPROC glDeleteShader;
extern PFNGLDELETEPROGRAMPROC glDeleteProgram;
extern PFNGLGETSHADERIVPROC glGetShaderiv;
extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
extern PFNGLGETPROGRAMIVPROC glGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;

extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;

extern PFNGLGENBUFFERSPROC glGenBuffers;
extern PFNGLBINDBUFFERPROC glBindBuffer;
extern PFNGLBUFFERDATAPROC glBufferData;
extern PFNGLDELETEBUFFERSPROC glDeleteBuffers;

extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;

extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
namespace gl
{
    bool InitModernGLFunctions();
    void* GetAnyGLProcAddress(const char*name);
};
#endif