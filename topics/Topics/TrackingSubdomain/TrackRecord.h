#ifndef TRACK_RECORD_H
#define TRACK_RECORD_H
#include <vector>
#include <cstdint>

#include "SIDecibel.h"
#include "SIDecibelsPerSquareMeter.h"
#include "SIMeter.h"
#include "SIMeterPerSecond.h"
#include "SISecond.h"
#include "SIRadian.h"
#include "SIRadianPerSecond.h"
#include "SIRadianPerSecondSquared.h"

#include "ManoeuvreClassification.h"
#include "UpdatingTargetType.h"
#include "TrackStatus.h"
#include "TrackType.h"
#include "Acceleration.h"
#include "Position.h"
#include "Velocity.h"
#include "LatitudeLongitudeAltitude.h"
#include "MatrixInFrame.h"
#include "CovarianceMatrixPolar.h"
#include "CovarianceMatrixCartesian.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics{

class TrackRecord {
public:
    std::uint32_t                track_id                  {0};
    TrackStatus         	     track_status              {TrackStatus::TENTATIVE};
    SI::SISecond                 time_of_last_update       {0.0};
    std::uint32_t                plot_id                   {0};
    TrackType           	     track_type                {TrackType::AIR_TRACK_MEASURED_RANGE};
    UpdatingTargetType  	     updating_target_type      {UpdatingTargetType::ECHO};
    SI::SIDecibelsPerSquareMeter target_size_estimate      {0.0};
    bool                         target_size_validity_flag {false};
    SI::SIDecibel                signal_to_noise_ratio     {0.0};
    SI::SIRadian                 track_angle               {0.0};
    SI::SIRadian                 aspect_angle              {0.0};
    Position     	             position_vector           {FrameOfReference::FRAME_0};
    Velocity     	             velocity_vector           {FrameOfReference::FRAME_0};
    Acceleration 	             acceleration_vector       {FrameOfReference::FRAME_0};
    ManoeuvreClassification 	 manoeuvre_classification  {ManoeuvreClassification::NO_MANOEUVRE};
	CovarianceMatrixPolar	     covariance_matrix_polar     { MatrixInFrame{FrameOfReference::FRAME_1P, Matrix{9, 9}} };
	CovarianceMatrixCartesian    covariance_matrix_cartesian { MatrixInFrame{FrameOfReference::FRAME_0, Matrix{9, 9}} };
    MatrixInFrame                process_noise_matrix      { FrameOfReference::FRAME_0, Matrix{9,9} };
    SI::SIMeter                  range                     {0.0};
    SI::SIMeterPerSecond         range_rate                {0.0};
    SI::SIRadian                 azimuth                   {0.0};
    SI::SIRadian                 elevation                 {0.0};
    SI::SIRadianPerSecond        azimuth_rate              {0.0};
    SI::SIRadianPerSecond        elevation_rate            {0.0};
    SI::SIRadianPerSecondSquared azimuth_acceleration      {0.0};
    SI::SIRadianPerSecondSquared elevation_acceleration    {0.0};
    LatitudeLongitudeAltitude     frame_0_origin            {};

    
    TrackRecord() = default;
    TrackRecord(std::uint32_t track_id,
                TrackStatus track_status,
                SI::SISecond time_of_last_update,
                std::uint32_t plot_id,
                TrackType track_type,
                UpdatingTargetType updating_target_type,
                SI::SIDecibelsPerSquareMeter target_size_estimate,
                std::uint8_t target_size_validity_flag,
                SI::SIDecibel signal_to_noise_ratio,
                SI::SIRadian track_angle,
                SI::SIRadian aspect_angle,
                Position position_vector,
                Velocity velocity_vector,
                Acceleration acceleration_vector,
                ManoeuvreClassification manoeuvre_classification,
                CovarianceMatrixPolar covariance_matrix_polar,
				CovarianceMatrixCartesian covariance_matrix_cartesian,
                MatrixInFrame process_noise_matrix,
                SI::SIMeter range,
                SI::SIMeterPerSecond range_rate,
                SI::SIRadian azimuth,
                SI::SIRadian elevation,
                SI::SIRadianPerSecond azimuth_rate,
                SI::SIRadianPerSecond elevation_rate,
                SI::SIRadianPerSecondSquared azimuth_acceleration,
                SI::SIRadianPerSecondSquared elevation_acceleration,
                LatitudeLongitudeAltitude frame_0_origin)
    : track_id(track_id),
      track_status(track_status),
      time_of_last_update(time_of_last_update),
      plot_id(plot_id),
      track_type(track_type),
      updating_target_type(updating_target_type),
      target_size_estimate(target_size_estimate),
      target_size_validity_flag(target_size_validity_flag),
      signal_to_noise_ratio(signal_to_noise_ratio),
      track_angle(track_angle),
      aspect_angle(aspect_angle),
      position_vector(position_vector),
      velocity_vector(velocity_vector),
      acceleration_vector(acceleration_vector),
      manoeuvre_classification(manoeuvre_classification),
      covariance_matrix_polar(covariance_matrix_polar),
	  covariance_matrix_cartesian(covariance_matrix_cartesian),
      process_noise_matrix(process_noise_matrix),
      range(range),
      range_rate(range_rate),
      azimuth(azimuth),
      elevation(elevation),
      azimuth_rate(azimuth_rate),
      elevation_rate(elevation_rate),
      azimuth_acceleration(azimuth_acceleration),
      elevation_acceleration(elevation_acceleration),
      frame_0_origin(frame_0_origin)
    {}
    
    template <class T>
    void Serialise(T& archive) {

        /* Temporary variables to allow serialization of SI-unit members */
        double time_of_last_update_double{ time_of_last_update() };
        double target_size_estimate_double{ target_size_estimate() };
        double signal_to_noise_ratio_double{ signal_to_noise_ratio() };
        double track_angle_double{ track_angle() };
        double aspect_angle_double{ aspect_angle() };
        double range_double{ range() };
        double range_rate_double{ range_rate() };
        double azimuth_double{ azimuth() };
        double elevation_double{ elevation() };
        double azimuth_rate_double{ azimuth_rate() };
        double elevation_rate_double{ elevation_rate() };
        double azimuth_acceleration_double{ azimuth_acceleration() };
        double elevation_acceleration_double{ elevation_acceleration() };
 
        archive.Serialise(track_id,"track_id");
        archive.Serialise(track_status,"track_status");
        archive.Serialise(time_of_last_update_double ,"time_of_last_update");
        archive.Serialise(plot_id,"plot_id");
        archive.Serialise(track_type,"track_type");
        archive.Serialise(updating_target_type,"updating_target_type");
        archive.Serialise(target_size_estimate_double,"target_size_estimate");
        archive.Serialise(target_size_validity_flag,"target_size_validity_flag");
        archive.Serialise(signal_to_noise_ratio_double,"signal_to_noise_ratio");
        archive.Serialise(track_angle_double,"track_angle");
        archive.Serialise(aspect_angle_double,"aspect_angle");
        archive.Serialise(position_vector,"position_vector");
        archive.Serialise(velocity_vector,"velocity_vector");
        archive.Serialise(acceleration_vector,"acceleration_vector");
        archive.Serialise(manoeuvre_classification,"manoeuvre_classification");
        archive.Serialise(covariance_matrix_polar, "covariance_matrix_polar");
		archive.Serialise(covariance_matrix_cartesian, "covariance_matrix_cartesian");
        archive.Serialise(process_noise_matrix, "process_noise_matrix");
        archive.Serialise(range_double,"range");
        archive.Serialise(range_rate_double,"range_rate");
        archive.Serialise(azimuth_double,"azimuth");
        archive.Serialise(elevation_double,"elevation");
        archive.Serialise(azimuth_rate_double,"azimuth_rate");
        archive.Serialise(elevation_rate_double,"elevation_rate");
        archive.Serialise(azimuth_acceleration_double,"azimuth_acceleration");
        archive.Serialise(elevation_acceleration_double, "elevation_acceleration");
        archive.Serialise(frame_0_origin,"frame_0_origin");

        /* After serialisation write values to SI-unit class members  */
        time_of_last_update    = SI::SISecond(time_of_last_update_double);
        target_size_estimate   = SI::SIDecibelsPerSquareMeter(target_size_estimate_double);
        signal_to_noise_ratio  = SI::SIDecibel(signal_to_noise_ratio_double);
        track_angle            = SI::SIRadian(track_angle_double);
        aspect_angle           = SI::SIRadian(aspect_angle_double);
        range                  = SI::SIMeter(range_double);
        range_rate             = SI::SIMeterPerSecond(range_rate_double);
        azimuth                = SI::SIRadian(azimuth_double);
        elevation              = SI::SIRadian(elevation_double);
        azimuth_rate           = SI::SIRadianPerSecond(azimuth_rate_double);
        elevation_rate         = SI::SIRadianPerSecond(elevation_rate_double);
        azimuth_acceleration   = SI::SIRadianPerSecondSquared(azimuth_acceleration_double);
        elevation_acceleration = SI::SIRadianPerSecondSquared(elevation_acceleration_double);

    }
    
    LCA_TOPIC("TrackRecord",1,0);
};


}
#endif