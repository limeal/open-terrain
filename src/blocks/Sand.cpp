/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Sand.hpp"

#include "../render/ResourceManager.hpp"

OpenTerrain::Sand::Sand(Vector3 position) :
    Block(position)
{
    setFaceTexture(Engine::Cube::Face::FRONT, OpenTerrain::ResourceManager::sandTexture.get());
    setFaceTexture(Engine::Cube::Face::BACK, OpenTerrain::ResourceManager::sandTexture.get());
    setFaceTexture(Engine::Cube::Face::LEFT, OpenTerrain::ResourceManager::sandTexture.get());
    setFaceTexture(Engine::Cube::Face::RIGHT, OpenTerrain::ResourceManager::sandTexture.get());
    setFaceTexture(Engine::Cube::Face::TOP, OpenTerrain::ResourceManager::sandTexture.get());
    setFaceTexture(Engine::Cube::Face::BOTTOM, OpenTerrain::ResourceManager::sandTexture.get());
}

OpenTerrain::Sand::~Sand()
{
}