#include "VertexArray.h"

#include <glad/glad.h>

#include <iostream>

#include "VertexBuffer.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_rendererId);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_rendererId);
}

void VertexArray::addBuffer(const VertexBuffer& vb, const BufferLayout& layout)
{
    bind();
    vb.bind();

    const auto&  elements = layout.getElements();
    unsigned int offset   = 0;

    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];

        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized,
                              layout.getStride(), (const void*)(uintptr_t)offset);

        offset += element.count * sizeof(float);
    }
}

void VertexArray::bind() const
{
    glBindVertexArray(m_rendererId);
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
}
