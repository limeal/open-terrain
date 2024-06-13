/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Water.hpp"
#include "../engine/3d/Cube.hpp"
#include "../render/ResourceManager.hpp"

OpenTerrain::Water::Water(Vector3 position) : Block(position, ResourceManager::writeDepthShader.get(), {0, 121, 241, 220})
{
    m_opaque = false;
}

OpenTerrain::Water::~Water()
{
}