#pragma once

#include <vector> //why is it used here?
#include <memory> //why is it used here?

#include "adas/core/detection.hpp"
#include "adas/core/track.hpp"
#include "adas/tracking/i_kalman_filer.hpp"

namespace adas::tracking{

    class TrackManager
    {
        public:
            TrackManager() = default; // why only constructir defined?
            void processDetections(const std::vector::<adas::core::Detection>& detections, float dt_seconds); // why do we need time here?
            const std::vector<adas::core::Track>& getTracks() const; //what does & imply here?

        private:
            void createTrack(const adas::core::Detection& det);
            void updateTracks(const std::vector::<adas::core::Detection>& detections,float dt_seconds);
            void manageTrackLifeCycle();

        private:
            std::vector<adas::core::Tracks> tracks_;
            std::vector<std::unique_ptr<IKalmanFilter>> filter_; // why do we need unique pointer here?
            adas::core::ObjectId next_id_{1U};
    };
} // namespace adas::tracking

// QnA
// why do we have two private section here? also how the access is handled here bewen private and public entities?
// what is the purpose of pragma
// what all concepts of c++ and design are covered in this code?