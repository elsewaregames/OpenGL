#pragma once

class VertexArray;
class IndexBuffer;
class Shader;

class Renderer
{
  public:
    void clear() const;
    void draw(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader) const;
};