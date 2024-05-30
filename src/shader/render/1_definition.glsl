// definition.glsl

struct Camera {
    vec3 pos;

    vec3 look;
    vec3 up;
    vec3 right;

    float fov;
    float focalLength;
    float lenRadius;
};

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

struct Material {
    // Pack 1
    float type;
    vec3 kd;

    // Pack 2
    float isGlow;
    vec3 glowSpectrum;
};

struct Object {
    Shape shape;
    Material material;
};
