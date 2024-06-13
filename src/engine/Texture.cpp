/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Texture.hpp"

OpenTerrain::Engine::Texture::Texture(std::string path) : m_path(path)
{
    std::cout << "Loading texture: " << path << std::endl;
    m_texture = LoadTexture(path.c_str());
}

OpenTerrain::Engine::Texture::~Texture()
{
    std::cout << "Unloading texture: " << m_path << std::endl;
    UnloadTexture(m_texture);
}
