/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "Model.hpp"

OpenTerrain::Engine::Model::Model(std::string file, std::vector<Texture *> textures)
{
    m_model = LoadModel(file.c_str());
    for (int i = 0; i < textures.size(); i++)
        m_model.materials[i].maps[MATERIAL_MAP_DIFFUSE].texture = textures[i]->getTexture();
    m_bounds = GetMeshBoundingBox(m_model.meshes[0]);
}

OpenTerrain::Engine::Model::Model(std::string file, std::vector<Color> colors)
{
    m_model = LoadModel(file.c_str());
    for (int i = 0; i < colors.size(); i++)
        m_model.materials[i].maps[MATERIAL_MAP_DIFFUSE].color = colors[i];
    m_bounds = GetMeshBoundingBox(m_model.meshes[0]);
}

OpenTerrain::Engine::Model::Model(std::string file)
{
    m_model = LoadModel(file.c_str());
    m_bounds = GetMeshBoundingBox(m_model.meshes[0]);
}

OpenTerrain::Engine::Model::~Model()
{
    UnloadModel(m_model);
}

void OpenTerrain::Engine::Model::draw(Vector3 position, float scale) const
{
    DrawModel(m_model, ~position, scale, WHITE);
}