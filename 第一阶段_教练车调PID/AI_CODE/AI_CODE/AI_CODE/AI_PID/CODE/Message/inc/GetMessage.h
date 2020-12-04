/*!
 * @file       GetMessage.h
 * @brief      �ɼ���Ϣ����
 * @author     
 * @version    v1.0
 * @date       2020-3-5
 */

#ifndef __GETMESSAGE_H__
#define __GETMESSAGE_H__

#define SamplingNum 5
#define Min_SamplingNum 1
#define Number 4

extern uint16 ADCMessage[Number][SamplingNum];   //Number����вɼ�SamplingNum����Ϣ
extern uint16 ADCSum[Number];   //ÿ����еĲɼ���Ϣ֮��
extern uint16 ADCAverage[Number];   //ÿ����е�ƽ��ֵ
extern float ADCNormal[Number];   //��й�һ��
extern uint16 ADCMaxing[Number];   //�������ֵ
extern float diangan_e;   //�������
extern float diangan_e1;   //���1
extern float diangan_e2;   //���2
extern float diangan_last_e;   //�ϴ����
extern float diangan_ec;   //�������仯��
extern uint16 speed_now_left;   //���ֵ�ǰ�ٶ�
extern uint16 speed_want_left;   //���������ٶ�
extern uint16 speed_e_left;   //���ֱ����ٶ����
extern uint16 speed_last_e_left;   //�����ϴ��ٶ����
extern uint16 speed_ec_left;   //���ֱ����ٶ����仯��
extern uint16 speed_last_ec_left;   //�����ϴ��ٶ����仯��
extern uint16 speed_now_right;   //���ֵ�ǰ�ٶ�
extern uint16 speed_want_right;   //���������ٶ�
extern uint16 speed_e_right;   //���ֱ����ٶ����
extern uint16 speed_last_e_right;   //�����ϴ��ٶ����
extern uint16 speed_ec_right;   //���ֱ����ٶ����仯��
extern uint16 speed_last_ec_right;   //�����ϴ��ٶ����仯��


void GetMessage();
void ADC_Sort();
void ADC_Average();
void Normal();
void Cal_error();
void ADC_Processing(); 
void Speed_error_Left();
void Speed_error_Right();

#endif