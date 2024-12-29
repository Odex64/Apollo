module;

#include "raylib.h"

export module Demo;

import std;
import IState;
import BaseMoon;
import BaseGalaxy;
import BasePlanet;
import BaseStar;
import SpaceCamera;
import BaseSpace;

export class Demo final : public IState {
private:
    BaseGalaxy _galaxy{};
    // std::vector<BaseSpace> _stars{};

    std::shared_ptr<SpaceCamera> _camera{nullptr};

public:
    // Constructor
    Demo() noexcept
    {
        const auto& star{_galaxy.AddStar(std::make_unique<BaseStar>(1.0f, YELLOW))};
        _camera = std::make_shared<SpaceCamera>(star->Position);

        const auto& planet{star->AddPlanet(std::make_unique<BasePlanet>(0.3f, BLUE, 6.0f, 1.0f, 0.0f))};
        planet->AddMoon(std::make_unique<BaseMoon>(0.08f, RED, 1.0f, 3.0f, 0.0f));
        planet->AddMoon(std::make_unique<BaseMoon>(0.04f, PURPLE, 2.0f, 2.0f, 3.0f));

        const auto& planet2{star->AddPlanet(std::make_unique<BasePlanet>(0.3f, BROWN, 10.0f, 2.0f, 0.0f))};
    }

    // Destructor
    ~Demo() noexcept override = default;

    // Copy Constructor
    Demo(const Demo&) noexcept = default;

    // Copy Assignment Operator
    Demo& operator=(const Demo&) noexcept = default;

    // Move Constructor
    Demo(Demo&&) noexcept = default;

    // Move Assignment Operator
    Demo& operator=(Demo&&) noexcept = default;

    void Update(const float ms) noexcept override
    {
        _camera->Update(ms);

        _galaxy.Update(ms);
    }

    void Draw() noexcept override
    {
        BeginDrawing();
        ClearBackground(BLACK);
        _camera->Begin();

        DrawGrid(150, 1.6f);
        _galaxy.Draw();

        _camera->End();
        EndDrawing();
    }

    void Pause() noexcept override
    {
    }

    void Resume() noexcept override
    {
    }
};