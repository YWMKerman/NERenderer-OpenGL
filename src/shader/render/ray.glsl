// ray.glsl

struct Ray {
    vec3 origin;
    vec3 dir;
    float tMin;
    float tMax;
};

Ray ray(vec3 origin, vec3 dir, float tMin, float tMax) {
    Ray ray;
    ray.origin = origin;
    ray.dir = dir;
    ray.tMin = tMin;
    ray.tMax = tMax;
    return ray;
}

vec3 rayAt(Ray r, float t) {
    return r.origin + r.dir * t;
}
