#pragma once

#include "../Test.h"

#include "../../renderer/IndexBuffer.h"
#include "../../renderer/Shader.h"
#include "../../renderer/VertexArray.h"
#include "../../renderer/VertexBuffer.h"

class TestTriangle : public Test
{
  private:
    VertexArray   m_VAO;
    VertexBuffer* m_VBO;
    IndexBuffer*  m_IBO;
    Shader*       m_shader;

  public:
    TestTriangle();
    ~TestTriangle();

    void onRender() override;
};