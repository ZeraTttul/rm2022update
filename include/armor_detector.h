/*
 * @Description: 识别装甲板
 * @Version: 1.0
 * @Author: Barimu
 * @Date: 2022-10-30 00:19:37
 * @LastEditors: Barimu
 * @LastEditTime: 2022-11-01 00:51:29
 */
#ifndef ARMOR_DETECTOR_H
#define ARMOR_DETECTOR_H

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/**
 * @description: 装甲板类
 */
class armors
{
public:
     RotatedRect l;                   //左灯条
     RotatedRect r;                   //右灯条
     float length;                    //装甲板长
     float height;                    //装甲板高
     float boardw;
     float boardh;  
     float angle_diff;                //左右灯条角度差  
     Point2f corner[5];               //装甲板四个角点
     float board_ratio;               //装甲板长宽比
     Point2f center;                  //装甲板中心点
};

/**
 * @description: 检测装甲板类
 */
class armor_detector
{
public:
    int hi;                           //视觉组的传承 ~by xyc
    int maxh;                         
    int t;
    void selectLightbar(Mat frame,Mat binary,vector<armors>&armors_possible);
    void selectrightarmor(vector<armors>&armors_possible,vector<armors>&armors,Mat binary);
    void selectfinalarmor(armors &finalarmor,vector<armors>&armors,Mat binary);
};
#endif