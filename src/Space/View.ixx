module;

#include "raylib.h"
#include "raymath.h"

export module View;

import std;
import IUpdate;

export class View final : public IUpdate {
private:
    float _rotationSpeed{0.2f};
    float _zoomSpeed{100.0f};
    float _smoothZoomSpeed{3.0f};
    float _zoom{20.0f};
    float _maxZoom{10.0f};
    float _minZoom{500.0f};
    const Vector3* _target;
    float _targetZoom{_zoom};

public:
    Camera3D Camera = {{0.0f, 10.0f, 20.0f}, *_target, {0.0f, 1.0f, 0.0f}, 45.0f, CAMERA_PERSPECTIVE};
    float Yaw{};
    float Pitch{0.6f};

    // Constructor
    explicit View(const Vector3& target) noexcept : _target{&target}
    {
    }

    // Destructor
    ~View() noexcept override = default;

    // Copy Constructor
    View(const View&) noexcept = default;

    // Copy Assignment Operator
    View& operator=(const View&) noexcept = default;

    // Move Constructor
    View(View&&) noexcept = default;

    // Move Assignment Operator
    View& operator=(View&&) noexcept = default;

    void SetTarget(const Vector3& target) noexcept
    {
        _target = &target;
    }

    void Update(const float ms) noexcept override
    {
        // Check for mouse input for yaw and pitch rotation
        auto [x, y]{GetMouseDelta()};
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Yaw += x * _rotationSpeed * ms;
            Pitch += y * _rotationSpeed * ms;

            // Optionally clamp pitch to avoid flipping
            constexpr float pitchLimit = PI / 2.0f - 0.1f;
            if (Pitch > pitchLimit)
                Pitch = pitchLimit;
            if (Pitch < 0.0f)
                Pitch = 0.0f; // Ensure we can't go below the horizontal plane
        }

        // Zoom control via mouse wheel
        const float zoomDelta = GetMouseWheelMove() * _zoomSpeed * ms;
        _targetZoom -= zoomDelta;

        // Clamp target zoom to the allowed range
        if (_targetZoom < _maxZoom)
            _targetZoom = _maxZoom;
        if (_targetZoom > _minZoom)
            _targetZoom = _minZoom;

        // Smooth zoom interpolation
        _zoom = Lerp(_zoom, _targetZoom, _smoothZoomSpeed * ms);

        // Recalculate the camera's position in spherical coordinates
        Camera.position.x = _target->x + _zoom * std::cos(Yaw) * std::cos(Pitch);
        Camera.position.y = _target->y + _zoom * std::sin(Pitch);
        Camera.position.z = _target->z + _zoom * std::sin(Yaw) * std::cos(Pitch);

        // Keep the camera pointed at the target
        Camera.target = *_target;
    }
};