#pragma once // why do we need this?

#include "adas/core/types.hpp"

namespace adas::tracking {

    class IKalmanFilter
    {
        public:
            virtual ~IKalmanFilter() = default; // why we use only destructor and no constructor here?

            virtual void initialize(const adas::core::Vec2F& position, const adas::core::Velocity2f& velocity) = 0;

            virtual void predict(float dt_seconds) = 0;

            virtual void update(const adas::core::Vec2f& measured_pos,const adas::core::Velocity2f& measured_vel) = 0;

            virtual adas::core::Vec2f getPosition() const = 0;

            virtual adas::core::Velocity2f getVelocity() const = 0;

    };

} // namespace adas::tracking

// QnA
// what all concepts of c++ and design are covered in this code?
// What is virtual keyowrd and how does it affect functions constructors destructors and variabled declared with it?
// in this line virtual adas::core::Vec2f getPosition() const = 0; why do we write const and end with = 0;
// what are all the concepts involved in this code?
// why position and vecocity are passed with & but dt_seconds directly? what differnce in the operation of assignment is in its core here?