/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Plain.hpp"
#include "Layer.hpp"

OpenTerrain::Plain::Plain(int32_t octaves) :
    Biome(PLAIN, octaves)
{
    m_layers.push_back(Layer({ Block::STONE }, 5, 100));
    m_layers.push_back(Layer({ Block::DIRT }, 2, 4));
    m_layers.push_back(Layer({ Block::GRASS }, 0, 1));
}

OpenTerrain::Plain::~Plain()
{
}
