/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Shader.hpp"
OpenTerrain::Engine::Shader::Shader(std::string path)
    : m_path(path)
{
    m_shader = LoadShader(0, path.c_str());
}

OpenTerrain::Engine::Shader::~Shader()
{
    UnloadShader(m_shader);
}

void OpenTerrain::Engine::Shader::setValueTexture(const char *name, Texture *texture)
{
    SetShaderValueTexture(m_shader, GetShaderLocation(m_shader, name), texture->getTexture());
}