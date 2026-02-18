#include "adas/tracking/track_manager.hpp"
#include "adas/tracking/simple_kalman.hpp"

namespace adas::tracking {

    void TrackManager::processDetections(const std::vector<adas::core::Detection>& detections, float dt_seconds)
    {
        updateTracks(detections, dt_seconds);

        //create new tracks for now (simple logic)
        for(const auto& det : detections)
        {
            createTrack(det);
        }

        manageTrackLifeCycle();
    }

    const std::vector<adas::core::Track>& TrackManager::getTracks() const
    {
        return tracks_;
    }

    void TrackManager::createTrack(const adas::core::Detection& det)
    {
        adas::core::Track track{};
        track.id = next_id_++;
        track.postiion = det.position;
        track.velocity = det.velocity;
        track.status = adas::core::TrackStatus::NEW;
        tracks_.push_back(track);

        //create Kalman filter
        auto kf = std::make_unique<SimpleKalman>; // how does auto help her?
        kf->initialize(det.position,det.velocity);
        filters_.push_back(std::move(kf));
    }

    void TrackManager::updateTracks(const std::vector<adas::core::Detection>& detections, float dt_seconds)
    {
        // for now only predict predict existing tracks
        for (std::size_t i = 0; i <filters_.size(); ++i) // what will differ here if i++ is used?
        {
            filters_[i]->predict(dt_seconds);
            tracks_[i].position = filters_[i]->getPosition();// why filters_ is accesed  with -> but track_ with .?
            tracks_[i].velocity = filters_[i]->getVelocity();
            tracks_[i].age++;
        }
    }

    void TrackManager::manageTrackLifeCycle()
    {
        for (auto& track : tracks_)
        {
            if (track.age > 3U) // is 3 frames 
            {
                track.status = adas::core::TrackStatus::CONFIRMED;
            }
        }
    }
} // namesapce adas::tracking

// QnA
// what all concepts of c++ and design are covered in this code?
// what is the best to include headers so that we dont encounter errors while building?
// What kind of error occurs when an include file is missing or wrong path is being accesed via #include?
// what kind of other common errors in C++ projects?