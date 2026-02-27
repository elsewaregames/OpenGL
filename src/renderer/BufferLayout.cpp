#include "BufferLayout.h"

#include <glad/glad.h>

void BufferLayout::pushFloat(unsigned int count)
{
    m_elements.push_back({count, GL_FLOAT, GL_FALSE});
    m_stride += count * sizeof(float);
}

const std::vector<BufferElement>& BufferLayout::getElements() const
{
    return m_elements;
}

unsigned int BufferLayout::getStride() const
{
    return m_stride;
}
