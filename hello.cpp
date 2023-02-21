#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);

}

void redraw_window(GLFWwindow *window) {
     // Rendering code goes here
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}


int main()
{
    glfwInit();
    // glxinfo | grep "OpenGL version"
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create a window
    GLFWwindow *window = glfwCreateWindow(1920,1080, "Hello OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // mini modifications
    gladLoadGL();
    glViewport(0,0,1920,1080);
    redraw_window(window);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        redraw_window(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

