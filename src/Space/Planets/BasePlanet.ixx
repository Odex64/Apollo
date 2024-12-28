module;

#include "raylib.h"

export module BasePlanet;

import std;
import BaseSpace;

export class BasePlanet : public BaseSpace {
private:
    Vector3 _orbitPathAxis{1.0f, 0.0f, 0.0f};
    Vector3 _orbitPathCenter{0.0f, 1.0f, 0.0f};

public:
    float Radius;
    Color PlanetColor;
    float OrbitRadius;
    float OrbitSpeed;
    float OrbitAngle;
    Vector3 Position{};

    // Constructor
    BasePlanet(const float radius, const Color& planetColor, const float orbitRadius, const float orbitSpeed,
               const float orbitAngle) noexcept
        : Radius{radius}, PlanetColor{planetColor}, OrbitRadius{orbitRadius}, OrbitSpeed{orbitSpeed},
          OrbitAngle{orbitAngle}
    {
        Position.y = 1.0f;
    }

    // Destructor
    ~BasePlanet() noexcept override = default;

    // Copy Constructor
    BasePlanet(const BasePlanet&) noexcept = default;

    // Copy Assignment Operator
    BasePlanet& operator=(const BasePlanet&) noexcept = default;

    // Move Constructor
    BasePlanet(BasePlanet&&) noexcept = default;

    // Move Assignment Operator
    BasePlanet& operator=(BasePlanet&&) noexcept = default;

    void Update(const float ms) noexcept override
    {
        OrbitAngle += OrbitSpeed * ms;

        Position.x = OrbitRadius * std::cos(OrbitAngle);
        Position.z = OrbitRadius * std::sin(OrbitAngle);
    }

    void Draw() noexcept override
    {
        // Draw planet
        DrawSphere(Position, Radius, PlanetColor);

        // Draw the orbit path
        DrawCircle3D(_orbitPathCenter, OrbitRadius, _orbitPathAxis, 90.0f, LIGHTGRAY);
    }
};