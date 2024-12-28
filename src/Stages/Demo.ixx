module;

#include "raylib.h"

export module Demo;

import IState;
import BaseMoon;
import BasePlanet;
import BaseStar;
import SpaceCamera;

export class Demo final : public IState {
private:
    BasePlanet _planet{0.5f, BLUE, 5.0f, 1.0f, 0.0f};
    BaseStar _star{1.0f, YELLOW};
    BaseMoon _moon{0.2f, GRAY, 1.2f, 5.f, 0.0f};

    SpaceCamera _camera{_moon.Position};

    float _cameraZoomMin = 5.0f;
    float _cameraZoomMax = 30.0f;
    Vector3 _cameraPosMin = {-50.0f, 1.0f, -50.0f};
    Vector3 _cameraPosMax = {50.0f, 50.0f, 50.0f};

public:
    // Constructor
    Demo() noexcept = default;

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
        _camera.Update(ms);

        _planet.Update(ms);
        _moon.SetOrbitPathCenter(_planet.Position);
        _moon.Update(ms);
        _star.Update(ms);



    }

    void Draw() noexcept override
    {
        BeginDrawing();
        ClearBackground(BLACK);
        _camera.Begin();

        DrawGrid(150, 1.6f);

        _planet.Draw();
        _star.Draw();
        _moon.Draw();

        _camera.End();
        EndDrawing();
    }

    void Pause() noexcept override
    {
    }

    void Resume() noexcept override
    {
    }
};