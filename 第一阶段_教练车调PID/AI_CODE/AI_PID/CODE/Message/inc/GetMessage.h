/*!
 * @file       GetMessage.h
 * @brief      采集信息函数
 * @author     
 * @version    v1.0
 * @date       2020-3-5
 */

#ifndef __GETMESSAGE_H__
#define __GETMESSAGE_H__

#define SamplingNum 5
#define Min_SamplingNum 1
#define Number 4

extern uint16 ADCMessage[Number][SamplingNum];   //Number个电感采集SamplingNum组信息
extern uint16 ADCSum[Number];   //每个电感的采集信息之和
extern uint16 ADCAverage[Number];   //每个电感的平均值
extern float ADCNormal[Number];   //电感归一化
extern uint16 ADCMaxing[Number];   //赛道最大值
extern float diangan_e;   //本次误差
extern float diangan_e1;   //误差1
extern float diangan_e2;   //误差2
extern float diangan_last_e;   //上次误差
extern float diangan_ec;   //本次误差变化率
extern uint16 speed_now_left;   //左轮当前速度
extern uint16 speed_want_left;   //左轮期望速度
extern uint16 speed_e_left;   //左轮本次速度误差
extern uint16 speed_last_e_left;   //左轮上次速度误差
extern uint16 speed_ec_left;   //左轮本次速度误差变化率
extern uint16 speed_last_ec_left;   //左轮上次速度误差变化率
extern uint16 speed_now_right;   //右轮当前速度
extern uint16 speed_want_right;   //右轮期望速度
extern uint16 speed_e_right;   //右轮本次速度误差
extern uint16 speed_last_e_right;   //右轮上次速度误差
extern uint16 speed_ec_right;   //右轮本次速度误差变化率
extern uint16 speed_last_ec_right;   //右轮上次速度误差变化率


void GetMessage();
void ADC_Sort();
void ADC_Average();
void Normal();
void Cal_error();
void ADC_Processing(); 
void Speed_error_Left();
void Speed_error_Right();

#endif