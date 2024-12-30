module;

#include "raylib.h"

export module BaseStar;

import std;
import BaseSpace;
import BasePlanet;

export class BaseStar : public BaseSpace {
private:
    std::vector<std::unique_ptr<BasePlanet>> _planets{};

public:
    float Radius;
    Color StarColor;

    // Constructor
    BaseStar(const float radius, const Color& starColor) noexcept : Radius{radius}, StarColor{starColor}
    {
    }

    // Destructor
    ~BaseStar() noexcept override = default;

    // Copy Constructor
    BaseStar(const BaseStar&) noexcept = default;

    // Copy Assignment Operator
    BaseStar& operator=(const BaseStar&) noexcept = default;

    // Move Constructor
    BaseStar(BaseStar&&) noexcept = default;

    // Move Assignment Operator
    BaseStar& operator=(BaseStar&&) noexcept = default;

    [[nodiscard]]
    const std::unique_ptr<BasePlanet>& operator[](const std::size_t index) const noexcept
    {
        return _planets[index];
    }

    [[nodiscard]]
    const std::vector<std::unique_ptr<BasePlanet>>& GetPlanets() const noexcept
    {
        return _planets;
    }

    [[nodiscard]]
    const std::unique_ptr<BasePlanet>& AddPlanet(std::unique_ptr<BasePlanet>&& planet)
    {
        return _planets.emplace_back(std::move(planet));
    }

    void Update(const float ms) noexcept override
    {
        for (const std::unique_ptr<BasePlanet>& planet : _planets)
        {
            planet->Update(ms);
        }
    }

    void Draw() noexcept override
    {
        DrawSphere(Position, Radius, StarColor);

        for (const std::unique_ptr<BasePlanet>& planet : _planets)
        {
            planet->Draw();
        }
    }
};