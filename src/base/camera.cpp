// camera.cpp

#include "include/camera.hpp"

#include "../math/include/vector3.hpp"

Camera::Camera(Vector3 pos,
               Vector3 look,
               Vector3 up,
               float fov,
               float focalLength,
               float lenRadius) {

    look = Vector3::Normalize(look);
    up = Vector3::Normalize(up);

    Vector3 right = Vector3::Cross(look, up);
    Vector3 newUp = Vector3::Cross(right, look);

    cameraData.pos[0] = pos[0];
    cameraData.pos[1] = pos[1];
    cameraData.pos[2] = pos[2];

    cameraData.look[0] = look[0];
    cameraData.look[1] = look[1];
    cameraData.look[2] = look[2];

    cameraData.up[0] = newUp[0];
    cameraData.up[1] = newUp[1];
    cameraData.up[2] = newUp[2];

    cameraData.fov = fov;
    cameraData.focalLength = focalLength;
    cameraData.lenRadius = lenRadius;
}

CameraData Camera::GetCameraData() const {
    return cameraData;
}
