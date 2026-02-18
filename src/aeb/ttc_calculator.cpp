#include "adas/aeb/ttc_calculator.hpp"

namespace adas::aeb {

    adas::core::TtcResult TtcCalculator::computeTtc (const adas::core::Track& track) const 
    {
        adas::core::TtcResult result{};
        result.track_id = track.id;

        const float relative_speed = -track.velocty.vx; //assuming ego forward

        if (relative_speed > kMinClosingVelocity)
        {
            result.ttc_seconds = track.position.x/realtive_speed;
            result.collision_imminent = (result.ttc_seconds < 3.0F);
        }
        else
        {
            result.ttc_seconds = 999.0F;
            result.collsion_imminent = false;
        }

        return result; 

    }
} // namesapce adas::aeb