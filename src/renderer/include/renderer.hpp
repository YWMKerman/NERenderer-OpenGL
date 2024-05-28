// renderer.hpp

#pragma once

#include "../../base/include/camera.hpp"
#include "../../base/include/scene.hpp"

class Renderer {
    public:
        Renderer(Scene &scene, const Camera &camera);
        void Render(int width, int height);

    private:
        unsigned char *objectListData;
        CameraData cameraData;
        static const float vertices[];
        static const unsigned int faces[];
};
