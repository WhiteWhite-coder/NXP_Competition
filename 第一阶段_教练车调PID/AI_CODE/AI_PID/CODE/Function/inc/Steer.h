/*!
 * @file       Steer.h
 * @brief      ������ƺ���
 * @author     
 * @version    v1.0
 * @date       2020-3-7
 */

#ifndef __Steer_H__
#define __Steer_H__

extern int16 MidSteering;   //�������PWMֵ
extern int16 SteerCtrl,SteerLastCtrl;   //���ռ�ձ�
extern int16 Steererror;
extern int16 MaxSteering,MinSteering;   //�����������ƫ/�������ƫ

void Steer_Ctrl();   //���ת��PID����

#endif
