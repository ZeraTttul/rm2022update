//
// Created by JYSimilar on 2022/9/25.
//

#ifndef RM2022_SOLUTION_H
#define RM2022_SOLUTION_H

#include <ctime>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/core/core.hpp>
#include <opencv2/video/tracking.hpp>
#include <cmath>
#include <iostream>
#include <cmath>
#include <fcntl.h>
#include <cerrno>
#include <cstring>
#include <cstdio>
#include "SolvePnP.h"
#include "rgb.h"
#include "Kalman.h"
#include "armor_detector.h"
#include "armor_tracker.h"

//#define NX
//#define RED
#define BLUE
#define IMSHOW //提高效率可以把这两个注释掉
//#define CLOCK
#define PREDICT

#ifdef NX
#include "serial.h"
#endif

using namespace std;
using namespace cv;
//using namespace camera;

class Solution {
private:

    clock_t start, finish;
    double totaltime,sum=0;
    int times = 0;
    Mat frame, binary, frame1;

public:
    void sol();
    kalman k;
};

#endif //RM2022_SOLUTION_H
