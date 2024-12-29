module;

#include "raylib.h"

export module Menu;

import std;
import IState;
import StateManager;
import Demo;

export class Menu final : public IState {
private:
    StateManager* _stateManager{&StateManager::GetInstance()};

public:
    // Constructor
    Menu() noexcept = default;

    // Destructor
    ~Menu() noexcept override = default;

    // Copy Constructor
    Menu(const Menu&) noexcept = default;

    // Copy Assignment Operator
    Menu& operator=(const Menu&) noexcept = default;

    // Move Constructor
    Menu(Menu&&) noexcept = default;

    // Move Assignment Operator
    Menu& operator=(Menu&&) noexcept = default;

    void Update(const float ms) noexcept override
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            _stateManager->PushState(std::make_unique<Demo>());
        }
    }

    void Draw() noexcept override
    {
        BeginDrawing();
        ClearBackground(WHITE);

        EndDrawing();
    }

    void Pause() noexcept override
    {
    }

    void Resume() noexcept override
    {
    }
};