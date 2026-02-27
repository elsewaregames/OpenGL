#include "TestClearColor.h"

#include <glad/glad.h>

#include "../../renderer/Renderer.h"

#include <iostream>

TestClearColor::TestClearColor() : m_r(0.1f), m_g(0.2f), m_b(0.6f), m_a(1.0f)
{
}

TestClearColor::~TestClearColor()
{
}

void TestClearColor::onUpdate(float deltaTime)
{
    float speed = 1.5f;
    m_time += deltaTime * speed;

    m_r = 0.5f + 0.5f * std::sin(m_time);
    m_g = 0.5f + 0.5f * std::sin(m_time + 2.0f);
    m_b = 0.5f + 0.5f * std::sin(m_time + 4.0f);
}

void TestClearColor::onRender()
{
    Renderer renderer;

    glClearColor(m_r, m_g, m_b, m_a);
    renderer.clear();
}