//
//  tracking.hpp
//  CarNd-Laser-Measurements
//
//  Created by Bajrang Chapola on 19/08/18.
//  Copyright © 2018 Bajrang Chapola. All rights reserved.
//

#ifndef tracking_hpp
#define tracking_hpp

#include <stdio.h>
#include "measurement_package.hpp"
#include <vector>
#include <string>
#include <fstream>
#include "kalman_filter.hpp"

class Tracking{
public:
    Tracking();
    virtual ~Tracking();
    void ProcessMeasurement(const MeasurementPackage &measurement_package);
    Kalmanfilter kf_;
private:
    bool is_initialized_;
    int64_t previous_timestamp_;
    
    //Acceleration noise component
    
    float noise_ax;
    float noise_ay;
    
    
};
#endif /* tracking_hpp */
