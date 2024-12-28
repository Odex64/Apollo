export module IUpdate;

export class IUpdate {
public:
    // Constructor
    IUpdate() noexcept = default;

    // Destructor
    virtual ~IUpdate() noexcept = default;

    // Copy Constructor
    IUpdate(const IUpdate&) noexcept = default;

    // Copy Assignment Operator
    IUpdate& operator=(const IUpdate&) noexcept = default;

    // Move Constructor
    IUpdate(IUpdate&&) noexcept = default;

    // Move Assignment Operator
    IUpdate& operator=(IUpdate&&) noexcept = default;

    virtual void Update(float ms) noexcept = 0;
};