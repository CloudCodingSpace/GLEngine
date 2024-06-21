#include "ge.hpp"

GLEngine::GLEngine(uint32_t width, uint32_t height, const std::string &title)
{
    window = new GEWindow(width, height, title);
    renderer = new GERenderer();
}

void GLEngine::Run()
{
    window->Show();
    window->SetClearColor(0.5f, 0.5f, 0.5f, 0.5f);
    while(!window->IsCloseButtonPressed()) {
        window->Clear();
        renderer->Update(window->GetHandle(), window->GetWidth(), window->GetHeight());
        renderer->Render();
        window->Update();
    }
}

void GLEngine::Cleanup()
{
    window->Cleanup();
}