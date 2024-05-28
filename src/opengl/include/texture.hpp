// texture.hpp

#pragma once

#include "../../../third-party/glad/include/glad/glad.h"

class Texture {
    public:
        Texture(int width,
                int height,
                GLint warp,
                GLint filter,
                GLint internalFormat,
                GLenum format,
                GLenum type,
                const char *data);
        ~Texture();

        int GetTextureWidth() const;
        int GetTextureHeight() const;
        unsigned int GetTextureID() const;

    private:
        int textureWidth, textureHeight;
        unsigned int textureID;
};
