// shape.glsl

#include "intersectinfo.glsl"

struct Shape {
    // Pack 1
    float type;
    vec3 p0; // For Sphere Position

    // Pack 2
    float radius; // For Sphere
    vec3 p1;

    // Pack 3
    float reverseNormal;
    vec3 p2;
};

IntersectInfo sphereIntersect(vec3 origin, float radius, Ray r) {
}

bool sphereIsIntersect(vec3 origin, float radius, Ray r) {
}

IntersectInfo triangleIntersect(vec3 p0, vec3 p1, vec3 p2, Ray r) {
}

bool triangleIsIntersect(vec3 p0, vec3 p1, vec3 p2, Ray r) {
}
