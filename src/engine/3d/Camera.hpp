/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#pragma once

#include <raylib.h>
#include "../../maths/Vector.hpp"

namespace OpenTerrain
{
    namespace Engine
    {
        class Camera
        {
        public:

            Camera(Vector3 position, Vector3 target, Vector3 up, float fovy, int projectionType);
            ~Camera();

            Camera3D &getCamera() { return m_camera; }
            Vector3 getPosition();
            

            CameraMode getMode() const { return m_mode; }
            void update(CameraMode mode);
            void nextMode();

            void move(Vector3 position, bool relative = true);
            int getYaw();
            int getPitch();
            int getRoll();

        protected:
        private:
            ::Camera m_camera;
            CameraMode m_mode;
        };
    }
}