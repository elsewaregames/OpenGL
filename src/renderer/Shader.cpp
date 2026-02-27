#include "Shader.h"

#include <glad/glad.h>

#include <fstream>
#include <iostream>
#include <sstream>

static unsigned int getShaderTypeFromString(const std::string& type)
{
    if (type == "vertex")
        return GL_VERTEX_SHADER;
    if (type == "fragment")
        return GL_FRAGMENT_SHADER;
    return 0;
}

std::string Shader::readFile(const std::string& path)
{
    std::ifstream     stream(path);
    std::stringstream ss;
    ss << stream.rdbuf();

    return ss.str();
}

std::unordered_map<unsigned int, std::string> Shader::parseShader(const std::string& source)
{
    std::unordered_map<unsigned int, std::string> result;
    std::stringstream                             ss(source);
    std::string                                   line;

    unsigned int      type = 0;
    std::stringstream shaderStream[2];

    while (std::getline(ss, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                type = GL_VERTEX_SHADER;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                type = GL_FRAGMENT_SHADER;
            }
        }
        else
        {
            shaderStream[type == GL_VERTEX_SHADER ? 0 : 1] << line << "\n";
        }
    }

    result[GL_VERTEX_SHADER]   = shaderStream[0].str();
    result[GL_FRAGMENT_SHADER] = shaderStream[1].str();

    return result;
}

unsigned int Shader::compile(unsigned int type, const std::string& source)
{
    unsigned int id  = glCreateShader(type);
    const char*  src = source.c_str();

    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    return id;
}

Shader::Shader(const std::string& filepath)
{
    std::string source  = readFile(filepath);
    auto        shaders = parseShader(source);

    unsigned int program = glCreateProgram();

    unsigned int vs = compile(GL_VERTEX_SHADER, shaders[GL_VERTEX_SHADER]);
    unsigned int fs = compile(GL_FRAGMENT_SHADER, shaders[GL_FRAGMENT_SHADER]);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    m_rendererId = program;
}

Shader::~Shader()
{
    glDeleteProgram(m_rendererId);
}

void Shader::bind() const
{
    glUseProgram(m_rendererId);
}

void Shader::unbind() const
{
    glUseProgram(0);
}
