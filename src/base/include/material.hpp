// material.hpp

#pragma once

#include "../../math/include/spectrum.hpp"

#pragma pack(1)

typedef struct MaterialData {
    // Pack 1
    int type;
    float kd[3];

    // Pack 2
    int isGlow;
    float glowSpectrum[3];
} MaterialData;

#pragma pack()


class Material {
    public:
        Material() {}
        MaterialData GetMaterialData() const;

    protected:
        MaterialData materialData;
};

class Lambertian : public Material {
    public:
        Lambertian(Spectrum kd, Spectrum glow);
};
