#pragma once

#include "adas/core/types.h"

namespace adas::core {

    enum class SensorType : std::uint8_t
    {
        RADAR,
        CAMERA,
        UNKNOWN
    };

    struct Detection
    {
        ObjectId id{0U};
        SensorType sensor{SensorTpye::UNKNOWN};
        Vec2f position{};
        float confidence{0.0F};
        TimestampMs timestamp{0U};
    };

} // namespace adas::core
// QnA
// what all concepts of c++ and design are covered in this code?