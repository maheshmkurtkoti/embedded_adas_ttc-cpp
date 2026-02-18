#include "adas/aeb/aeb_controller.hpp"

namespace adas::aeb {
    adas::core::AebCommand AebController::update(const std::vector<adas::core::TtcResult>& ttc_results)
    {
        float min_ttc = 999.0F;

        for (const auto& r : ttc_results) //How does this for lop work ?
        {
            if (r.ttc_seconds < min_ttc)
            {
                min_ttc = r.ttc_seconds;
            }
        }

        transitionState(min_ttc);

        adas:core::AebCommand cmd{};

        switch (state_)
        {
            case AebState::WARNING:
                cmd.level = adas::core::BrakeLevel::WARNING;
                cmd.forward_collision_warning = true;
                break;

            case AebState::BRAKING:
                cmd.level = adas::core::BrakeLevel::FULL;
                break;

            default:
                cmd.level = adas::core::BrakeLevel::NONE;
                break;
        }
        return cmd;
    }

    AebState AebController::getState() const
    {
        return state_;
    }

    void AebController::transitionState(float min_ttc)
    {
        switch(state_)
        {
            case AebState::IDLE:
            case AebState::MONITORING:
                if(min_ttc < kBrakeTtc)
                {
                    state_ = AebState::BRAKING;
                }
                else if (min_ttc < kWarningTtc)
                {
                    state_ = AebState::WARNING;
                }
                else
                {
                    state_ = AebState::MONITORING;
                }
            
                case AebState::WARNING:
                if (min_ttc < kBrateTtc)
                {
                    state_ = AebState::BRAKING;
                }
                else if (min_ttc >= kWarningTtc)
                {
                    state_ = AebState::MONITORING;
                }
                break;

            case AebState::Braking:
                if(min_ttc >= kWarningTtc)
                {
                    state_ = AebState::MONITORING;
                }
                break;
        }
    }
} // namespace adas::aeb

// QnA
// what all concepts of c++ and design are covered in this code?
// what is auto keyword?How can it used? when is it need?
