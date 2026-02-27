#include "Application.h"

#include <GLFW/glfw3.h>

#include "../tests/test_clear_color/TestClearColor.h"
#include "../tests/test_triangle/TestTriangle.h"

Application::Application() : m_window(1280, 720, "elseware Games: OpenGL Workbench")
{
    m_currentTest = std::make_unique<TestClearColor>();
    // m_currentTest = std::make_unique<TestTriangle>();
}

Application::~Application()
{
}

void Application::run()
{
    float lastTime = 0.0f;

    while (!m_window.shouldClose())
    {
        float currentTime = glfwGetTime();
        float deltaTime   = currentTime - lastTime;
        lastTime          = currentTime;

        m_currentTest->onUpdate(deltaTime);
        m_currentTest->onRender();

        m_window.swapBuffers();
        m_window.pollEvenets();
    }
}
