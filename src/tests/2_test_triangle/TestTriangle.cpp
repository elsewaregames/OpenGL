#include "TestTriangle.h"

#include <glad/glad.h>

#include "../../renderer/Renderer.h"

#include <iostream>

TestTriangle::TestTriangle()
{
    float vertices[] = {0.0f, 0.5f, 0.0f, 1.0f, 0.0f,  0.0f, -0.5f, -0.5f, 0.0f,
                        0.0f, 1.0f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f,  0.0f,  1.0f};

    unsigned int indices[] = {0, 1, 2};


    m_VBO = new VertexBuffer(vertices, sizeof(vertices));
    m_IBO = new IndexBuffer(indices, 3);

    BufferLayout layout;
    layout.pushFloat(3);
    layout.pushFloat(3);

    m_VAO.addBuffer(*m_VBO, layout);

    m_shader = new Shader("assets/shaders/basic.glsl");

    glEnable(GL_DEPTH_TEST);
}

TestTriangle::~TestTriangle()
{
    delete m_VBO;
    delete m_IBO;
    delete m_shader;
}

void TestTriangle::onRender()
{
    Renderer renderer;
    renderer.clear();
    renderer.draw(m_VAO, *m_IBO, *m_shader);
}