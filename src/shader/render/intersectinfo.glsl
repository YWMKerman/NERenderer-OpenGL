// intersectinfo.glsl

#include "object.glsl"

struct IntersectInfo {
    float tHit;
    vec3 hitPoint;
    vec3 hitNormal;
    vec3 incomeDir;
    ObjectPointer hitObj;
};

IntersectInfo intersectInfo(float tHit,
                            vec3 hitPoint,
                            vec3 hitNormal,
                            vec3 incomeDir,
                            ObjectPointer hitObj) {

    IntersectInfo isect;
    isect.tHit = tHit;
    isect.hitPoint = hitPoint;
    isect.hitNormal = hitNormal;
    isect.incomeDir = incomeDir;
    isect.hitObj = hitObj;
}
