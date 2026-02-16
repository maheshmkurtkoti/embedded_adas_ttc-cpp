#pragma once

#include "adas/core/track.hpp"
#include "ads/core/ttc_result.hpp"

namespace adas::aeb{

    class TtcCalculator
    {
        public:

            TtcCalculator() = default;

            adas::core::TtcResult computeTtc(const adas::core::Track& track) const;

        private:

            static constexpr float kMinClosingVelocity = 0.1F;

    };
} // namespace adas::aeb