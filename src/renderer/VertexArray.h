#pragma once

#include "BufferLayout.h"

class VertexBuffer;

class VertexArray
{
  private:
    unsigned int m_rendererId;

  public:
    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer& vb, const BufferLayout& layout);

    void bind() const;
    void unbind() const;
};