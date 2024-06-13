/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Layer.hpp"

OpenTerrain::Layer::Layer(std::vector<Block::Material> materials, int minDepth, int maxDepth) :
    m_materials{materials},
    m_minDepth{minDepth},
    m_maxDepth{maxDepth}
{
}

OpenTerrain::Layer::~Layer()
{
}

OpenTerrain::Block::Material OpenTerrain::Layer::getRandomBlock()
{
    int random = std::rand() % m_materials.size();
    return m_materials[random];
} 
