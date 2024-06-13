/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include <vector>
#include <unordered_map>

#pragma once

#include "../blocks/Block.hpp"
#include "../maths/Vector.hpp"
#include "./biomes/Biome.hpp"
#include "PerlinNoise.hpp"

#include "../engine/3d/Model.hpp"

namespace OpenTerrain
{
    class World;
    class Chunk
    {
    public:
        Chunk(World &world, Vector3 pos);
        ~Chunk();

        void load();
        void unload();

        //Biome& getBiome() { return biome; }
        //void setBiome(Biome biome) { this->biome = biome; }

        std::unordered_map<Vector3, Block, Vector3::HashFunction>& getBlocks() { return m_blocks; }
        Block* getBlockAt(Vector3 pos);
        void updateBlocksToRender(std::unordered_map<Vector3, Block&, Vector3::HashFunction> &blocks);

        Vector3& getPosition() { return m_pos; }

        void render();

        static const int CHUNK_SIZE = 16;
        static const int CHUNK_HEIGHT = 30;

        inline static const float TREE_RATIO = 0.1;
    protected:
    private:
        World &m_world;
        //Biome biome;
        bool loaded = false;
        std::unordered_map<Vector3, Block, Vector3::HashFunction> m_blocks;
        Vector3 m_pos;

        std::list<std::pair<const Engine::Model *, Vector3>> m_trees;
    };

}