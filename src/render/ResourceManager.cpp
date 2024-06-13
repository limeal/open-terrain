/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "ResourceManager.hpp"

void OpenTerrain::ResourceManager::Init()
{
    grassTexture = std::make_unique<Engine::Texture>(TEXTURE_FOLDER + "grass.png");
    grassTextureTop = std::make_unique<Engine::Texture>(TEXTURE_FOLDER + "grass_top.png");
    dirtTexture = std::make_unique<Engine::Texture>(TEXTURE_FOLDER + "dirt.png");
    stoneTexture = std::make_unique<Engine::Texture>(TEXTURE_FOLDER + "stone.png");

    // cubeFacesShader = std::make_unique<Engine::Shader>("./shaders/cube_shader.fs");

    sandTexture = std::make_unique<Engine::Texture>(TEXTURE_FOLDER + "sand.png");
    sandstoneTexture = std::make_unique<Engine::Texture>(TEXTURE_FOLDER + "sandstone.png");
    sandstoneTopTexture = std::make_unique<Engine::Texture>(TEXTURE_FOLDER + "sandstone_top.png");
    sandstoneBottomTexture = std::make_unique<Engine::Texture>(TEXTURE_FOLDER + "sandstone_bottom.png");

    writeDepthShader = std::make_unique<Engine::Shader>(SHADER_FOLDER + "write_depth.fs");
    treeTexture = std::make_unique<Engine::Texture>(RESOURCE_FOLDER + "models/tree_texture.png");
    // waterTexture = std::make_unique<Engine::Texture>("./assets/water.png");
    treeModel = std::make_unique<Engine::Model>(RESOURCE_FOLDER + "models/tree.obj", std::vector<Engine::Texture *>{ treeTexture.get() });
}