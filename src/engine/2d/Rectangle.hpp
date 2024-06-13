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
        class Rectangle
        {
        public:
            Rectangle(float x, float y, float width, float height) : m_rectangle{x, y, width, height} {}
            ~Rectangle() = default;

            ::Rectangle &getRectangle() { return m_rectangle; }

            float getX() { return m_rectangle.x; }
            float getY() { return m_rectangle.y; }
            float getWidth() { return m_rectangle.width; }
            float getHeight() { return m_rectangle.height; }

        protected:
        private:
            ::Rectangle m_rectangle;
        };
    }
}