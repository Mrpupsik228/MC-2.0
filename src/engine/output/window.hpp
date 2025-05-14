#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <vulkan/vulkan.hpp>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool isRunning();

private:
    bool mIsRunning = true;
    GLFWwindow* handle;

    int width, height;
    const char* title;

    VkInstance instance;

    std::vector<const char*> requiredExtensions;
    
    void createInstance();
    void initVulkan();
    void initWindow();

    void cleanUp();
};
