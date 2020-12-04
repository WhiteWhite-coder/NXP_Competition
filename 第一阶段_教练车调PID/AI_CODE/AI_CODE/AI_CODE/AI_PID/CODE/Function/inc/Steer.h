/*!
 * @file       Steer.h
 * @brief      舵机控制函数
 * @author     
 * @version    v1.0
 * @date       2020-3-7
 */

#ifndef __Steer_H__
#define __Steer_H__

extern int16 MidSteering;   //舵机正中PWM值
extern int16 SteerCtrl,SteerLastCtrl;   //舵机占空比
extern int16 Steererror;
extern int16 MaxSteering,MinSteering;   //舵机保护左满偏/舵机右满偏

void Steer_Ctrl();   //舵机转角PID控制

#endif
