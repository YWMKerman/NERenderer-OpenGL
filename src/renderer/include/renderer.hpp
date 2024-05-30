// renderer.hpp

#pragma once

#include "../../base/include/camera.hpp"
#include "../../base/include/scene.hpp"
#include "../../base/include/object.hpp"

class Renderer {
    public:
        Renderer(Scene &scene, const Camera &camera);
        ~Renderer();

        void Render();

    private:
        ObjectData *objectListData;
        unsigned int objectListDataLength;
        unsigned int packPerObject;
        const Camera &camera;
        static const float vertices[];
        static const unsigned int faces[];
        unsigned int *randomSeed;
};
