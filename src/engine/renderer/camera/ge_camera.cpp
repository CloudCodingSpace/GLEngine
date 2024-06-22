#include "ge_camera.hpp"

GECamera::GECamera()
{
    yaw = -90.0f;
    pitch = 1.0f;
    fov = 90.0f;
    near = 0.01f;
    far = 100.0f;
    lastX = 0.0f;
    lastY = 0.0f;
    firstClick = true;

    view = glm::mat4(1.0f);
    proj = glm::mat4(1.0f);
    pos = glm::vec3(0.0f, 0.0f, 3.0f);
    dir = glm::vec3(0.0f, 0.0f, -1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
}

void GECamera::Update(GLFWwindow *window)
{
    // Key inputs
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        pos += dir * speed;
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        pos -= glm::normalize(glm::cross(dir, up)) * speed;
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        pos -= dir * speed;
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        pos += glm::normalize(glm::cross(dir, up)) * speed;
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        pos.y -= speed * 0.25f;
    }
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        pos.y += speed * 0.25;
    }
    // Mouse inputs
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {

        double crntX = 0;
        double crntY = 0;
        glfwGetCursorPos(window, &crntX, &crntY);

        if(firstClick) {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            lastX = crntX;
            lastY = crntY;
            firstClick = false;
        }
        else {
            float xoffset = crntX - lastX;
            float yoffset = lastY - crntY;
            lastX = crntX;
            lastY = crntY;

            xoffset *= sensitivity;
            yoffset *= sensitivity;

            yaw += xoffset;
            pitch += yoffset;

            if(pitch > 90.0f)
                pitch = -90.0f;
            if(pitch < -90.0f)
                pitch = 90.0f;

            dir.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
            dir.y = sin(glm::radians(pitch));
            dir.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
            dir = glm::normalize(dir);
        }
    }
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        firstClick = true;
    }
}

glm::mat4 GECamera::GetProjMatrix(uint32_t width, uint32_t height)
{
    if(width == 0 || height == 0) {
        width = 1;
        height = 1;
    }
    proj = glm::perspective(glm::radians(fov), (float)width/(float)height, near, far);

    return proj;
}

glm::mat4 GECamera::GetBasicModelMatrix()
{
    return glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 2.0f));
}

glm::mat4 GECamera::GetViewMatrix()
{
    view = glm::lookAt(pos, pos + dir, up);

    return view;
}
