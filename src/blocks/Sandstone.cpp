/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Sandstone.hpp"

#include "../render/ResourceManager.hpp"

OpenTerrain::Sandstone::Sandstone(Vector3 position) :
    Block(position)
{
    setFaceTexture(Engine::Cube::Face::FRONT, OpenTerrain::ResourceManager::sandstoneTexture.get());
    setFaceTexture(Engine::Cube::Face::BACK, OpenTerrain::ResourceManager::sandstoneTexture.get());
    setFaceTexture(Engine::Cube::Face::LEFT, OpenTerrain::ResourceManager::sandstoneTexture.get());
    setFaceTexture(Engine::Cube::Face::RIGHT, OpenTerrain::ResourceManager::sandstoneTexture.get());
    setFaceTexture(Engine::Cube::Face::TOP, OpenTerrain::ResourceManager::sandstoneTopTexture.get());
    setFaceTexture(Engine::Cube::Face::BOTTOM, OpenTerrain::ResourceManager::sandstoneBottomTexture.get());
}

OpenTerrain::Sandstone::~Sandstone()
{
}