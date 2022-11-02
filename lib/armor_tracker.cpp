/*
 * @Author: ZeraTul ZeraTttul@gmail.com
 * @Date: 2022-11-01 23:10:00
 * @LastEditors: ZeraTul ZeraTttul@gmail.com
 * @LastEditTime: 2022-11-02 00:44:13
 * @FilePath: \rm2022update\lib\armor_tracker.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _ARMOR_TRACTER_CPP_
#define _ARMOR_TRACTER_CPP

#include "../include/armor_tracker.h"

void ArmorTracker :: track(armors &final_armor, bool isDetected)
{
	armors armor = final_armor;
    if(!isDetected)
    {
		
    }
    else 
    {
		while(!m_predict_que.empty()) m_predict_que.pop();
		m_armor_que.push(armor);

		if(1);                                                          //装甲板中心点瞬移 x 个装甲板宽度后 init卡尔曼滤波器

		Point2f predict_pt = k.kal(armor.center.x, armor.center.y);
		armor.center = predict_pt;
		m_predict_que.push(armor);

    }
}

#endif