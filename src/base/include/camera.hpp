// camera.hpp

#pragma once

#include "../../math/include/vector3.hpp"

typedef struct CameraData {
    float pos[3];

    float look[3];
    float up[3];
    float right[3];

    float fov;
    float focalLength;
    float lenRadius;
} CameraData;

class Camera {
    public:
        Camera(Vector3 pos,
               Vector3 look,
               Vector3 up,
               float fov,
               float focalLength,
               float lenRadius); 

        CameraData GetCameraData() const;

    private:
        CameraData cameraData;
};
