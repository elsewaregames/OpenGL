#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Window
{
  private:
    GLFWwindow* m_window;

  public:
    Window(int width, int height, char* title);
    ~Window();

    bool shouldClose() const;
    void swapBuffers();
    void pollEvenets();
};