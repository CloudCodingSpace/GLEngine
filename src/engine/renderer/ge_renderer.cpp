#include "ge_renderer.hpp"

GERenderer::GERenderer()
{
    shader = new GEShader("shaders/default.vert", "shaders/default.frag");
}

void GERenderer::Update()
{

}

void GERenderer::Render(uint32_t with, uint32_t height)
{
    shader->Bind();
    shader->Unbind();
}

void GERenderer::Cleanup()
{
    shader->Cleanup();
}