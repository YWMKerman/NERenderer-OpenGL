// renderer.hpp

#pragma once

#include "../../base/include/camera.hpp"
#include "../../base/include/scene.hpp"
#include "../../base/include/object.hpp"

class Renderer {
    public:
        Renderer(Scene &scene, const Camera &camera);
        void Render(int width, int height);

    private:
        ObjectData *objectListData;
        unsigned int objectListDataLength;
        const Camera &camera;
        static const float vertices[];
        static const unsigned int faces[];
};
