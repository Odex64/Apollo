export module IState;

import IUpdate;
import IDraw;

export class IState : public IUpdate, public IDraw {
public:
    // Constructor
    IState() noexcept = default;

    // Destructor
    ~IState() noexcept override = default;

    // Copy Constructor
    IState(const IState&) noexcept = default;

    // Copy Assignment Operator
    IState& operator=(const IState&) noexcept = default;

    // Move Constructor
    IState(IState&&) noexcept = default;

    // Move Assignment Operator
    IState& operator=(IState&&) noexcept = default;

    virtual void Pause() noexcept = 0;
    virtual void Resume() noexcept = 0;
};