export module BaseGalaxy;

import std;
import BaseSpace;
import BaseStar;

export class BaseGalaxy : public BaseSpace {
private:
    std::vector<std::unique_ptr<BaseStar>> _stars{};

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
    const std::unique_ptr<BaseStar>& GetStar(const std::size_t index)
    {
        return _stars[index];
    }

    [[nodiscard]]
    std::unique_ptr<BaseStar>& AddStar(std::unique_ptr<BaseStar>&& star)
    {
        return _stars.emplace_back(std::move(star));
    }

    void Update(const float ms) noexcept override
    {
        for (const std::unique_ptr<BaseStar>& star : _stars)
        {
            star->Update(ms);
        }
    }

    void Draw() noexcept override
    {
        for (const std::unique_ptr<BaseStar>& star : _stars)
        {
            star->Draw();
        }
    }
};