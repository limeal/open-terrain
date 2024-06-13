/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#pragma once

#include "Biome.hpp"

namespace OpenTerrain
{
    class Plain : public Biome
    {
    public:
        Plain(int32_t octaves = 1);
        ~Plain();

    protected:
    private:
    };
}
