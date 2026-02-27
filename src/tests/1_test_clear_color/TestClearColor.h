#pragma once

#include "../Test.h"

/*
--- PURPOSE ---
- Verify render loop works
- Verify clear color changes
- No VOA required

--- WHAT IT TESTS ---
- Renderer::clear()
- glClearColor behaviour

--- EXPECTED ---
*/ 

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
