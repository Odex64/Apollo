module;

#include "raylib.h"

export module BaseStar;

import std;
import BaseSpace;

export class BaseStar : public BaseSpace {
public:
    Vector3 Position{};
    float Radius;
    Color StarColor;

    // Constructor
    BaseStar(const float radius, const Color& starColor) noexcept : Radius{radius}, StarColor{starColor}
    {
        Position.y = 1.0f;
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

    void Update(const float ms) noexcept override
    {
    }

    void Draw() noexcept override
    {
        DrawSphere(Position, Radius, StarColor);
    }
};