#include "Application.h"

#include "../tests/test_clear_color/TestClearColor.h"
#include "../tests/test_triangle/TestTriangle.h"

Application::Application() : m_window(1280, 720, "elseware Games: OpenGL Workbench")
{
    // m_currentTest = std::make_unique<TestClearColor>();
    m_currentTest = std::make_unique<TestTriangle>();
}

Application::~Application()
{
}

void Application::run()
{
    while (!m_window.shouldClose())
    {
        m_currentTest->onUpdate(0.0f);
        m_currentTest->onRender();

        m_window.swapBuffers();
        m_window.pollEvenets();
    }
}
