#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class GEShader
{
public:
    GEShader() = default;
    GEShader(const std::string& vertPath, const std::string& fragPath);

    void Bind();
    void PutTexture(const std::string& name, int slot);
    void PutMat4(const std::string& name, glm::mat4& mat);
    void Unbind();

    void Cleanup();
private:
    unsigned int ID;

    std::string ReadShaderFile(const std::string& path);
};