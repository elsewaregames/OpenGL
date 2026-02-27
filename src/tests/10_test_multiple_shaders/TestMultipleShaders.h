#pragma once

#include "../Test.h"

/*
--- PURPOSE ---
- Switch shaders mid-frame

--- WHAT IT TESTS ---
- Shader binding isolation
- Program switching correctness

--- EXPECTED ---
- Render triangle1 -> shader1 and triangle2 -> shader2
*/

class TestMultipleShaders : public Test
{
  private:
  public:
};
