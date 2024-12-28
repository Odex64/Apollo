export module Debug;

export class Debug {
public:
    // Constructor
    Debug() noexcept = default;

    // Destructor
    virtual ~Debug() noexcept = default;

    // Copy Constructor
    Debug(const Debug&) noexcept = default;

    // Copy Assignment Operator
    Debug& operator=(const Debug&) noexcept = default;

    // Move Constructor
    Debug(Debug&&) noexcept = default;

    // Move Assignment Operator
    Debug& operator=(Debug&&) noexcept = default;

    virtual void DebugUpdate() noexcept = 0;
    virtual void DebugDraw() noexcept = 0;
};