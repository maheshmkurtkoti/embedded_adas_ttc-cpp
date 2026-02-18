#pragma once

#include "adas/core/types.hpp"

namespace adas::core {

    struct TtcResult
    {
        ObjectID track_id{0U};
        float ttc_seconds(0.0F);
        bool collision_imminent{false};
    };
} // namespace adas::core