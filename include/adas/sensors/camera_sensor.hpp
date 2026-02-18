#pragma once

#include "adas/sensor/i_sensor.hpp"

namespace adas::sensors{

    class CameraSensor final : public ISensor
    {
        public:
            CameraSensor() = default;
            ~CameraSensor() override = default;

            std::vector<adas::core::Detection> getDetections() override;
            bool isHealthy() const override;
            const char* getName() const override;

        private:
            bool healthy_{true};
    };
} // namespace adas::sensors
// QnA
// what all concepts of c++ and design are covered in this code?