// scene.glsl

#include "intersectinfo.glsl"
#include "objectptr.glsl"
#include "shape.glsl"
#include "material.glsl"
#include "ray.glsl"

IntersectInfo SceneIntersect(Ray ray) {
    IntersectInfo isect = IntersectInfoInitNone();
    for (ObjectPtr objPtr = ObjectPtrInit(uint(0));
         !ObjectPtrEOF(objPtr);
         objPtr = ObjectPtrNext(objPtr)) {

        Shape shape = ShapeInit(objPtr);
        isect = ShapeIntersect(shape, ray);
        if (isect.isHit) {
            Material material = MaterialInit(objPtr);
            ray.tMax = isect.tHit;
            isect.hitMaterial = material;
        }
    }
    return isect;
}

bool SceneIsIntersect(Ray ray) {
    bool isHit = false;
    for (ObjectPtr objPtr = ObjectPtrInit(uint(0));
         !ObjectPtrEOF(objPtr);
         objPtr = ObjectPtrNext(objPtr)) {

        Shape shape = ShapeInit(objPtr);
        if (ShapeIsIntersect(shape, ray)) {
            isHit = true;
            break;
        }
    }
    return isHit;
}
