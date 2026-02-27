#pragma once

#include "../Test.h"

/*
--- PURPOSE ---
- Verify how depth buffer works

--- WHAT IT TESTS ---
- glEnable(GL_DEPTH_TEST)
- Depth buffer clear
- Z coordinate usage

--- EXPECTED ---
- Front triangle hides the back one
*/

class TestDepth : public Test
{
  private:
  public:
};
