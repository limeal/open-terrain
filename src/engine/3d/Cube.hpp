/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#pragma once

#include "../Texture.hpp"
#include "../Shader.hpp"
#include "../2d/Rectangle.hpp"
#include "../../maths/Vector.hpp"

namespace OpenTerrain
{
    namespace Engine
    {
        class Cube
        {
        public:
            enum Face : unsigned int
            {
                FRONT,
                BACK,
                LEFT,
                RIGHT,
                TOP,
                BOTTOM
            };

            Cube() = default;
            ~Cube() = default;

            static void Draw(Vector3 position, float width, float height, float length, Color color);
            static void DrawWithTexture(const Texture &texture, Vector3 position, float width, float height, float length, Color color);
            static void DrawWithTextureRect(const Texture &texture, Rectangle source, Vector3 position, float width, float height, float length, Color color);

            static void DrawWithFaceTexture(const std::vector<Engine::Texture *> textures, Vector3 position, float width, float height, float length, Color color);

        protected:
        private:
        };
    }

} // namespace OpenTerrainEngine