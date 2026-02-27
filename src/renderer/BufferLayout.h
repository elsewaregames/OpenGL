#pragma once

#include <vector>

struct BufferElement
{
    unsigned int  count;
    unsigned int  type;
    unsigned char normalized;
};

class BufferLayout
{
  private:
    std::vector<BufferElement> m_elements;
    unsigned int               m_stride = 0;

  public:
    void                              pushFloat(unsigned int count);
    const std::vector<BufferElement>& getElements() const;
    unsigned int                      getStride() const;
};