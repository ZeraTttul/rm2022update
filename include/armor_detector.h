#ifndef ARMOR_DETECTOR_H
#define ARMOR_DETECTOR_H

#include <opencv2/opencv.hpp>
#include "Solution.h"

using namespace std;
using namespace cv;

class armors
{
public:
     RotatedRect l;
     RotatedRect r;
     float length;
     float height;
     float angle_diff;
     Point2f corner[5];
     float boardw,boardh;
     float board_ratio;
     Point2f center;
};

class armor_detector
{
public:
    int hi;
    int hh;
    int maxh;
    int t;
    void selectLightbar(Mat frame,Mat binary,vector<armors>&armors_possible);
    void selectrightarmor(vector<armors>&armors_possible,vector<armors>&armors,Mat binary);
    void selectfinalarmor(armors &final_armor,vector<armors>&armors,Mat binary);
};
#endif