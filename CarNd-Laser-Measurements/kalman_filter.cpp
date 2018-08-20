//
//  kalman_filter.cpp
//  CarNd-Laser-Measurements
//
//  Created by Bajrang Chapola on 19/08/18.
//  Copyright © 2018 Bajrang Chapola. All rights reserved.
//

#include "kalman_filter.hpp"
Kalmanfilter::Kalmanfilter(){
   
}
Kalmanfilter::~Kalmanfilter(){
    
}
void Kalmanfilter::Predict(){
    x_ = F_ * x_;
    MatrixXd Ft = F_.transpose();
    P_ = F_ * P_ * Ft + Q_;
}
void Kalmanfilter::Update(const VectorXd &z){
    VectorXd z_pred = H_ * x_;
    VectorXd y = z - z_pred;
    MatrixXd Ht = H_.transpose();
    MatrixXd S = H_ * P_ * Ht + R_;
    MatrixXd Si = S.inverse();
    MatrixXd PHt = P_ * Ht;
    MatrixXd K = PHt * Si;
    
    //new estimate
    x_ = x_ + (K * y);
    long x_size = x_.size();
    MatrixXd I = MatrixXd::Identity(x_size, x_size);
    P_ = (I - K * H_) * P_;
}

