#include "ge_texture.hpp"

GETexture::GETexture(const std::string &path)
{
    stbi_set_flip_vertically_on_load(true);
    texels = stbi_load(path.c_str(), &width, &height, &channels, STBI_rgb_alpha);

    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texels);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(texels);
}

void GETexture::Activate(int texNum)
{
    glActiveTexture(GL_TEXTURE0 + texNum);
}

void GETexture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, ID);
}

void GETexture::Unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void GETexture::Cleanup()
{
    glDeleteTextures(1, &ID);
}