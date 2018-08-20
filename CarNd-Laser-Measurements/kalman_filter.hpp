//
//  kalman_filter.hpp
//  CarNd-Laser-Measurements
//
//  Created by Bajrang Chapola on 19/08/18.
//  Copyright © 2018 Bajrang Chapola. All rights reserved.
//

#ifndef kalman_filter_hpp
#define kalman_filter_hpp
#include "Eigen/Dense"

#include <stdio.h>
using Eigen::MatrixXd;
using Eigen::VectorXd;
class Kalmanfilter{
public:
    ///*state vector
    VectorXd x_;
    
    // State Covariance matrix
    MatrixXd P_;
    
    // State Transition Matrix
    
    MatrixXd F_;
    
    // Process Covariance matrix
    MatrixXd Q_;
    
    // measurement matrix
    MatrixXd H_;
    
    // measurement Covariance matrix
    MatrixXd R_;
    
    //Constructor
    
    Kalmanfilter();
    
    //Distructor
    
    virtual ~Kalmanfilter();
    
    /**
     *Predict, Pridict the state and state covariance
     *using process model
     */
    void Predict();
    
    /**
     *Update the state
     *@params z The measurement at k+1
     */
    
    void Update(const VectorXd &z);
    
    
};
#endif /* kalman_filter_hpp */
