/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "World.hpp"
#include "PerlinNoise.hpp"

#include <math.h>
#include <iostream>
#include <stdexcept>

OpenTerrain::World::World(int seed) : m_seed(seed), m_perlin(seed)
{
}

OpenTerrain::World::~World()
{
}

void OpenTerrain::World::generate(std::atomic_int &dataProgress)
{
    int nb_chunks_x = std::sqrt(NB_CHUNKS);
    int nb_chunks_y = std::sqrt(NB_CHUNKS);

    int start_x = std::floor(-(nb_chunks_x / 2));
    int start_y = std::floor(-(nb_chunks_y / 2));
    int end_x = std::floor(nb_chunks_x / 2);
    int end_y = std::floor(nb_chunks_y / 2);

    for (int x = start_x; x <= end_x; x++)
        for (int y = start_y; y <= end_y; y++) {
            m_chunks.push_back(Chunk(*this, Vector3(x, 1, y)));
            dataProgress++;
        }

    for (auto &chunk: m_chunks)
        for (auto &pair: chunk.getBlocks()) 
            m_blocks.insert_or_assign(pair.first, pair.second);

    for (Chunk &chunk : m_chunks) {
        chunk.updateBlocksToRender(m_blocks);
        dataProgress++;
    }

    loaded = true;
}

void OpenTerrain::World::regenerate(std::atomic_int &dataProgress, int seed)
{
    m_seed = seed;
    std::cout << "Remove block reference" << std::endl;
    m_blocks.clear();
    std::cout << "Unload chunks" << std::endl;
    for (Chunk &chunk : m_chunks)
        chunk.unload();
    std::cout << "Reseeding" << std::endl;
    m_perlin.reseed(seed);
    generate(dataProgress);
}

OpenTerrain::Chunk* OpenTerrain::World::getChunkAt(Vector3 pos)
{
    for (Chunk &chunk : m_chunks)
    {
        if (chunk.getPosition().x() == pos.x() && chunk.getPosition().y() == pos.y() && chunk.getPosition().z() == pos.z())
            return &chunk;
    }
    return nullptr;
}

OpenTerrain::Block* OpenTerrain::World::getBlockAt(Vector3 pos)
{
    for (Chunk &chunk : m_chunks)
    {
        Block *block = chunk.getBlockAt(pos);
        if (block != nullptr)
            return block;
    }
    return nullptr;
}


void OpenTerrain::World::render()
{
    for (Chunk &chunk : m_chunks)
        chunk.render();
}