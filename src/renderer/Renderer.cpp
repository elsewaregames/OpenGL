#include "Renderer.h"

#include <glad/glad.h>

#include "IndexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"

void Renderer::clear() const
{
    glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader) const
{
    shader.bind();
    vao.bind();
    ibo.bind();

    glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, nullptr);
}