/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Desert.hpp"
#include "Layer.hpp"

OpenTerrain::Desert::Desert() :
    Biome(PLAIN, 1)
{
    m_layers.push_back(Layer({ Block::STONE }, 5, 100));
    m_layers.push_back(Layer({ Block::SANDSTONE }, 2, 4));
    m_layers.push_back(Layer({ Block::SAND }, 0, 1));
}

OpenTerrain::Desert::~Desert()
{
}
