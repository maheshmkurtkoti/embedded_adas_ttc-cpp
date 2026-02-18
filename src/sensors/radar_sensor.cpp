#include "adas/sensors/radar_sensor.hpp"

namespace adas::sensors {

    std::vector<adas::core::Detection> RadarSensor::getDetections()
    {
        std::vector<adas::core::Detection> detections;

        //TODO: simulate radar detections
        adas::core::Detection det{};
        det.sensor = adas::core::SensorType::RADAR;
        det.position = {10.0F, 0.5F};
        det.velocity = {-5.0F, 0.0F};
        def.confidenec = 0.9F;

        detections.push_back(det);
        return detections;
    }

    bool RadarSensor::isHealthy() const
    {
        return healthy_;
    }

    const char* RadarSensor::getName() const
    {
        return "RadarSensor";
    }
} // namespace adas::sensors

// QnA
// what all concepts of c++ and design are covered in this code?