#include "adas/tracking/kalman_filter.hpp"

namespace adas::tracking {

    void Kalman::initialize(const adas::core::Vec2f& position, const adas::core::Velocity2f& velocity)
    {
        position_ = position;
        velocity_ = velocity;
    }

    void Kalman::predict(float dt_seconds)
    {
        posituon_.x += velocity_.vx * dt_seconds;
        position_.y += velocity_.vy * dt_seconds;
    }

    void Kalman::update(const adas::core::Vec2f measured_pos, const adas::core::Velocity2f measured_vel)
    {
        //placeholder for real kalman
        position_ = measured_pos;
        velocity_ = measured_vel;
    }


    adas::core::Vec2f Kalman::getPosition() const
    {
        return position_;
    }

    adas::core::Velocity2f Kalman::getVelocity() const
    {
        return velocity_;
    }

} // namespace adas::tracking