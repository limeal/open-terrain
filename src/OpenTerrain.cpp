/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include "OpenTerrain.hpp"
#include "./world/World.hpp"

#include <time.h>
#include <string>

#include <GL/gl.h>

#include "./render/ResourceManager.hpp"
#include "./engine/TextureDepthTex.hpp"
#include "./engine/3d/Model.hpp"

#include <atomic>
#include <pthread.h>

OpenTerrain::OpenTerrain::OpenTerrain(
    std::string title,
    int width,
    int height) : m_width(width),
                  m_height(height),
                  m_camera(Vector3(45.0f, 70.0f, 45.0f), Vector3(0.0f, 0.5f, 0.0f), Vector3(0.0f, 1.0f, 0.0f), 45.0f, CAMERA_PERSPECTIVE)
{
    InitWindow(width, height, title.c_str());
    // Set fullscreen

    ResourceManager::Init();
}

OpenTerrain::OpenTerrain::~OpenTerrain()
{
    //CloseWindow();
}

static std::atomic_bool dataLoaded = false;
static std::atomic_int dataProgress = 0;


static void *LoadWorld(void *w)
{
    int timeCounter = 0;            // Time counted in ms
    clock_t prevTime = clock();     // Previous time
    OpenTerrain::World *world = (OpenTerrain::World *)w;

    if (world->isLoaded()) {
        std::cout << "REGENERATE WORLD" << std::endl;
        world->regenerate(dataProgress);
    } else
        world->generate(dataProgress);

    // When data has finished loading, we set global variable
    atomic_store_explicit(&dataLoaded, true, std::memory_order_relaxed);
    return NULL;
}

void OpenTerrain::OpenTerrain::launch()
{
    bool lock = false;
    srand(time(NULL));

    double octaves = 4;
    double persistence = 0.5;

    // TODO:
    //  - Add lightnings
    //  - Push to github

    RenderTexture2D target = Engine::TextureDepthTex::LoadRender(m_width, m_height);
    Shader shader = LoadShader(0, TextFormat("resources/shaders/write_depth.fs"));
    
    m_world = std::make_unique<World>();
    pthread_t threadId = { 0 };
    enum { STATE_WAITING, STATE_LOADING, STATE_FINISHED } state = STATE_WAITING;
    int framesCounter = 0;
    
    DisableCursor();
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        m_camera.update(m_camera.getMode());

        switch (state)
        {
            case STATE_WAITING:
            {
                    int error = pthread_create(&threadId, NULL, &LoadWorld, m_world.get());
                    if (error != 0) TraceLog(LOG_ERROR, "Error creating loading thread");
                    else TraceLog(LOG_INFO, "Loading thread initialized successfully");

                    state = STATE_LOADING;
            } break;
            case STATE_LOADING:
            {
                framesCounter++;
                if (atomic_load_explicit(&dataLoaded, std::memory_order_relaxed))
                {
                    framesCounter = 0;
                    int error = pthread_join(threadId, NULL);
                    if (error != 0) TraceLog(LOG_ERROR, "Error joining loading thread");
                    else TraceLog(LOG_INFO, "Loading thread terminated successfully");

                    state = STATE_FINISHED;
                }
            } break;
            case STATE_FINISHED:
            {
                if (IsKeyPressed(KEY_R))
                {
                    // Reset everything to launch again
                    atomic_store_explicit(&dataLoaded, false, std::memory_order_relaxed);
                    atomic_store_explicit(&dataProgress, 0, std::memory_order_relaxed);
                    state = STATE_WAITING;
                }
            } break;
            default: break;
        }

        // 3D world drawing
        if (state == STATE_FINISHED)
        {

            if (IsKeyDown(KEY_LEFT_SHIFT))
                m_camera.move(Vector3(0.0f, -1, 0.0f));
            if (IsKeyDown(KEY_SPACE))
                m_camera.move(Vector3(0.0f, 1, 0.0f));
            BeginTextureMode(target);
                ClearBackground(WHITE);
                BeginMode3D(m_camera.getCamera());
                    m_world->render();
                    DrawGrid(100, 1.0f);
                EndMode3D();
            EndTextureMode();
        }

        BeginDrawing();
            switch (state)
            {
                case STATE_WAITING:
                case STATE_LOADING:
                {
                    ClearBackground(BLACK);

                    int marginX = 100;
                    int progressBarWidth = (m_width - marginX*2);
                    int progressBarMultiplier = state == STATE_LOADING ? progressBarWidth/18 : 0;
                    std::string loadingtext = state == STATE_LOADING ? "GENERATING WORLD..." : "REGENERATING TRIGGERED";
                    int fontSize = 40;
                    int barHeight = 60;

                    DrawRectangle(marginX, m_height/2-barHeight/2, (atomic_load_explicit(&dataProgress, std::memory_order_relaxed)%18)*progressBarMultiplier, barHeight, RED);
                    if ((framesCounter/15)%2) DrawText(loadingtext.c_str(), marginX + ((progressBarWidth/2) - (loadingtext.size()/2)*(fontSize/1.5)), m_height/2-fontSize/2, fontSize, WHITE);
                    DrawRectangleLines(marginX, m_height/2-barHeight/2, progressBarWidth, barHeight, BLUE);

                } break;
                case STATE_FINISHED:
                {
                    ClearBackground(RAYWHITE);

                    DrawTextureRec(target.texture, (Rectangle){0, 0, (float)m_width, (float)-m_height}, {0, 0}, WHITE);

                    DrawText(("Seed: " + std::to_string(m_world->getSeed())).c_str(), 10, 10, 20, DARKGRAY);
                    DrawText("Press R to regenerate", 10, 30, 20, DARKGRAY);
                    DrawText(("Coordinates: " + m_camera.getPosition().toString()).c_str(), 10, 80, 20, DARKGRAY);
                    DrawText(("Yaw: " + std::to_string(m_camera.getYaw())).c_str(), 10, 100, 20, DARKGRAY);
                    DrawText(("Pitch: " + std::to_string(m_camera.getPitch())).c_str(), 10, 120, 20, DARKGRAY);
                    DrawText(("Roll: " + std::to_string(m_camera.getRoll())).c_str(), 10, 140, 20, DARKGRAY);
                    DrawFPS(m_width - 100, 10);
                } break;
                default: break;
            }
        EndDrawing();
    }

    Engine::TextureDepthTex::UnloadRender(target);
    //CloseWindow();
}