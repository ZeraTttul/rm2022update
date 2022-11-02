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
    public:
        void track(armors &armor, bool isDetected);
};


#endif