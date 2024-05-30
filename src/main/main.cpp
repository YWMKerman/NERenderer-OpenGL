// main.cpp

#include "../math/include/vector3.hpp"
#include "../math/include/spectrum.hpp"

#include "../base/include/camera.hpp"
#include "../base/include/scene.hpp"
#include "../base/include/object.hpp"
#include "../base/include/shape.hpp"
#include "../base/include/material.hpp"

#include "../renderer/include/renderer.hpp"

int main() {
    Camera camera(800,                      // width
                  600,                      // height
                  Vector3(0.0, -5.0,  0.0), // pos
                  Vector3(0.0,  1.0,  0.0), // look
                  Vector3(0.0,  0.0,  1.0), // up
                  60,                       // fov
                  1,                        // focalLength
                  0.1                       // lenRadius
    );

    Scene scene;

    // Left Wall
    scene.AddObject(
            Object(
                Sphere(Vector3(-101, 0, 0), 100, false),
                Lambertian(Spectrum(1.0, 0.0, 0.0), Spectrum(0.0, 0.0, 0.0))
            )
    );

    // Right Wall
    scene.AddObject(
            Object(
                Sphere(Vector3(101, 0, 0), 100, false),
                Lambertian(Spectrum(0.0, 1.0, 0.0), Spectrum(0.0, 0.0, 0.0))
            )
    );

    // Upper Wall
    scene.AddObject(
            Object(
                Sphere(Vector3(0, 0, 101), 100, false),
                Lambertian(Spectrum(1.0, 1.0, 1.0), Spectrum(0.0, 0.0, 0.0))
            )
    );

    // Bottom Wall
    scene.AddObject(
            Object(
                Sphere(Vector3(0, 0, -101), 100, false),
                Lambertian(Spectrum(1.0, 1.0, 1.0), Spectrum(0.0, 0.0, 0.0))
            )
    );

    // Inside Wall
    scene.AddObject(
            Object(
                Sphere(Vector3(0, 101, 0), 100, false),
                Lambertian(Spectrum(1.0, 1.0, 1.0), Spectrum(0.0, 0.0, 0.0))
            )
    );

    // Glowing Sphere
    scene.AddObject(
            Object(
                Sphere(Vector3(0, 0, 0.2), 0.2, false),
                Lambertian(Spectrum(1.0, 1.0, 1.0), Spectrum(1.0, 1.0, 1.0))
            )
    );

    Renderer renderer(scene, camera);
    renderer.Render();
}
