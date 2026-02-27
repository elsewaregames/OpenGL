#pragma once

#include <memory>

#include "../tests/Test.h"
#include "Window.h"

class Application
{
  private:
    Window                m_window;
    std::unique_ptr<Test> m_currentTest;

  public:
    Application();
    ~Application();

    void run();
};