// renderer.cpp

#include "include/renderer.hpp"

#include "../base/include/camera.hpp"
#include "../base/include/scene.hpp"

#include "../opengl/include/openglwindow.hpp"
#include "../opengl/include/shader.hpp"
#include "../opengl/include/mesh.hpp"
#include "../opengl/include/framebuffer.hpp"
#include "../opengl/include/texture.hpp"

#include "../../third-party/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#define ArrayLength(_array) ((unsigned int) (sizeof(_array) / sizeof(*_array)))

#define PROJECT_ROOT "/data/data/com.termux/files/home/workspace/NERenderer-OpenGL/"
#define VERTEX_SHADER_PATH PROJECT_ROOT "src/opengl/shader/vertex.glsl"
#define RENDER_FRAGMENT_SHADER_PATH PROJECT_ROOT "src/opengl/shader/render.glsl"
#define DISPLAY_FRAGMENT_SHADER_PATH PROJECT_ROOT "src/opengl/shader/display.glsl"

using namespace std;

const float Renderer::vertices[] = {
     1.0f,  1.0f, 0.0f, // Top Right
     1.0f, -1.0f, 0.0f, // Bottom Right
    -1.0f, -1.0f, 0.0f, // Bottom Left
    -1.0f,  1.0f, 0.0f  // Top Left 
};

const unsigned int Renderer::faces[] = {
    0, 1, 3, // First Triangle
    1, 2, 3  // Second Triangle
};

Renderer::Renderer(Scene &scene, const Camera &camera) {
    cameraData = camera.GetCameraData();
    objectListData = (unsigned char *) scene.GetObjectList();
}

void Renderer::Render(int width, int height) {
    OpenGLWindow openglwindow(width, height, true, "NERenderer");
    openglwindow.LoadOpenGLFunctions();

    Shader renderShader(VERTEX_SHADER_PATH, RENDER_FRAGMENT_SHADER_PATH);
    Shader displayShader(VERTEX_SHADER_PATH, DISPLAY_FRAGMENT_SHADER_PATH);

    Mesh mesh((float *) vertices,
              ArrayLength(vertices),
              (unsigned int *) faces,
              ArrayLength(faces));

    FrameBuffer frame;

    Texture frameTexture(width,
                         height,
                         GL_CLAMP_TO_EDGE,
                         GL_NEAREST,
                         GL_RGB32F,
                         GL_RGB,
                         GL_FLOAT,
                         NULL);

    frame.BindTexture(frameTexture.GetTextureID());

    openglwindow.RenderLoop(
        [&] (GLFWwindow *window) {
            // Process Input
            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                glfwSetWindowShouldClose(window, true);
            }

            /*** Render Image ***/

            // Bind Frame Buffer to Frame Buffer Texture
            glBindFramebuffer(GL_FRAMEBUFFER, frame.GetFrameBufferID());

            // Clear Frame Buffer Texture
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Activate Frame Buffer Texture
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, frameTexture.GetTextureID());

            // Initialize Uniform Variables
            // renderShader.SetUniform("lastRenderResult", static_cast<int>(0));
            renderShader.SetUniform("screenGeometry",
                                    (unsigned int) width,
                                    (unsigned int) height);

            // Render Image to Frame Buffer Texture
            glUseProgram(renderShader.GetShaderProgramID());
            glBindVertexArray(mesh.GetVAO());
            glDrawElements(GL_TRIANGLES, mesh.GetFacesLength(), GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);

            /*** End Render Image ***/


            /*** Display Image ***/

            // Bind Frame Buffer to Screen
            glBindFramebuffer(GL_FRAMEBUFFER, 0);

            // Clear Screen
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Activate Frame Buffer Texture
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, frameTexture.GetTextureID());

            // Initialize Uniform Variables
            displayShader.SetUniform("lastRenderResult", static_cast<int>(0));
            displayShader.SetUniform("screenGeometry",
                                    (unsigned int) width,
                                    (unsigned int) height);

            // Display Image on Screen
            glUseProgram(displayShader.GetShaderProgramID());
            glBindVertexArray(mesh.GetVAO());
            glDrawElements(GL_TRIANGLES, mesh.GetFacesLength(), GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);

            /*** End Display Image ***/


            // Swap Buffers and Pull Events
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    );
}
