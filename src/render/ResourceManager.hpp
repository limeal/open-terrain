/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#pragma once

#include <memory>
#include <string>

#include "../engine/Texture.hpp"
#include "../engine/Shader.hpp"
#include "../engine/3d/Model.hpp"

namespace OpenTerrain
{
    class ResourceManager
    {
        public:
            // Blocks
            inline static std::unique_ptr<Engine::Texture> grassTexture = nullptr;
            inline static std::unique_ptr<Engine::Texture> grassTextureTop = nullptr;

            inline static std::unique_ptr<Engine::Texture> dirtTexture = nullptr;
            inline static std::unique_ptr<Engine::Texture> stoneTexture = nullptr;

            inline static std::unique_ptr<Engine::Texture> sandTexture = nullptr;

            inline static std::unique_ptr<Engine::Texture> sandstoneTexture = nullptr;
            inline static std::unique_ptr<Engine::Texture> sandstoneTopTexture = nullptr;
            inline static std::unique_ptr<Engine::Texture> sandstoneBottomTexture = nullptr;

            inline static std::unique_ptr<Engine::Texture> waterTexture = nullptr;

            inline static std::unique_ptr<Engine::Shader> writeDepthShader = nullptr;
            //inline static std::unique_ptr<Engine::Shader> cubeFacesShader = nullptr;

            inline static std::unique_ptr<Engine::Texture> treeTexture = nullptr;
            inline static std::unique_ptr<Engine::Model> treeModel = nullptr;

            static void Init();
        private:
            inline static std::string RESOURCE_FOLDER = "resources/";
            inline static std::string SHADER_FOLDER = RESOURCE_FOLDER+"shaders/";
            inline static std::string TEXTURE_FOLDER = RESOURCE_FOLDER+"textures/";
    };

}