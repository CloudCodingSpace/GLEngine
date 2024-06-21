#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class GECamera
{
public:
    GECamera();

    void Update(GLFWwindow* window);
    glm::mat4 GetProjMatrix(uint32_t width, uint32_t height);
    glm::mat4 GetBasicModelMatrix();
    glm::mat4 GetViewMatrix();
    glm::vec3 GetPos() { return pos; }

    float GetFOV() { return fov; }
    float GetNearPlane() { return near; }
    float GetFarPlane() { return far; }

    void UpdateFOV(float x) { fov += x; }
    void UpdateNearPlane(float x) { near += x; }
    void UpdateFarPlane(float x) { far += x; }
private:
    glm::mat4 proj, view;
    glm::vec3 pos, dir, up;
    float fov, near, far, yaw, pitch, lastX, lastY;
    const float speed = 0.005f;
    const float sensitivity = 0.1f;
    bool firstClick = true;
};