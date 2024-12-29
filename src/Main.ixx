module;

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

export module Main;

import std;
import Menu;
import Demo;
import Game;
import StateManager;

export int main()
{
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Apollo");
    SetTargetFPS(60);

    InitAudioDevice();

    Game& game{Game::GetInstance()};
    StateManager& stateManager{StateManager::GetInstance()};

    // stateManager.PushState(std::make_unique<Menu>());
    stateManager.PushState(std::make_unique<Demo>());

    while (!WindowShouldClose())
    {
        const float deltaTime{GetFrameTime()};

        // Update logic
        game.Update(deltaTime);
        stateManager.Active->Update(deltaTime);

        // Draw logic
        game.Draw();
        stateManager.Active->Draw();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}