// material.glsl

struct Material {
    // Pack 1
    float type;
    vec3 kd;

    // Pack 2
    float isGlow;
    vec3 glowSpectrum;
};
