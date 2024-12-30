module;

#include "raylib.h"

export module BaseGalaxy;

import std;
import BaseSpace;
import BaseStar;
import BasePlanet;
import BaseMoon;
import View;

export class BaseGalaxy : public BaseSpace {
private:
    std::optional<View> _view{};
    std::vector<std::unique_ptr<BaseStar>> _stars{};

    [[nodiscard]]
    std::optional<const BaseSpace*> DetectClickedObject() const noexcept
    {
        const Ray ray{GetScreenToWorldRay(GetMousePosition(), _view->Camera)};

        // Check each star in the galaxy
        for (const std::unique_ptr<BaseStar>& star : GetStars())
        {
            // Check collision with the star
            if (GetRayCollisionSphere(ray, star->Position, star->Radius).hit)
            {
                return star.get(); // Return the clicked star
            }

            // Check each planet in the star
            for (const std::unique_ptr<BasePlanet>& planet : star->GetPlanets())
            {
                // Check collision with the planet
                if (GetRayCollisionSphere(ray, planet->Position, planet->Radius).hit)
                {
                    return planet.get(); // Return the clicked planet
                }

                // Check each moon in the planet
                for (const std::unique_ptr<BaseMoon>& moon : planet->GetMoons())
                {
                    // Check collision with the moon
                    if (GetRayCollisionSphere(ray, moon->Position, moon->Radius).hit)
                    {
                        return moon.get(); // Return the clicked moon
                    }
                }
            }
        }

        return std::nullopt; // No object was clicked
    }

public:
    // Constructor
    BaseGalaxy() noexcept = default;

    // Destructor
    ~BaseGalaxy() noexcept override = default;

    // Copy Constructor
    BaseGalaxy(const BaseGalaxy&) noexcept = default;

    // Copy Assignment Operator
    BaseGalaxy& operator=(const BaseGalaxy&) noexcept = default;

    // Move Constructor
    BaseGalaxy(BaseGalaxy&&) noexcept = default;

    // Move Assignment Operator
    BaseGalaxy& operator=(BaseGalaxy&&) noexcept = default;

    [[nodiscard]]
    const std::unique_ptr<BaseStar>& operator[](const std::size_t index) const noexcept
    {
        return _stars[index];
    }

    [[nodiscard]]
    const std::vector<std::unique_ptr<BaseStar>>& GetStars() const noexcept
    {
        return _stars;
    }

    [[nodiscard]]
    const std::unique_ptr<BaseStar>& AddStar(std::unique_ptr<BaseStar>&& star) noexcept
    {
        return _stars.emplace_back(std::move(star));
    }

    void SetView(const BaseSpace& element) noexcept
    {
        _view.emplace(element.Position);
    }

    void Update(const float ms) noexcept override
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (const std::optional collision{DetectClickedObject()})
            {
                _view->SetTarget(collision.value()->Position);
            }
        }

        _view->Update(ms);
        for (const std::unique_ptr<BaseStar>& star : _stars)
        {
            star->Update(ms);
        }
    }

    void BeginView() const noexcept
    {
        BeginMode3D(_view->Camera);
    }

    void EndView() const noexcept
    {
        EndMode3D();
    }

    void Draw() noexcept override
    {
        for (const std::unique_ptr<BaseStar>& star : _stars)
        {
            star->Draw();
        }
    }
};