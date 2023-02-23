#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

void redraw_window(GLFWwindow *window)
{
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
    GLFWwindow *window = glfwCreateWindow(1920, 1080, "Hello OpenGL", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // init application
    gladLoadGL();

    // trangle we want to render
    float points[] = {
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f};

    // create VBO to store point information into buffer
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind the vbo buffer

    // // send the buffer to graphics card
    // // step 1: initialize a buffer store to store array buffer data with frequency of access set to "Draw"
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

    // write a simple vertex shader in glsl, and compile it dynamically in runtime

    const char *vertexShaderSource = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // check if shader is compiled successfully
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // create a fragment shader
    const char *fragShaderSource = "#version 330 core\n"
                                   "out vec4 frag_colour;\n"
                                   "void main() {"
                                   "  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
                                   "}";
    // create and compile fragment shader
    unsigned int fragShader; // store id of shader
    fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragShaderSource, NULL);
    glCompileShader(fragShader);
    // check if frag shader is setup correctly
    int isFragSuccess;
    char fragInfoLog[512];
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &isFragSuccess);
    if (!isFragSuccess)
    {
        glGetShaderInfoLog(fragShader, 512, NULL, fragInfoLog);
        std::cout << "Error frag shader not compiled successfully \n"
                  << fragInfoLog << "\n"
                  << std::endl;
    };

    glViewport(0, 0, 1920, 1080);
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
