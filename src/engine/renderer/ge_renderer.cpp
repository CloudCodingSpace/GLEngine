#include "ge_renderer.hpp"

GERenderer::GERenderer()
{
    shader = GEShader("shaders/default.vert", "shaders/default.frag");

    std::vector<Vertex> vertices = {
        {{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},
        {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},
        {{0.0f,  0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}}
    };

    std::vector<unsigned int> indices = {
        0, 1, 2
    };

    mesh = GEMesh(vertices, indices);
}

void GERenderer::Update()
{

}

void GERenderer::Render(uint32_t with, uint32_t height)
{
    shader.Bind();
    mesh.Render();
    shader.Unbind();
}

void GERenderer::Cleanup()
{
    mesh.Cleanup();
    shader.Cleanup();
}