//
//  measurement_package.hpp
//  CarNd-Laser-Measurements
//
//  Created by Bajrang Chapola on 19/08/18.
//  Copyright © 2018 Bajrang Chapola. All rights reserved.
//

#ifndef measurement_package_hpp
#define measurement_package_hpp

#include <stdio.h>
#include "Eigen/Dense"
using Eigen::VectorXd;
class MeasurementPackage{
public:
    int64_t timestamp_;
    enum SensorType{
        LASAR,LADAR
    }sensor_type_;
    VectorXd raw_measurements_;
};

#endif /* measurement_package_hpp */
