#pragma once

#include "../Test.h"

/*
--- PURPOSE ---
- Test index buffer correctness
- Create a rectanble with 2 triangles
```
0---1
|   |
2---3
```
- Indices
```
0,1,2
2,1,3
```

--- WHAT IT TESTS ---
- Correct index drawing
- No duplicated vertices
- Proper element buffer binding

--- EXPECTED ---
*/

class TestLargeIndexBuffer : public Test
{
  private:
  public:
};
