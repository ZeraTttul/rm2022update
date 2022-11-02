/*
 * @Description: 卡尔曼预测
 * @Version: 1.0
 * @Author: Barimu
 * @Date: 2022-10-30 00:10:23
 * @LastEditors: ZeraTul ZeraTttul@gmail.com
 * @LastEditTime: 2022-11-02 00:43:34
 */
#ifndef RM2022_KALMAN_H
#define RM2022_KALMAN_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/core/core.hpp>
#include <opencv2/video/tracking.hpp>
#include "../include/SolvePnP.h"
#include "../include/armor_detector.h"
#include <queue>
#include <vector>
#include <iostream>

using namespace std;
using namespace cv;

/**
 * @description: 卡尔曼类
 */
class kalman
{
public:
    const int stateNum = 4;                          //状态值4×1向量(x,y,△x,△y)
    const int measureNum = 2;                        //测量值2×1向量(x,y)
    KalmanFilter KF;
    Mat measurement;                                 //测量值
    Mat prediction;                                  //预测值
    void init(KalmanFilter KF);
    void predict(armors &finalarmor,Mat binary);
    Point2f kal(float x,float y);
};
#endif