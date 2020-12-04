/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.24
 * @Target core		NXP RT1064DVL6A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-04-30
 ********************************************************************************************************************/


//整套推荐IO查看Projecct文件夹下的TXT文本



//打开新的工程或者工程移动了位置务必执行以下操作
//第一步 关闭上面所有打开的文件
//第二步 project  clean  等待下方进度条走完

//下载代码前请根据自己使用的下载器在工程里设置下载器为自己所使用的

//编码器需要不同模块
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
    board_init();   //务必保留，本函数用于初始化MPU 时钟 调试串口
	
    //此处编写用户代码(例如：外设初始化代码等)

    All_Init();
    pitinit();
    motor_speed=300;
    zanting_flag = 0;
    bluetooth = 1;
    stop_flag = 0;
    OLED_Clear();
	
    EnableGlobalIRQ(0);   //总中断最后开启
    while (1)
    {
        //此处编写需要循环执行的代码
       /************车子运行***********/
        motor_l();
       /***********参数调整***********/
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



