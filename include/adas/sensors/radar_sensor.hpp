#pragma once

#include "adas/sensors/i_sensor.hpp"

namespace adas::sensors {

    class RadarSensor final : public Isensor
    {
        public:
            RadarSensor() = default;
            ~ RadarSensor() override = default;

            std::vector<adas::core::Detection> getDetection() override;
            bool isHealthy() const override;
            const char* getName()const override;

        private:
            bool healthy_{true};
    };
} // namespace adas::sensors