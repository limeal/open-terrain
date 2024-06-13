/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Stone.hpp"

#include "../render/ResourceManager.hpp"

OpenTerrain::Stone::Stone(Vector3 position) :
    Block(position)
{
    setFaceTexture(Engine::Cube::Face::FRONT, OpenTerrain::ResourceManager::stoneTexture.get());
    setFaceTexture(Engine::Cube::Face::BACK, OpenTerrain::ResourceManager::stoneTexture.get());
    setFaceTexture(Engine::Cube::Face::LEFT, OpenTerrain::ResourceManager::stoneTexture.get());
    setFaceTexture(Engine::Cube::Face::RIGHT, OpenTerrain::ResourceManager::stoneTexture.get());
    setFaceTexture(Engine::Cube::Face::TOP, OpenTerrain::ResourceManager::stoneTexture.get());
    setFaceTexture(Engine::Cube::Face::BOTTOM, OpenTerrain::ResourceManager::stoneTexture.get());
}

OpenTerrain::Stone::~Stone()
{
}