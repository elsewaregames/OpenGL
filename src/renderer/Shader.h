#pragma once

#include <string>
#include <unordered_map>

class Shader
{
  private:
    unsigned int m_rendererId;

    // Helpers
    std::string                                   readFile(const std::string& path);
    std::unordered_map<unsigned int, std::string> parseShader(const std::string& source);
    unsigned int compile(unsigned int type, const std::string& source);

  public:
    Shader(const std::string& filepath);
    ~Shader();

    void bind() const;
    void unbind() const;
};