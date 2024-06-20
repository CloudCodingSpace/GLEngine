#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

#include <glad/glad.h>

class GEShader
{
public:
    GEShader() = default;
    GEShader(const std::string& vertPath, const std::string& fragPath);

    void Bind();
    void Unbind();

    void Cleanup();
private:
    unsigned int ID;

    std::string ReadShaderFile(const std::string& path);
};