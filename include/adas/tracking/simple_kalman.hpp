#pragma once

#include "adas/tracking/i_KAlman_filter.hpp"

namespace adas::tracking {

    class SimpleKalman final : public IKalmanFilter // what does final do here?
    {
        public:
            SimpleKalman() = default; // what happens when we define constructor with default and what other ways can be used to initialise the constructor?
            ~SimpleKalman() override = default; // Why do we need distructor here?

            void initialize(const adas::core::Vec2F& position, const adas::core::Velocity2f& velocity)) override;

            void predict(float dt_seconds) override;

            void update(const adas::core::Vec2f& measured_pos,const adas::core::Velocity2f& measured_vel) override;

            adas::core::Vec2f getPosition() const override;

            adas::core::Velocity2f getVelocity() const override;

        private:
            adas::core::Vec2f position_{};
            adas::core::Velocity2f velocity_{};
    };
}// namespace adas::tracking

// QnA
// what all concepts of c++ and design are covered in this code?
// what is the purpose of override?
// why do we create adas::core::Vec2f adas::core::Velocity2f what is major benefit of doing it?
// what do these {} mean when used  like position_{} do we use [] similarly cpp how i diffres from python?
