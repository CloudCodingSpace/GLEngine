#include "ge_renderer.hpp"

GERenderer::GERenderer()
{
    std::vector<Vertex> vertices = {
        {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f}},
        {{0.5f, -0.5f, 0.0f}, {1.0f, 0.0f}},
        {{0.0f,  0.5f, 0.0f}, {0.5f, 1.0f}}
    };

    std::vector<unsigned int> indices = {
        0, 1, 2
    };

    shader = GEShader("shaders/default.vert", "shaders/default.frag");
    mesh = GEMesh(vertices, indices, "assets/textures/face.png");
}

void GERenderer::Update()
{

}

void GERenderer::Render(uint32_t with, uint32_t height)
{
    shader.Bind();
    mesh.Render(shader);
    shader.Unbind();
}

void GERenderer::Cleanup()
{
    mesh.Cleanup();
    shader.Cleanup();
}