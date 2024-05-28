// texture.cpp

#include "include/texture.hpp"

#include "../../third-party/glad/include/glad/glad.h"

Texture::Texture(int width,
                 int height,
                 GLint warp,
                 GLint filter,
                 GLint internalFormat,
                 GLenum format,
                 GLenum type,
                 const char *data):
                 
                 textureWidth(width),
                 textureHeight(height) {

    // Generate Texture
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Configure Texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, warp);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, warp);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);

    // Copy Data to Texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_FLOAT, data);

    // Unbind Texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture() {
    glDeleteTextures(1, &textureID);
}

int Texture::GetTextureWidth() const {
    return textureWidth;
}

int Texture::GetTextureHeight() const {
    return textureHeight;
}

unsigned int Texture::GetTextureID() const {
    return textureID;
}
