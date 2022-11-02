//
// Created by JYSimilar on 2022/9/25.
//

#ifndef RM2022_SOLUTION_CPP
#define RM2022_SOLUTION_CPP

#include "../include/Solution.h"

void Solution :: sol() {

    //定义KalmanFilter类并初始化
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

  
  
   // 1.初始化
        k.init(k.KF);

	//HikCamera MVS_cap; // 初始化相机
    //	MVS_cap.CamInfoShow(); // 显示图像参数信息
   
    VideoCapture cap ("E:\\VSCode\\production\\rm2022\\Video\\blueVideo3.mp4");

    while (true) {

#ifdef CLOCK
        start = clock();
#endif

        //frame = imread("D:/BaiduNetdiskDownload/photo/5.jpg");

        cap.read(frame1);
	//MVS_cap.ReadImg(frame1); // 相机取图
        //if (frame1.empty()) { // 相机开启线程需要一定时间
        //    continue;
        //}
		resize(frame1,frame,frame.size(),0.5,0.5);
        frame.copyTo(binary);//展示效果
        frame.copyTo(frame1);      
        
        armors finalarmor;                      
        armor_detector armor;
        vector<armors> armors_possible;
        vector<armors> armors;
        armor.maxh=100;
        armor.t=-1;
        armor.selectLightbar(frame,binary,armors_possible);
        if(armors_possible.size()!=0)armor.selectrightarmor(armors_possible,armors,binary);
        
        if(armors.size()!=0)
        {
                armor.selectfinalarmor(finalarmor,armors,binary);
                m_isDetected = 1;
        }
#ifdef PREDICT

            ArmorTracker trackArmor;
            trackArmor.track(finalarmor, m_isDetected);//追踪器
            k.predict(finalarmor,binary);
                
#endif  
        if(armors.size()!=0)
        {
                SOLVEPNP pnp;
                pnp.caculate(finalarmor);

#ifdef IMSHOW
                imshow("okey", binary);
#endif

                waitKey(30);
#ifdef CLOCK

                finish = clock();
                totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
                sum += totaltime;
                times+=1;
                if (sum > 1)
                {
                        cout <<"times"<< times << endl;
                        times = 0;
                        sum = 0;
                }
                std::cout << "Time" << totaltime << endl;
#endif
        }
    }
}
#endif //RM2022_SOLUTION_CPP
