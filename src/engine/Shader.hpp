/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#pragma once

#include "Texture.hpp"

#include <iostream>
#include <raylib.h>
namespace OpenTerrain
{
    namespace Engine
    {
        class Shader
        {
        public:
            Shader(std::string path);
            ~Shader();

            ::Shader &getShader() { return m_shader; }
            int getID() { return m_shader.id; }
            void setValueTexture(const char *name, Texture *texture);

        protected:
        private:
            ::Shader m_shader;
            std::string m_path;
        };
    }
} // namespace OpenTerrainEngine
