#pragma once

#include <cstdint>

#include "mesh/ge_mesh.hpp"
#include "shader/ge_shader.hpp"

class GERenderer
{
public:
    GERenderer();

    void Update();
    void Render(uint32_t with, uint32_t height);

    void Cleanup();
private:
    GEShader shader;
    GEMesh mesh;
};