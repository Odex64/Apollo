export module StateManager;

import std;
import IState;
import ISingleton;

export class StateManager final : public ISingleton<StateManager> {
private:
    std::stack<std::unique_ptr<IState>> _states{};

public:
    IState* Active{nullptr};

    // Constructor
    StateManager() noexcept = default;

    // Destructor
    ~StateManager() noexcept override = default;

    // Copy Constructor
    StateManager(const StateManager&) noexcept = default;

    // Copy Assignment Operator
    StateManager& operator=(const StateManager&) noexcept = default;

    // Move Constructor
    StateManager(StateManager&&) noexcept = default;

    // Move Assignment Operator
    StateManager& operator=(StateManager&&) noexcept = default;

    void PushState(std::unique_ptr<IState>&& state) noexcept
    {
        if (Active)
            Active->Pause();

        Active = _states.emplace(std::move(state)).get();
    }

    void PopState() noexcept
    {
        const std::size_t size{_states.size()};
        if (size == 0)
            return;

        if (size >= 2)
        {
            _states.pop();
            Active = _states.top().get();
            Active->Resume();
        }
        else
        {
            _states.pop();
            Active = nullptr;
        }
    }
};