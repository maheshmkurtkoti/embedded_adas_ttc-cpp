#pragma once

#include <vector>
#include <memory>

#include "adas/core/detection.hpp"

namespace adas::sensors {

    class Isensor
    {
        public:
            virtual ~ISensor() = default;

            //Main sensor pulling API
            virtual std::vector<ads::core::Detection> getDetection() = 0;

            //Sensor health check
            virtual bool isHealthy() const = 0;

            //Sensor name (useful for logging)
            virtual const char* getname() const = 0;
    };
} // namespace adas::sensors
// QnA
// what all concepts of c++ and design are covered in this code?
// when to include memory and vector? what do they do?
// why only destructor and no constructor?