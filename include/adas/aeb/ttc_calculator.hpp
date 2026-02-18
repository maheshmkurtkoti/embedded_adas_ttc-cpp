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

// QnA
// what all concepts of c++ and design are covered in this code?
// what is static keyword? how does it affect fuction,variable or class or any other C++ entity when declared with it?
// when doe have to use static keyword?
// what is constexpr and when do use it?
// what this line means static constexpr float kMinClosingVelocity = 0.1F;