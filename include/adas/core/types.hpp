#pragma once

#include <cstdint> // when do we need this?

namespace adas::core {

    using Objecid = std::uint32_t;
    using TimestampMs = std::uint64_t;

    struct Vec2f
    {
        float x{0.0F};
        float y{0.0F};
    };

    struct Velocity2f
    {
        float vx{0.0F};
        float vy{0.0F};
    };

} // namespace adas::core
// QnA
// what all concepts of c++ and design are covered in this code?
// why do we use using? how all can it be used?
// How will these structures be like in memory?