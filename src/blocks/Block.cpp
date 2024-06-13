/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Block.hpp"
#include <raylib.h>
#include <iostream>
#include <filesystem>
#include <memory>
#include <unordered_map>
#include <stdexcept>

#include "../world/World.hpp"
#include "../render/ResourceManager.hpp"

#include "Dirt.hpp"
#include "Grass.hpp"
#include "Stone.hpp"
#include "Sandstone.hpp"
#include "Sand.hpp"
#include "Water.hpp"

OpenTerrain::Block::Block(Vector3 position, Color color)
    : m_hidden(false), m_opaque(true), m_position(position), _textures(6, nullptr), m_color(color), m_shader(nullptr)
{
}

OpenTerrain::Block::Block(Vector3 position, Engine::Shader *shader, Color color)
    : m_hidden(false), m_opaque(true), m_position(position), _textures(6, nullptr), m_color(color), m_shader(shader)
{
}

void OpenTerrain::Block::render()
{
    if (m_hidden) return;
    if (m_shader != nullptr) BeginShaderMode(m_shader->getShader());

    if (_textures.size() == 0 || _textures[0] == nullptr) {
        Engine::Cube::Draw(m_position, 1, 1, 1, m_color);
    } else
        Engine::Cube::DrawWithFaceTexture(_textures, m_position, 1, 1, 1, m_color);
    
    if (m_shader != nullptr) EndShaderMode();
}

void OpenTerrain::Block::setFaceTexture(Engine::Cube::Face face, Engine::Texture *texture)
{
    _textures[face] = texture;
    //_shader.setValueTexture(TextFormat("texture%i", face), texture);
}

void OpenTerrain::Block::update(std::unordered_map<Vector3, Block&, Vector3::HashFunction> &blocks)
{
    Vector3 position = m_position;
    Vector3 positionUp = Vector3(position.x(), position.y() + 1, position.z());
    Vector3 positionDown = Vector3(position.x(), position.y() - 1, position.z());
    Vector3 positionLeft = Vector3(position.x() - 1, position.y(), position.z());
    Vector3 positionRight = Vector3(position.x() + 1, position.y(), position.z());
    Vector3 positionFront = Vector3(position.x(), position.y(), position.z() + 1);
    Vector3 positionBack = Vector3(position.x(), position.y(), position.z() - 1);

    if (m_opaque) {
        if (
            (blocks.find(positionUp) != blocks.end() && blocks.at(positionUp).isOpaque()) &&
            (m_position.y() == 0 || (blocks.find(positionDown) != blocks.end() && blocks.at(positionDown).isOpaque())) &&
            (blocks.find(positionLeft) != blocks.end() && blocks.at(positionLeft).isOpaque()) &&
            (blocks.find(positionRight) != blocks.end() && blocks.at(positionRight).isOpaque()) &&
            (blocks.find(positionFront) != blocks.end() && blocks.at(positionFront).isOpaque()) &&
            (blocks.find(positionBack) != blocks.end() && blocks.at(positionBack).isOpaque())
        ) {
            m_hidden = true;
        } else {
            m_hidden = false;
        }
    } else {
        m_hidden = false;
    }
}

OpenTerrain::Block OpenTerrain::Block::fromMaterial(Material material, Vector3 position)
{
    switch (material)
    {
    case DIRT:
        return Dirt(position);
    case GRASS:
        return Grass(position);
    case STONE:
        return Stone(position);
    case SANDSTONE:
        return Sandstone(position);
    case SAND:
        return Sand(position);
    case WATER:
        return Water(position);
    default:
        throw std::runtime_error("Invalid material");
    }
}