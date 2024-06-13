/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Dirt.hpp"

#include "../render/ResourceManager.hpp"

OpenTerrain::Dirt::Dirt(Vector3 position) :
    Block(position)
{
    setFaceTexture(Engine::Cube::Face::FRONT, OpenTerrain::ResourceManager::dirtTexture.get());
    setFaceTexture(Engine::Cube::Face::BACK, OpenTerrain::ResourceManager::dirtTexture.get());
    setFaceTexture(Engine::Cube::Face::LEFT, OpenTerrain::ResourceManager::dirtTexture.get());
    setFaceTexture(Engine::Cube::Face::RIGHT, OpenTerrain::ResourceManager::dirtTexture.get());
    setFaceTexture(Engine::Cube::Face::TOP, OpenTerrain::ResourceManager::dirtTexture.get());
    setFaceTexture(Engine::Cube::Face::BOTTOM, OpenTerrain::ResourceManager::dirtTexture.get());
}

OpenTerrain::Dirt::~Dirt()
{
}