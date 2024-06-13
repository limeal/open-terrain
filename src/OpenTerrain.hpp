/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#pragma once

#include <raylib.h>
#include <string>
#include <memory>

#include "./engine/3d/Camera.hpp"
#include "./world/World.hpp"

namespace OpenTerrain
{
    class OpenTerrain
    {
    public:
        OpenTerrain(std::string title, int width, int height);
        ~OpenTerrain();

        void launch();

    protected:
    private:

        int m_width;
        int m_height;

        Engine::Camera m_camera;
        std::unique_ptr<World> m_world;
    };
}