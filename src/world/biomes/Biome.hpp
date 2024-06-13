/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include <map>
#include <vector>
#include "Layer.hpp"

#pragma once

namespace OpenTerrain
{
    class Biome
    {
    public:
        enum BiomeType
        {
            PLAIN
        };

        Biome(BiomeType id, int32_t octaves);
        ~Biome();

        static Biome getBiomeFromMoisture(double moisture);
        Layer &getLayer(int height, int y);

        int getId() { return m_id; }
        std::vector<Layer> getLayers() { return m_layers; }
        int32_t getOctaves() { return m_octaves; }

    protected:
        int m_id;
        std::vector<Layer> m_layers;
        int32_t m_octaves;
    private:
    };
}
