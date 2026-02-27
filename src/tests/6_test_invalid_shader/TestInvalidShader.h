#pragma once

#include "../Test.h"

/*
--- PURPOSE ---
- Verify shader error logging works
- Suppose a broken GLSL like following
```
#shader vertex
#version 330 core
invalid syntax here
```

--- WHAT IT TESTS ---
- Compile error handling
- Link error handling

--- EXPECTED ---
- Console error
- No crash
- Program not used
*/

class TestLargeIndexBuffer : public Test
{
  private:
  public:
};
