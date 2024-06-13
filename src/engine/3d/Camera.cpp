/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Camera.hpp"
#include <iostream>

OpenTerrain::Engine::Camera::Camera(OpenTerrain::Vector3 position, OpenTerrain::Vector3 target, OpenTerrain::Vector3 up, float fovy, int projectionType) :
    m_camera{::Camera{~position, ~target, ~up, fovy, projectionType}}, m_mode(CameraMode::CAMERA_ORBITAL)
{
}

OpenTerrain::Engine::Camera::~Camera()
{
}

void OpenTerrain::Engine::Camera::update(CameraMode mode)
{
    UpdateCamera(&m_camera, mode);
}

void OpenTerrain::Engine::Camera::move(OpenTerrain::Vector3 position, bool relative)
{
    if (relative)
        m_camera.position = ~Vector3(m_camera.position.x + position.x(), m_camera.position.y + position.y(), m_camera.position.z + position.z());
    else
        m_camera.position = ~position;
}

int OpenTerrain::Engine::Camera::getYaw()
{
    return m_camera.target.x;
}

int OpenTerrain::Engine::Camera::getPitch()
{
    return m_camera.target.y;
}

int OpenTerrain::Engine::Camera::getRoll()
{
    return m_camera.target.z;
}

OpenTerrain::Vector3 OpenTerrain::Engine::Camera::getPosition()
{
    return OpenTerrain::Vector3(m_camera.position.x, m_camera.position.y, m_camera.position.z);
}