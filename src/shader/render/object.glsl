// object.glsl

#include "shape.glsl"
#include "material.glsl"
#include "intersectinfo.glsl"
#include "objectptr.glsl"

uniform sampler2D objectList;

struct Object {
    Shape shape;
    Material material;
};

Object object(ObjectPtr objPtr) {
    vec4 shapeData[3];
    vec4 materialData[2];
    float index = float(objPtr.index);

    shapeData[0] = texture1D(objectList, (index + 0 + 0.5f) / objNum);
    shapeData[1] = texture1D(objectList, (index + 1 + 0.5f) / objNum);
    shapeData[2] = texture1D(objectList, (index + 2 + 0.5f) / objNum);
    materialData[0] = texture1D(objectList, (index + 3 + 0.5f) / objNum);
    materialData[1] = texture1D(objectList, (index + 4 + 0.5f) / objNum);

    Shape shape;
    shape.type = shapeData[0].x;
    shape.p0 = shapeData[0].yzw;
    shape.radius = shapeData[1].x;
    shape.p1 = shapeData[1].yzw;
    shape.reverseNormal = shapeData[2].x;
    shape.p2 = shapeData[2].yzw;

    Material material;
    material.type = materialData[0].x;
    material.kd = materialData[0].yzw;
    material.isGlow = materialData[1].x;
    material.glowSpectrum = materialData[1].yzw;

    Object obj;
    obj.shape = shape;
    obj.material = material;

    return obj;
}

IntersectInfo objectIntersect(ObjectPtr objPtr, Ray r) {
    Object obj = object(objPtr);
}

bool objectIsIntersect(ObjectPtr objPtr, Ray r) {
    Object obj = object(objPtr);
}
