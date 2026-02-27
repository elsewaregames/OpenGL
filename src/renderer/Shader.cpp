#include "Shader.h"

#include <glad/glad.h>

#include <fstream>
#include <iostream>
#include <sstream>

static const char* shaderTypeToString(unsigned int type)
{
    switch (type)
    {
    case GL_VERTEX_SHADER:
        return "VERTEX";
    case GL_FRAGMENT_SHADER:
        return "FRAGMENT";
    default:
        return "UNKNOWN";
    }
}

std::string Shader::readFile(const std::string& path)
{
    std::ifstream stream(path);

    if (!stream.is_open())
    {
        std::cerr << "Error could not open shader file: " << path << std::endl;
        return "";
    }

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
            if (type == GL_VERTEX_SHADER)
            {
                shaderStream[0] << line << "\n";
            }
            else if (type == GL_FRAGMENT_SHADER)
            {
                shaderStream[1] << line << "\n";
            }
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

    if (!checkCompileErrors(id, type))
    {
        glDeleteShader(id);
        return 0;
    }

    return id;
}

bool Shader::checkCompileErrors(unsigned int shader, unsigned int type)
{
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        int length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

        std::vector<char> message(length);
        glGetShaderInfoLog(shader, length, nullptr, message.data());

        std::cerr << "-------------------\n";
        std::cerr << "(SHADER COMPILATION ERROR (" << shaderTypeToString(type) << ")\n";
        std::cerr << message.data() << std::endl;
        std::cerr << "-------------------\n";

        return false;
    }

    return true;
}

bool Shader::checkLinkErrors(unsigned int program)
{
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (!success)
    {
        int length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

        std::vector<char> message(length);
        glGetProgramInfoLog(program, length, nullptr, message.data());

        std::cerr << "-------------------\n";
        std::cerr << "PROGRAM LINK ERROR\n";
        std::cerr << message.data() << std::endl;
        std::cerr << "-------------------\n";

        return false;
    }

    return true;
}

Shader::Shader(const std::string& filepath)
{
    std::string source = readFile(filepath);
    if (source.empty())
        return;

    auto shaders = parseShader(source);

    unsigned int vs = compile(GL_VERTEX_SHADER, shaders[GL_VERTEX_SHADER]);
    unsigned int fs = compile(GL_FRAGMENT_SHADER, shaders[GL_FRAGMENT_SHADER]);

    if (!vs || !fs)
        return;

    unsigned int program = glCreateProgram();

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    if (!checkLinkErrors(program))
    {
        glDeleteProgram(program);
        return;
    }

    glDeleteShader(vs);
    glDeleteShader(fs);

    m_rendererId = program;

    std::cout << "Shader loaded successfully: " << filepath << std::endl;
}

Shader::~Shader()
{
    if (m_rendererId)
        glDeleteProgram(m_rendererId);
}

void Shader::bind() const
{
    if (m_rendererId)
        glUseProgram(m_rendererId);
}

void Shader::unbind() const
{
    glUseProgram(0);
}

bool Shader::isValid() const
{
    return m_rendererId != 0;
}