/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#pragma once

#include <iostream>
#include <raylib.h>

namespace OpenTerrain
{
    namespace Engine
    {
        class Texture
        {
        public:
            Texture(std::string path);
            ~Texture();

            Texture2D &getTexture() { return m_texture; }
            int getID() const { return m_texture.id; }

            int getWidth() const { return m_texture.width; }
            int getHeight() const { return m_texture.height; }

        protected:
        private:
            Texture2D m_texture;
            std::string m_path;
        };
    }
}