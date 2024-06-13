/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include <vector>
#include "../../blocks/Block.hpp"

#pragma once

namespace OpenTerrain
{
    class Layer
    {
    public:
        Layer(
            std::vector<Block::Material> materials,
            int minDepth,
            int maxDepth
        );
        ~Layer();

        Block::Material getRandomBlock();

        std::vector<Block::Material> getMaterials() { return m_materials; }
        int getMinDepth() { return m_minDepth; }
        int getMaxDepth() { return m_maxDepth; }

    protected:
    private:
        std::vector<Block::Material> m_materials;
        int m_minDepth;
        int m_maxDepth;
    };
}