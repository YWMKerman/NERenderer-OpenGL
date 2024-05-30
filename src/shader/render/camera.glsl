// camera.glsl

#include "ray.glsl"
#include "random.glsl"

struct Camera {
    int width;
    int height;

    vec3 pos;

    vec3 look;
    vec3 up;
    vec3 right;

    vec3 screenUpperLeftCorner;
    float screenPlaneWidth;
    float screenPlaneHeight;

    float fov;
    float focalLength;
    float lenRadius;
};

uniform Camera camera;

Ray cameraGetSampleRay(vec2 screenOffset) {
    screenOffset += vec2(random01(),random01());
    vec3 samplePoint =  camera.screenUpperLeftCorner
                        + camera.right * screenOffset.x * camera.screenPlaneWidth
                        - camera.up    * screenOffset.y * camera.screenPlaneHeight;

    return ray(samplePoint, samplePoint - camera.pos, 0.0f, inf);
}
