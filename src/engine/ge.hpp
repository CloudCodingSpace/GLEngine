#pragma once

#define GE_STD_WINDOW_WIDTH      800
#define GE_STD_WINDOW_HEIGHT     600

#include <cstdint>
#include <string>

#include "window/ge_window.hpp"

class GLEngine
{
public:
    GLEngine(uint32_t width, uint32_t height, const std::string& title);

    void Run();
    void Cleanup();
private:
    GEWindow* window;
};