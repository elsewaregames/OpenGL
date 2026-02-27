#include "TestClearColor.h"

#include <glad/glad.h>

void TestClearColor::onRender()
{
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}