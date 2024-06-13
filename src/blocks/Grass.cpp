/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Grass.hpp"

#include "../render/ResourceManager.hpp"

OpenTerrain::Grass::Grass(Vector3 position) :
    Block(position)
{
    setFaceTexture(Engine::Cube::Face::FRONT, OpenTerrain::ResourceManager::grassTexture.get());
    setFaceTexture(Engine::Cube::Face::BACK, OpenTerrain::ResourceManager::grassTexture.get());
    setFaceTexture(Engine::Cube::Face::LEFT, OpenTerrain::ResourceManager::grassTexture.get());
    setFaceTexture(Engine::Cube::Face::RIGHT, OpenTerrain::ResourceManager::grassTexture.get());
    setFaceTexture(Engine::Cube::Face::TOP, OpenTerrain::ResourceManager::grassTextureTop.get());
    setFaceTexture(Engine::Cube::Face::BOTTOM, OpenTerrain::ResourceManager::dirtTexture.get());
}

OpenTerrain::Grass::~Grass()
{
}