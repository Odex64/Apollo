export module ISingleton;

export template <typename T>
class ISingleton {
public:
    // Constructor
    ISingleton() noexcept = default;

    // Destructor
    virtual ~ISingleton() noexcept = default;

    // Copy Constructor
    ISingleton(const ISingleton&) noexcept = default;

    // Copy Assignment Operator
    ISingleton& operator=(const ISingleton&) noexcept = default;

    // Move Constructor
    ISingleton(ISingleton&&) noexcept = default;

    // Move Assignment Operator
    ISingleton& operator=(ISingleton&&) noexcept = default;

    [[nodiscard]]
    static T& GetInstance()
    {
        static T instance{};
        return instance;
    }
};