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


//�����Ƽ�IO�鿴Projecct�ļ����µ�TXT�ı�



//���µĹ��̻��߹����ƶ���λ�����ִ�����²���
//��һ�� �ر��������д򿪵��ļ�
//�ڶ��� project  clean  �ȴ��·�����������

//���ش���ǰ������Լ�ʹ�õ��������ڹ���������������Ϊ�Լ���ʹ�õ�

//��������Ҫ��ͬģ��
#include "headfile.h"
#include "smartcar.h"

uint16 motor_speed;
uint8 dat;
uint8 zanting_flag;
uint8 bluetooth;
uint8 stop_flag;


int main(void)
{
    DisableGlobalIRQ();
    board_init();   //��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
	
    //�˴���д�û�����(���磺�����ʼ�������)

    All_Init();
    pitinit();
    motor_speed=360;
    zanting_flag = 0;
    bluetooth = 1;
    stop_flag = 0;
	
    EnableGlobalIRQ(0);   //���ж������
    while (1)
    {
        //�˴���д��Ҫѭ��ִ�еĴ���
       /************��������***********/
        motor_l();
       /***********��������***********/
        diangan_view();
    }
}



