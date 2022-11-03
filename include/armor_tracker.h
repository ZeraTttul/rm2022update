#ifndef _ARMOR_TRACKER_H_
#define _ARMOR_TRACKER_H_

#include "armor_detector.h"
#include "Kalman.h"

class ArmorTracker
{
    private:
        queue<armors> m_armor_que;
        queue<armors> m_predict_que;
        kalman k;
        float target_change_threshold = 0;
    public:
        ArmorTracker()
        {
            KalmanFilter KK(k.stateNum,k.measureNum,0);
            k.KF=KK;
            //定义测量值
            k.measurement = Mat::zeros(k.measureNum,
                                    1,
                                    CV_32F);


            //转移矩阵 A
            k.KF.transitionMatrix = (Mat_<float>(k.stateNum,
                                                k.stateNum) <<
                                                1, 0, 1, 0,
                                                0, 1, 0, 1,
                                                0, 0, 1, 0,
                                                0, 0, 0, 1);
            k.init(k.KF);
        }
        void track(armors &armor, bool isDetected, Mat binary);
};


#endif