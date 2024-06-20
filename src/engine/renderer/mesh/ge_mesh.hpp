#pragma once

#include <vector>
#include <string>
#include <glm/glm.hpp>

#include <glad/glad.h>

#include "../shader/ge_shader.hpp"
#include "ge_texture.hpp"

struct Vertex
{
    glm::vec3 pos;
    glm::vec2 coord;
};

class GEMesh
{
public:
    GEMesh() = default;
    GEMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::string& texPath);

    GETexture GetTexture() { return texture; }
    void Render(GEShader& shader);

    void Cleanup();
private:
    unsigned int vao, vbo, ebo, vertexCount;
    GETexture texture;
};