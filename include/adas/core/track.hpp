#pragma once

#include "adas/core/types.hpp"

namespace adas::core {

    enum class TrackStatus : std::uint8_t
    {
        NEW,
        CONFIRMED,
        LOST
    };

    struct Track
    {
        ObjectID id{0U};
        Vec2f position{};
        Velocity2f velocity{};
        float acceleration{0.0F};
        TrackStatus status{TrackStatus::NEW};
        TimestampMS last_update{0U};
        std::uint16_t age{0U};
        std::uint16_t missed_detections{0U};
    };
} // namespace adas::core