#pragma once

#include <vector>
#include <glm/glm.hpp>

#include <glad/glad.h>

struct Vertex
{
    glm::vec3 pos;
    glm::vec3 color;
};

class GEMesh
{
public:
    GEMesh() = default;
    GEMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

    void Render();

    void Cleanup();
private:
    unsigned int vao, vbo, ebo, vertexCount;
};