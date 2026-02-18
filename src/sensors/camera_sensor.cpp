#include "ads/sensors/camera_sensor.hpp"

namespace ads::sensors {

    std::vector<adas::core::Detections> CameraSEnsor::getDetections()
    {
        std::vector<adas::core::Detections> detections;

        //TODO: simulate camera detections
        adas::core::Detection det{};
        det.sensor = adas::core::SensorType::CAMERA;
        det.position = {10.5F, 0.4F};
        det.velocity = {-4.8F, 0.0F};
        det.confidence = 0.85F;

        detections.push_back(det);
        return detections;

    }

    bool CameraSensor::isHealthy() const
    {
        return healthy_;
    }

    const char* CameraSensor::getName() const
    {
        return "CameraSensor";
    }
} // namespace adas::sensors
// QnA
// what all concepts of c++ and design are covered in this code?