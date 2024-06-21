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

void GERenderer::Update(GLFWwindow* window, uint32_t width, uint32_t height)
{
    camera.Update(window);
    shader.Bind();
    pvm = camera.GetProjMatrix(width, height) * camera.GetViewMatrix() * camera.GetBasicModelMatrix();
    shader.PutMat4("pvm", pvm);
    shader.Unbind();
}

void GERenderer::Render()
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