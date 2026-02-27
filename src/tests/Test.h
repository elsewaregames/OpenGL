#pragma once

class Test
{
  public:
    virtual ~Test() = default;
    virtual void onUpdate(float deltaTime) {};
    virtual void onRender() {};
};
