module;

#include "raylib.h"

export module Game;

import std;
import ISingleton;
import IUpdate;
import IDraw;

export class Game final : public ISingleton<Game>, public IUpdate, public IDraw {
private:
    float _deltaTime{};

public:
    // Constructor
    Game() noexcept = default;

    // Destructor
    ~Game() noexcept override = default;

    // Copy Constructor
    Game(const Game&) noexcept = default;

    // Copy Assignment Operator
    Game& operator=(const Game&) noexcept = default;

    // Move Constructor
    Game(Game&&) noexcept = default;

    // Move Assignment Operator
    Game& operator=(Game&&) noexcept = default;

    [[nodiscard]]
    float GetDeltaTime() const noexcept
    {
        return _deltaTime;
    }

    void Update(const float ms) noexcept override
    {
        _deltaTime = ms;
    }

    void Draw() noexcept override
    {
    }
};