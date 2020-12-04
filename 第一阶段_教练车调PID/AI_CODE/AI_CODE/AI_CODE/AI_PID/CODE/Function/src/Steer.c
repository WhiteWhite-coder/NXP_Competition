/*!
 * @file       Steer.c
 * @brief      ������ƺ���
 * @author     
 * @version    v1.0
 * @date       2020-3-7
 */

#include "headfile.h"
#include "smartcar.h"

//������������������������������������������������������������������������������������������������������������������������������������
//�������ֵ��Ҫ�ⶨ
//������������������������������������������������������������������������������������������������������������������������������������
int16 MidSteering = 714;   //�������PWMֵ
int16 SteerCtrl = 714,SteerLastCtrl = 714;   //���ռ�ձ�
int16 Steererror = 0;
//������������������������������������������������������������������������������������������������������������������������������������
//�������ƫֵ������ƫֵ��Ҫ�ⶨ
//������������������������������������������������������������������������������������������������������������������������������������
int16 MaxSteering = 789,MinSteering = 639;   //�����������ƫ/�������ƫ

/*******************************************************************************
 *  @brief       Steer_Ctrl����
 *  @note       ������ƺ���
 *  @data       2020-3-7 
 ******************************************************************************/
void Steer_Ctrl()   
{
    static uint8 number;
    if(number==0)  diangan_last_e=diangan_e;
    number++;
    if(number == 5)
    {
        diangan_ec = diangan_e - diangan_last_e;
        number = 0;
    }
    if(P_diangan < 0)   P_diangan = -P_diangan;
    Steererror = (int16)(P_diangan*diangan_e     //P*��E��k��-E��k-1����
                        + D_diangan*diangan_ec);   //D*��E��k��-2E��k-1��+E��k-2����
    SteerLastCtrl = SteerCtrl;
    SteerCtrl = MidSteering + (Steererror / 50);   //���ת��ΪPWM
    if(SteerCtrl<=MinSteering)   SteerCtrl = MinSteering;   //����ƫ/����ƫ����
    if(SteerCtrl>=MaxSteering)   SteerCtrl = MaxSteering;
}