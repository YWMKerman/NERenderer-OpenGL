// main.glsl

#version 330 core

out vec4 outColor;

uniform sampler2D lastRenderResult;
uniform uvec2 screenGeometry;

const float inf = 1.0f / 0.0f;

#include "random.glsl"
#include "camera.glsl"
#include "ray.glsl"
#include "pathtracer.glsl"

void main() {
    vec2 screenOffset = gl_FragCoord.xy / screenGeometry;
    randomInit(screenOffset);
    Ray r = cameraGetSampleRay(screenOffset);
    outColor = vec4(pathTracing(r), 1.0f);
}
