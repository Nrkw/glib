#include "image/glImageRenderer.hpp"
#include <GL/gl.h>

#ifndef GL_BGR
#define GL_BGR 0x80E0
#endif

#ifndef GL_BGRA
#define GL_BGRA 0x80E1
#endif

namespace gl
{
    ImageRenderer::ImageRenderer(const cv::Mat &mat)
    {
        try{
        // std::wcout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
        // ここにcv::MatをOpenGLテクスチャとして読み込むコードを実装します。
        // 例えば、テクスチャの生成、バインド、データのアップロードなど。

        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);

        if (mat.empty()) {
            throw std::runtime_error("Input image is empty");
        }

        if (mat.channels() != 3 && mat.channels() != 4) {
            throw std::runtime_error("Unsupported number of channels in input image");
        }

        GLint internalFormat = -1;
        GLenum dataFormat = -1;
        switch(mat.channels())
        {
            case 1:
                std::wcout << "Monochrome" << std::endl;
                internalFormat = GL_LUMINANCE;
                dataFormat = GL_LUMINANCE;
            break;
            case 3:
                std::wcout << "Color(BGR)" << std::endl;
                internalFormat = GL_RGB;
                dataFormat = GL_BGR;
            break;
            case 4:
                std::wcout << "Color(RGBA)" << std::endl;
                // cv::cvtColor(mat, rgb, cv::COLOR_BGRA2RGBA);
                internalFormat = GL_RGBA;
                dataFormat = GL_BGRA;
            break;
            default:
                std::wcout << "DEFAULT" << std::endl;
                throw std::runtime_error("Unsupported number of channels");
            break;
        }
        rgb = mat.clone();
        if(mat.empty())
        {
            throw std::runtime_error("Failed to convert");
        }

        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, rgb.cols, rgb.rows, 0, 
                    dataFormat, GL_UNSIGNED_BYTE, rgb.data);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
    }
    catch(const std::exception &e)
    {
        std::cerr << "Error in ImageRenderer constructor: " << e.what() << std::endl;
    }
    }
    ImageRenderer::~ImageRenderer()
    {
        glDeleteTextures(1, &textureID);
    }
    void ImageRenderer::render(float x, float y, float width, float height)
    {
        // ここにGLuintをOpenGLテクスチャとしてレンダリングするコードを実装します。
        // 例えば、テクスチャの生成、バインド、データのアップロード、描画など。
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f); glVertex2f(x, y);
            glTexCoord2f(1.0f, 1.0f); glVertex2f(x + width, y);
            glTexCoord2f(1.0f, 0.0f); glVertex2f(x + width, y + height);
            glTexCoord2f(0.0f, 0.0f); glVertex2f(x, y + height);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        
    }
}