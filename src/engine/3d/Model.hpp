/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#pragma once

#include "../Texture.hpp"
#include "../../maths/Vector.hpp"
#include <raylib.h>
#include <vector>

namespace OpenTerrain
{
    namespace Engine
    {
        class Model
        {
            public:
            Model(std::string file, std::vector<Texture *> texture);
            Model(std::string file, std::vector<Color> colors);
            Model(std::string file);
            ~Model();

            void draw(Vector3 position, float scale = 1) const;

            protected:
            private:
                ::Model m_model;
                BoundingBox m_bounds;
        }; // Add a semicolon here
    }
}