/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#pragma once

#include <raylib.h>
#include "Block.hpp"
#include "../engine/Shader.hpp"

namespace OpenTerrain
{
    class Water : public Block
    {
    public:
        Water(Vector3 position);
        ~Water();
    protected:
    private:
        Engine::Shader *m_shader;
    };
}