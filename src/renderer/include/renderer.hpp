// renderer.hpp

#pragma once

#include "../../base/include/camera.hpp"
#include "../../base/include/scene.hpp"
#include "../../base/include/object.hpp"

class Renderer {
    public:
        Renderer(Scene &scene,
                 const Camera &camera,
                 int maxDepth,
                 float russianRoulete,
                 float gamma,
                 bool accumulate);

        ~Renderer();

        void Render();

    private:
        static const float vertices[];
        static const unsigned int faces[];

        ObjectData *objectListData;
        unsigned int objectListDataLength;
        unsigned int packPerObject;

        const Camera &camera;
        int screenWidth;
        int screenHeight;

        int maxDepth;
        float russianRoulete;
        float gamma;
        bool accumulate;

        unsigned int *randomSeed;
};
