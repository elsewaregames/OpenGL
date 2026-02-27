#pragma once

#include "../Test.h"

class TestClearColor : public Test
{
  private:
    float m_r;
    float m_g;
    float m_b;
    float m_a;
    float m_time;

  public:
    TestClearColor();
    ~TestClearColor();

    void onUpdate(float deltaTime) override;
    void onRender() override;
};
