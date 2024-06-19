#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

class GEWindow
{
public:
    GEWindow(uint32_t width, uint32_t height, const std::string& title);

    uint32_t GetWidth() { return width; }
    uint32_t GetHeight() { return height; }
    GLFWwindow* GetHandle() { return window; }

    bool IsCloseButtonPressed() { return glfwWindowShouldClose(window); }

    void SetClearColor(float r, float g, float b, float a) { glClearColor(r, g, b, a); }

    void Show();
    void Clear();
    void Update();

    void Cleanup();
private:
    GLFWwindow* window;
    uint32_t width, height;
    std::string title;

    static void framesizecallback(GLFWwindow* window, int w, int h);
};