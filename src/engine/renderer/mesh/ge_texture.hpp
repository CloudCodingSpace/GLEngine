#pragma once

#include <string>
#include <stb/stb_image.h>

#include <glad/glad.h>

class GETexture
{
public:
    GETexture() = default;
    GETexture(const std::string& path);

    void Activate(int texNum);
    void Bind();
    void Unbind();

    int GetWidth() { return width; }
    int GetHeight() { return height; }
    int GetChannels() { return channels; }

    void Cleanup();
private:
    int width, height, channels;
    unsigned char* texels;
    unsigned int ID;
};