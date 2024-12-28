export module BaseSpace;

import IUpdate;
import IDraw;

export class BaseSpace : public IUpdate, public IDraw {
public:
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