/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.24
 * @Target core		NXP RT1064DVL6A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-04-30
 ********************************************************************************************************************/

#ifndef _RT106X_config_h
#define _RT106X_config_h

//-------------------------------------------------------------------------------------------------------------------
//  ��ǰ�汾��
//  ����˴��汾����version.txt�ļ��汾��һ�£���version.txt�ļ�Ϊ׼
//-------------------------------------------------------------------------------------------------------------------
#define SEEKFREE_RT106X_VERSION   0X100




//-------------------------------------------------------------------------------------------------------------------
//  PRINTF_ENABLE Ϊ 0               ��ʹ��printf���ڴ�ӡ�����������������Ϣ���򲻻��ʼ����Ӧ����
//  PRINTF_ENABLE Ϊ 1               ʹ��printf���ڴ�ӡ���������������Ϣ������ʼ����Ӧ���ڣ����ﶨ��Ϊ1֮�������Լ��ֶ���ʼ������
//-------------------------------------------------------------------------------------------------------------------
#define PRINTF_ENABLE               1


#if(1 == PRINTF_ENABLE)

//-------------------------------------------------------------------------------------------------------------------
//printf���ڴ�ӡ������ʹ�õĴ��ڡ����ڲ����ʡ��������ź궨��
//-------------------------------------------------------------------------------------------------------------------
#define DEBUG_UART                  USART_1
#define DEBUG_UART_BAUD             115200
#define DEBUG_UART_TX_PIN           UART1_TX_B12
#define DEBUG_UART_RX_PIN           UART1_RX_B13

//-------------------------------------------------------------------------------------------------------------------
//  DEBUG_INFO Ϊ 0                  �����������Ϣ
//  DEBUG_INFO Ϊ 1                  ���������Ϣ��������Ϣ�������������ļ���������  ��ҪPRINTF�궨��Ϊ1������Ч���
//-------------------------------------------------------------------------------------------------------------------
#define DEBUG_PRINTF                1

#endif

//����ģ����ֵADC
#define SteerADC1 ADC2_CH9_B20
#define SteerADC2 ADC2_CH13_B24
#define SteerADC3 ADC2_CH14_B25
#define SteerADC4 ADC2_CH15_B26
//���PWM
#define DUOJI_Channel PWM4_MODULE2_CHA_C30
//���PWM
#define Motor_Go_L PWM2_MODULE3_CHA_D2
#define Motor_Go_R PWM1_MODULE3_CHB_D1
#define Motor_Return_L PWM1_MODULE3_CHA_D0
#define Motor_Return_R PWM2_MODULE3_CHB_D3
//C25��C26��C27��C28��C29����OLED
//��������ѵ��ģ��ADC
#define AI_ADC1 ADC1_CH3_B14
#define AI_ADC2 ADC1_CH4_B15
#define AI_ADC3 ADC1_CH8_B19
#define AI_ADC4 ADC1_CH6_B17
#define AI_ADC5 ADC1_CH7_B18
#define AI_ADC6 ADC1_CH0_B27
#define AI_ADC7 ADC1_CH10_B21
//����ת����
#define UART8_TX UART8_TX_D16
#define UART8_RX UART8_RX_D17
//������
#define Speed_A1 QTIMER1_TIMER0_C0
#define Speed_B1 QTIMER1_TIMER1_C1
#define Speed_A2 QTIMER1_TIMER2_C2
#define Speed_B2 QTIMER1_TIMER3_C24
//������
#define BEEP C3
//���� 
#define K1 B9
#define K2 B10
#define K3 B11
#define K4 B28
//���뿪��
#define BM1 B0
#define BM2 B1
#define BM3 B2
#define BM4 B3
//D4�ɻɹ�
#define Stop C16
//D14��D15���ùܽ�
   


#endif
