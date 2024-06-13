/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#pragma once

#include <memory>
#include <list>
#include <map>
#include <unordered_map>

#include "../engine/Texture.hpp"
#include "../engine/3d/Cube.hpp"
#include "../maths/Vector.hpp"
#include "../engine/3d/Camera.hpp"

namespace OpenTerrain
{
    class World;
    class Block
    {
    public:
        enum Material
        {
            AIR,
            DIRT,
            GRASS,
            STONE,
            SANDSTONE,
            SAND,
            WATER
        };

        Block(Vector3 position, Color color = WHITE);
        Block(Vector3 position, Engine::Shader *shader, Color color = WHITE);
        ~Block() = default;

        Vector3 &getPosition() { return m_position; }

        void setFaceTexture(Engine::Cube::Face face, Engine::Texture *texture);
    
        void render();

        Vector3 getLocalPosition() { return m_position; } // Chunk position
        void update(std::unordered_map<Vector3, Block&, Vector3::HashFunction> &blocks);

        bool isHidden() { return m_hidden; }
        void setHidden(bool hidden) { m_hidden = hidden; }

        bool isOpaque() { return m_opaque; }

        static Block fromMaterial(Material material, Vector3 position);

    protected:
        bool m_hidden = false;
        bool m_opaque = true;

        std::vector<Engine::Texture *> _textures;
        Vector3 m_position; // Chunk position
    private:
        Color m_color;
        Engine::Shader *m_shader;
    };
}