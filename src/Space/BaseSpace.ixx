module;

#include "raylib.h"

export module BaseSpace;

import IUpdate;
import IDraw;

export class BaseSpace : public IUpdate, public IDraw {
public:
    Vector3 Position{0.0f, 1.0f, 0.0f};

    // Constructor
    BaseSpace() noexcept = default;

    // Destructor
    ~BaseSpace() noexcept override = default;

    // Copy Constructor
    BaseSpace(const BaseSpace&) noexcept = default;

    // Copy Assignment Operator
    BaseSpace& operator=(const BaseSpace&) noexcept = default;

    // Move Constructor
    BaseSpace(BaseSpace&&) noexcept = default;

    // Move Assignment Operator
    BaseSpace& operator=(BaseSpace&&) noexcept = default;

    void Update(const float ms) noexcept override
    {
    }

    void Draw() noexcept override
    {
    }
};