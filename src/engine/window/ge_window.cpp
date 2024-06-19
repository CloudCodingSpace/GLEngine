#include "ge_window.hpp"

GEWindow::GEWindow(uint32_t width, uint32_t height, const std::string &title)
{
    this->width = width;
    this->height = height;
    this->title = title;

    if(!glfwInit()) {
        throw std::runtime_error("Failed to init GLFW!");
    }

    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow((int) width, (int) height, title.c_str(), nullptr, nullptr);
    if(window == nullptr) {
        throw std::runtime_error("Failed to create the window!");
    }
    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framesizecallback);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw std::runtime_error("Failed to load OpenGL!");
    }

    glViewport(0, 0, width, height);
}

void GEWindow::Show()
{
    glfwShowWindow(window);
}

void GEWindow::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GEWindow::Update()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void GEWindow::Cleanup()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void GEWindow::framesizecallback(GLFWwindow *window, int w, int h)
{
    GEWindow* win = reinterpret_cast<GEWindow*>(glfwGetWindowUserPointer(window));
    win->width = (uint32_t) w;
    win->height = (uint32_t) h;
}