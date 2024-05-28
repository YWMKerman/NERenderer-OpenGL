// shape.cpp

#include "include/shape.hpp"

#include "../math/include/vector3.hpp"

ShapeData Shape::GetShapeData() const {
    return shapeData;
}

Sphere::Sphere(Vector3 pos, float radius, bool reverseNormal) {
    shapeData.type = 0;
    shapeData.radius = radius;
    shapeData.reverseNormal = reverseNormal ? 1 : 0;

    shapeData.p0[0] = pos[0];
    shapeData.p0[1] = pos[1];
    shapeData.p0[2] = pos[2];

    shapeData.p1[0] = 0;
    shapeData.p1[1] = 0;
    shapeData.p1[2] = 0;

    shapeData.p2[0] = 0;
    shapeData.p2[1] = 0;
    shapeData.p2[2] = 0;
}

Triangle::Triangle(Vector3 p0, Vector3 p1, Vector3 p2, bool reverseNormal) {
    shapeData.type = 1;
    shapeData.radius = 0;
    shapeData.reverseNormal = reverseNormal ? 1 : 0;

    shapeData.p0[0] = p0[0];
    shapeData.p0[1] = p0[1];
    shapeData.p0[2] = p0[2];

    shapeData.p1[0] = p1[0];
    shapeData.p1[1] = p1[1];
    shapeData.p1[2] = p1[2];

    shapeData.p2[0] = p2[0];
    shapeData.p2[1] = p2[1];
    shapeData.p2[2] = p2[2];
}
