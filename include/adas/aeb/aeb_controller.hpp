#pragma once

#include <vector> // why do we need this?

#include "adas/core/aeb_command.hpp"
#include "adas/core/ttc_result.hpp"

namespace adas::aeb {

    enum class AebState : std::uint8_t // what is the meaning of this line? what uint8_t does here?
    {
        IDLE,
        MONITORING,
        WARNING,
        BRAKING
    };

    class AebController
    {
        public:
            AebControler() = default;
            adas::core::AebCommand update(const std::vector<adas::core::TtcResult>& ttc_results);
            AebState getState() const;

        private:
            void transitionstate(float min_ttc);

        private:
            AebState state_{AebState::IDLE};

            //thresholds can be moved to config later
            static constexpr float kWarningTtc = 2.5F;
            static constexpr float kBrakeTtc = 1.2F;

    };
} //  namespace adas::aeb

// QnA
// what all concepts of c++ and design are covered in this code?
// why do we create enum classes? what benefits they have in c++?
// why do we use namespace? how beneficial they are?
