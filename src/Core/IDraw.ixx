export module IDraw;

export class IDraw {
public:
    // Constructor
    IDraw() noexcept = default;

    // Destructor
    virtual ~IDraw() noexcept = default;

    // Copy Constructor
    IDraw(const IDraw&) noexcept = default;

    // Copy Assignment Operator
    IDraw& operator=(const IDraw&) noexcept = default;

    // Move Constructor
    IDraw(IDraw&&) noexcept = default;

    // Move Assignment Operator
    IDraw& operator=(IDraw&&) noexcept = default;

    virtual void Draw() noexcept = 0;
};