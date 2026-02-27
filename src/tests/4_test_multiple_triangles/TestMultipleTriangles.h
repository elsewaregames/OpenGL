#pragma once

#include "../Test.h"

/*
--- PURPOSE ---
- Render multiple VOAs in same frame

--- WHAT IT TESTS ---
- Multiple draw calls
- State binding isolation
- No cross-VAO corruption

--- EXPECTED ---
- Render triangle1(left) and triangle2(right)
*/

class TestMultipleTriangles : public Test
{
  private:
  public:
};
