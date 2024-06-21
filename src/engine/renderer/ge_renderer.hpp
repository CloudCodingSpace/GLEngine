#pragma once

#include <cstdint>

#include "mesh/ge_mesh.hpp"
#include "shader/ge_shader.hpp"
#include "camera/ge_camera.hpp"

class GERenderer
{
public:
    GERenderer();

    void Update(GLFWwindow* window, uint32_t width, uint32_t height);
    void Render();

    void Cleanup();
private:
    GEShader shader;
    GEMesh mesh;
    GECamera camera;
    glm::mat4 pvm;
};