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

void keypros1()
{
	if(gpio_get(K1) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K1) == 1)
                     P_diangan += 10;
                while(gpio_get(K1));
            }		
}

void keypros2()
{
	if(gpio_get(K2) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K2) == 1)
                     D_diangan += 50;
                while(gpio_get(K2));
            }		
}

void Kp_change2()
 {
     if(gpio_get(BM1) == 0 &&
        gpio_get(BM2) == 0 )
     {
       OLED_Clear();
         while(gpio_get(BM1) == 0 && gpio_get(BM2) == 0)
         {
           diangan_view();
             if(gpio_get(K1) == 1)
             {
                 systick_delay_ms(100);
                 if(gpio_get(K1) == 1)
                     P_diangan += 4;
                 while(gpio_get(K1));
             }
             if(gpio_get(K2) == 1)
             {
                 systick_delay_ms(100);
                 if(gpio_get(K2) == 1)
                     P_diangan -= 4;
                 while(gpio_get(K2));
             }
         }
         OLED_Clear();
     }
 }
 
void Kd_change2()
 {
     if(gpio_get(BM1) == 1 &&
        gpio_get(BM2) == 0 )
    {
      OLED_Clear();
        while(gpio_get(BM1) == 1 && gpio_get(BM2) == 0)
        {
          diangan_view();
            if(gpio_get(K1) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K1) == 1)
                    D_diangan += 10;
                while(gpio_get(K1));
            }
            if(gpio_get(K2) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K2) == 1)
                    D_diangan -= 10;
                while(gpio_get(K2));
            }
        }
        OLED_Clear();
    }
 } 

void Variable_change2()
 {
     if(gpio_get(BM1) == 0 &&
        gpio_get(BM2) == 1 )
    {
      OLED_Clear();
        while(gpio_get(BM1) == 0 && gpio_get(BM2) == 1)
        {
          diangan_view();
            if(gpio_get(K1) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K1) == 1)
                    Variable += 10;
                while(gpio_get(K1));
            }
            if(gpio_get(K2) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K2) == 1)
                    Variable -= 10;
                while(gpio_get(K2));
            }
        }
        OLED_Clear();
    }
 } 

int main(void)
{
    DisableGlobalIRQ();
    board_init();   //��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
	
    //�˴���д�û�����(���磺�����ʼ�������)

    All_Init();
    pitinit();
    motor_speed=300;
    zanting_flag = 0;
    bluetooth = 1;
    stop_flag = 0;
    OLED_Clear();
	
    EnableGlobalIRQ(0);   //���ж������
    while (1)
    {
        //�˴���д��Ҫѭ��ִ�еĴ���
       /************��������***********/
        motor_l();
       /***********��������***********/
        //Kp_change();
        //Kd_change();
        //e_change();
        /*e_change_xiao();
        Kd_change();*/
        //keypros1();
        //keypros2();
        Kp_change2();
        Kd_change2();
        Variable_change2();
        diangan_view();
        
        //e_change_da();
    }
}



