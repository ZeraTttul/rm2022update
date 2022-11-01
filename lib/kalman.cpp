/*
 * @Description: 卡尔曼预测
 * @Version: 1.0
 * @Author: Barimu
 * @Date: 2022-10-30 00:10:23
 * @LastEditors: Barimu
 * @LastEditTime: 2022-11-01 00:51:43
 */
#ifndef RM2022_KALMAN_CPP
#define RM2022_KALMAN_CPP

#include "../include/Kalman.h"

using namespace std;
using namespace cv;

/**
 * @description: 卡尔曼相关数据初始化
 * @param {KalmanFilter} KF
 */
void kalman :: init(KalmanFilter KF) {
    //将下面几个矩阵设置为对角阵
    setIdentity(KF.measurementMatrix);                     //测量矩阵 H
    setIdentity(KF.processNoiseCov, Scalar::all(1e-3));    //过程噪声 Q
    setIdentity(KF.measurementNoiseCov, Scalar::all(1e-2));//测量噪声 R
    setIdentity(KF.errorCovPost, Scalar::all(1));          //最小均方误差 Pt
    //randn( KF.statePost, Scalar::all(0), Scalar::all(0.1) );
    randn(KF.statePost, Scalar::all(0), Scalar::all(0.1)); //x(0)初始化
}

/**
 * @description: 卡尔曼预测装甲板中心点
 * @param {float} x
 * @param {float} y
 * @return {*}
 * @author: Barimu
 */
Point kalman::kal(float x,float y)
{
    Point center;   
    prediction = KF.predict();                  //进行一次预测
    measurement.at<float>(0) = x;               //写入真实值
	measurement.at<float>(1) = y;		
    for(int i=1;i<=5;i++)                       //迭代5次
         {
                KF.correct(measurement);        //更新
                prediction = KF.predict();
                measurement.at<float>(0) = prediction.at<float>(0);
		        measurement.at<float>(1) = prediction.at<float>(1); 
        }
        center.x=prediction.at<float>(0);
        center.y=prediction.at<float>(1);
    return center;
}

/**
 * @description: 调用卡尔曼预测
 * @param {armors} &finalarmor
 * @param {Mat} binary
 * @param {kalman} &k
 */
void kalman::predict(armors &finalarmor,Mat binary)
{
        Point2f centers=finalarmor.center;
        Point predict_pt = kal(centers.x,centers.y);
        circle(binary, predict_pt, 3, Scalar(34, 255, 255), -1);  
}
#endif