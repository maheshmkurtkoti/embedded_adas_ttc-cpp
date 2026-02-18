#include "adas/tracking/simple_kalman.hpp"

namespace adas::tracking {

    void SimpleKalman::initialize(const adas::core::Vec2f& position, const adas::core::Velocity2f& velocity)
    {
        position_ = position;
        velocity_ = velocity;
    }

    void SimpleKalman::predict(float dt_seconds)
    {
        position_.x += velocity_.vx * dt_seconds;
        position_.y += velocity_.vy * dt_seconds;
    }

    void SimpleKalman::update(const adas::core::Vec2f measured_pos, const adas::core::Velocity2f measured_vel)
    {
        //placeholder for real SimpleKalman
        position_ = measured_pos;
        velocity_ = measured_vel;
    }


    adas::core::Vec2f SimpleKalman::getPosition() const
    {
        return position_;
    }

    adas::core::Velocity2f SimpleKalman::getVelocity() const
    {
        return velocity_;
    }

} // namespace adas::tracking
// QnA
// what all concepts of c++ and design are covered in this code