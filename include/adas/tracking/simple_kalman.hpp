#pragma once

#include "adas/tracking/i_KAlman_filter.hpp"

namespace adas::tracking {

    class SimpleKalman final : public IKalmanFilter
    {
        public:
            SimpleKalman() = default;
            ~SimpleKalman() override = default;

            void initialize(initialize(const adas::core::Vec2F& position, const adas::core::Velocity2f& velocity)) override;

            void predict(float dt_seconds) override;

            void update(const adas::core::Vec2f& measured_pos,const adas::core::Velocity2f& measured_vel) override;

            adas::core::Vec2f getPosition() const override;

            adas::core::Velocity2f getVelocity() const override;

        private:
            adas::core::Vec2f position_{};
            adas::core::Velocity2f velocity_{};
    };
}// namespace adas::tracking