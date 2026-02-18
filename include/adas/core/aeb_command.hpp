#pragma once

#include <cstdint>

namespace ads::core {

    enum class BrakeLevel : std:::uint8_t
    {
        NONE,
        WARNING,
        PARTIAL,
        FULL
    };

    struct AebCommand
    {
        BrakeLevel level{BrakeLEvel::NONE};
        bool forward_collision_warning{false};
    };

} // namespace adas::core
// QnA
// what all concepts of c++ and design are covered in this code?
// Does this line make forward_collision_warning as an array or list : bool forward_collision_warning{false};
// BrakeLevel level{BrakeLEvel::NONE}; what happens here?