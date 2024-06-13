/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include <math.h>

#include "Chunk.hpp"
#include "World.hpp"

#include "../blocks/Block.hpp"
#include "../blocks/Dirt.hpp"
#include "../blocks/Grass.hpp"
#include "../blocks/Stone.hpp"
#include "../render/ResourceManager.hpp"

OpenTerrain::Chunk::Chunk(World &world, Vector3 pos) :
    m_pos(pos),
    m_world(world)
{
    load();
}

OpenTerrain::Chunk::~Chunk()
{
}

void OpenTerrain::Chunk::updateBlocksToRender(std::unordered_map<Vector3, Block&, Vector3::HashFunction> &blocks)
{
    for (auto &pair: m_blocks)
        pair.second.update(blocks);
}

OpenTerrain::Block *OpenTerrain::Chunk::getBlockAt(Vector3 pos)
{
    if (m_blocks.find(pos) == m_blocks.end())
        return nullptr;
    return &m_blocks.at(pos);
}

void OpenTerrain::Chunk::load()
{
    if (loaded)
        return;

    int start_x = std::floor(-(CHUNK_SIZE / 2));
    int start_z = std::floor(-(CHUNK_SIZE / 2));
    int end_x = std::floor(CHUNK_SIZE / 2);
    int end_z = std::floor(CHUNK_SIZE / 2);

    for (int x = start_x; x < end_x; x++)
    {
        for (int z = start_z; z < end_z; z++)
        {
            int nx = x + (m_pos.x() * CHUNK_SIZE);
            int nz = z + (m_pos.z() * CHUNK_SIZE);
            double moisture = m_world.getNoise().octave2D_01(nx * 0.01, nz * 0.01, 4, 0.5);
            Biome biome = Biome::getBiomeFromMoisture(moisture);

            int height = static_cast<int>(m_world.getNoise().octave2D_01(nx * 0.05, nz * 0.05, biome.getOctaves(), 0.5) * CHUNK_HEIGHT);

            int y = 0;
            for (; y < height; y++)
                m_blocks.insert_or_assign(Vector3(nx, y, nz), Block::fromMaterial(biome.getLayer(height, y).getRandomBlock(), Vector3(nx, y, nz)));
            for (; y <= World::WATER_LEVEL; y++)
                m_blocks.insert_or_assign(Vector3(nx, y, nz), Block::fromMaterial(Block::Material::WATER, Vector3(nx, y, nz)));

            int tree = rand() % 1000;
            if (height > World::WATER_LEVEL && 5 > tree)
               m_trees.push_back(std::make_pair<Engine::Model *, Vector3>(ResourceManager::treeModel.get(), Vector3(nx, y, nz)));
        }
    }
    
    loaded = true;
}

void OpenTerrain::Chunk::unload()
{
    if (!loaded)
        return;
    m_blocks.clear();
    m_trees.clear();
    loaded = false;
}

void OpenTerrain::Chunk::render()
{
    for (auto &pair: m_blocks)
        pair.second.render();
    for (auto &pair: m_trees)
        pair.first->draw(pair.second, 0.3f);
}