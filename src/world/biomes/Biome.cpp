/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Biome.hpp"
#include "Plain.hpp"
#include "Desert.hpp"
#include "Mountain.hpp"

#include <algorithm>

OpenTerrain::Biome::Biome(BiomeType id,
            int32_t octaves) :
    m_id{id},
    m_octaves{octaves}
{
}

OpenTerrain::Biome::~Biome()
{
}

OpenTerrain::Biome OpenTerrain::Biome::getBiomeFromMoisture(double moisture)
{
    // Available biomes: Plain, Desert

    if (moisture < 0.2)
        return Desert();

    if (moisture < 0.7)
        return Plain();

    return Mountain();
}

OpenTerrain::Layer &OpenTerrain::Biome::getLayer(int height, int y)
{
    for (auto &layer : m_layers) {
        int maxDepth = height - layer.getMinDepth();
        int minDepth = height - layer.getMaxDepth();
        if (y >= minDepth && y <= maxDepth) {
            return layer;
        }
    }
    return m_layers[0];
}