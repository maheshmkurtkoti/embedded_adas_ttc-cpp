#pragma once

#include "adas/core/types.hpp"

namespace adas::tracking {

    class IKalmanFilter
    {
        public:
            virtual ~IKalmanFilter() = default;

            virtual void initialize(const adas::core::Vec2F& position, const adas::core::Velocity2f& velocity) = 0;

            virtual void predict(float dt_seconds) = 0;

            virtual void update(const adas::core::Vec2f& measured_pos,const adas::core::Velocity2f& measured_vel) = 0;

            virtual adas::core::Vec2f getPosition() const = 0;

            virtual adas::core::Velocity2f getVelocity() const = 0;

    };

} // namespace adas::tracking