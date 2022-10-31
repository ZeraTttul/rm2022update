//
// Created by JYSimilar on 2022/9/25.
//

#include "../include/Solution.h"

/****************************
*
* 记得给串口赋予权限 chmod 777 /dev/ttyUSB0
*
* **************************/

#ifdef NX
#include "serial.h"
#endif

using namespace std;
using namespace cv;



int main () {

    #ifdef NX
    Serial uart(BR115200, WORDLENGTH_8B, STOPBITS_1, PARITY_NONE, HWCONTROL_NONE);
    uart.sOpen("/dev/ttyUSB0");
    VideoCapture capture(0);
    #endif

    Solution solve;
    solve.sol();

}