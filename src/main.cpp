#include "engine/output/window.hpp"

int main() {
    Window window(800, 600, "Vulkan Window");
    
    while (window.isRunning()) {
        glfwPollEvents();

        
    }
    
    return 0;
}