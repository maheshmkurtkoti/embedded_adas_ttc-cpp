#include <iostream>
#include <memory>
#include <vector>

#include "adas/sensors/radar_sensor.hpp"
#include "adas/sensors/camera_sensor.hpp"
#include "adas/tracking/track_manager.hpp"
#include "adas/aeb/ttc_calculator.hpp"
#include "adas/aeb/aeb_controller.hpp"

using namespace adas;

int main()
{
    std::cout << "=== ADAS Pipeline Demo ===\n";

    // --------------------------------------------------
    // Create sensors
    // --------------------------------------------------
    std::vector<std::unique_ptr<sensors::ISensor>> sensors_list;
    sensors_list.push_back(std::make_unique<sensors::RadarSensor>());
    sensors_list.push_back(std::make_unique<sensors::CameraSensor>());

    // --------------------------------------------------
    // Core modules
    // --------------------------------------------------
    tracking::TrackManager track_manager;
    aeb::TtcCalculator ttc_calc;
    aeb::AebController aeb_controller;

    constexpr float dt = 0.1F;

    // --------------------------------------------------
    // Run few cycles
    // --------------------------------------------------
    for (int frame = 0; frame < 5; ++frame)
    {
        std::cout << "\n--- Frame: " << frame << " ---\n";

        // ================================
        // Collect detections
        // ================================
        std::vector<core::Detection> all_detections;

        for (auto& sensor : sensors_list)
        {
            if (sensor->isHealthy())
            {
                auto dets = sensor->getDetections();
                all_detections.insert(
                    all_detections.end(),
                    dets.begin(),
                    dets.end());
            }
        }

        std::cout << "Detections: " << all_detections.size() << "\n";

        // ================================
        // Tracking
        // ================================
        track_manager.processDetections(all_detections, dt);
        const auto& tracks = track_manager.getTracks();

        std::cout << "Tracks: " << tracks.size() << "\n";

        // ================================
        // TTC computation
        // ================================
        std::vector<core::TtcResult> ttc_results;
        for (const auto& track : tracks)
        {
            ttc_results.push_back(ttc_calc.computeTtc(track));
        }

        // ================================
        // AEB decision
        // ================================
        const auto cmd = aeb_controller.update(ttc_results);

        std::cout << "AEB State: "
                  << static_cast<int>(aeb_controller.getState()) << "\n";

        std::cout << "Brake Level: "
                  << static_cast<int>(cmd.level) << "\n";
    }

    std::cout << "\n=== Demo Complete ===\n";
    return 0;
}

// QnA
// what all concepts of c++ and design are covered in this code?