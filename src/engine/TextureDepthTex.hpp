/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#pragma once

#include <raylib.h>

namespace OpenTerrain
{
    namespace Engine
    {
        class TextureDepthTex
        {
        public:
            static RenderTexture2D LoadRender(int width, int height);
            static void UnloadRender(RenderTexture2D &target);
        };
    }
}
