/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include <list>
#include "Chunk.hpp"
#include <string>
#include <atomic>
#include "../engine/3d/Camera.hpp"

#pragma once
namespace OpenTerrain
{
    class World
    {
    public:
        World(int seed = rand() % 100000);
        ~World();

        void render();

        //void getBlocksInFrustum(OpenTerrain::Engine::Camera &camera);
        //std::list<Block &> getBlocks();
        Block* getBlockAt(Vector3 pos);
        Chunk* getChunkAt(Vector3 pos);

        void generate(std::atomic_int &dataProgress);
        void regenerate(std::atomic_int &dataProgress, int seed = rand() % 100000);

        int getSeed() { return m_seed; }
        siv::PerlinNoise& getNoise() { return m_perlin; }

        bool isLoaded() { return loaded; }

        inline static const int WATER_LEVEL = 10;
    protected:
    private:
        bool loaded = false;
        siv::PerlinNoise m_perlin;
        std::list<Chunk> m_chunks;
        std::unordered_map<Vector3, Block&, Vector3::HashFunction> m_blocks;
        int m_seed = 0;

        const int NB_CHUNKS = 9;
    };

}