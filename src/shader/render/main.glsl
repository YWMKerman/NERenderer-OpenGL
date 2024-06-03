// main.glsl

#version 330 core

out vec4 outColor;

uniform sampler2D lastRenderResult;
uniform uvec2 screenGeometry;
uniform bool accumulate;
uniform int frameCount;

uniform sampler1D objectList;
uniform uint packPerObject;
uniform uint packNum;

uniform float gamma;

const float INF = 1.0f / 0.0f;
const float PI = 3.1415926535898f;
const float TWOPI = 6.2831853071796f;
const float INVPI = 0.3183098861838f;
const float EPSILON = 0.001f;

#include "random.glsl"
#include "camera.glsl"
#include "ray.glsl"
#include "renderer.glsl"

void main() {
    vec2 screenIndex = gl_FragCoord.xy;
    RandomInit(screenIndex);
    Ray ray = CameraGetSampleRay(screenIndex);

    vec3 result = PathTracing(ray);
    float invGamma = 1.0f / gamma;
    result = vec3(clamp(pow(result.x, invGamma), 0, 1),
                  clamp(pow(result.y, invGamma), 0, 1),
                  clamp(pow(result.z, invGamma), 0, 1));

    if (accumulate) {
        vec3 lastColor = texture2D(lastRenderResult, screenIndex / screenGeometry).xyz;
        outColor = vec4(mix(lastColor, result, 1.0f / frameCount), 1.0f);
    }
    else {
        outColor = vec4(result, 1.0f);
    }
}
