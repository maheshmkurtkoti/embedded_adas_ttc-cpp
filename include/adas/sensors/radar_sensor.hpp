#pragma once

#include "adas/sensors/i_sensor.hpp"

namespace adas::sensors {

    class RadarSensor final : public Isensor
    {
        public:
            RadarSensor() = default; // why we need both constructors and distructors here?
            ~ RadarSensor() override = default; // why is override used here?

            std::vector<adas::core::Detection> getDetection() override;
            bool isHealthy() const override;
            const char* getName() const override;// what is happening in this line, why char* is written?

        private:
            bool healthy_{true};
    };
} // namespace adas::sensors
// QnA
// what all concepts of c++ and design are covered in this code?