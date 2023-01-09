#include <iostream>
#include <GLFW/glfw3.h>

int main()
{
    std::cout << "Hello World GL" << std::endl;
    if (!glfwInit())
    {
        // Initialization failed
    }
}