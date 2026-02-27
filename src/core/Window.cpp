#include <glad/glad.h>

#include "Window.h"

#include <iostream>

Window::Window(int width, int height, char* title)
{
    if (!glfwInit())
        std::cerr << "Failed to init GLFW\n";

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!m_window)
    {
        std::cerr << "Window creation failed\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        std::cerr << "Failed to init GLAD\n";

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    glViewport(0, 0, width, height);
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

bool Window::shouldClose() const
{
    return glfwWindowShouldClose(m_window);
}

void Window::swapBuffers()
{
    glfwSwapBuffers(m_window);
}

void Window::pollEvenets()
{
    glfwPollEvents();
}