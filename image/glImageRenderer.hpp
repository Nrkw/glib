#ifndef GL_IMAGE_RENDERER_HPP
#define GL_IMAGE_RENDERER_HPP

#include <opencv2/opencv.hpp>
#include "glRenderer.hpp"

namespace gl
{
    class ImageRenderer
    {
        public:
            ImageRenderer(const cv::Mat &mat);
            ~ImageRenderer();

            void render(float x, float y, float width, float height);
        private:
        GLuint textureID;
        cv::Mat rgb;
    };
};

#endif