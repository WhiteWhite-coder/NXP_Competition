/*!
 * @file       OLED_debug.c
 * @brief      OLED���Բ������ӻ�����
 * @author     
 * @version    v1.0
 * @date       2020-7-17
 */
 
 #include "headfile.h"
 #include "smartcar.h"
 
 /*******************************************************************************
 *  @brief      Oled_view_duoji����
 *  @note       ����OLED��ʾ���Ե��ԵĲ������������ڵ�Ƭ������
 *  @data       2020-7-17
 ******************************************************************************/
 void Oled_view_duoji()
 {
     LED_P6x8Str(0, 0, "Steer_P");
     LED_P6x8Str(50, 0, "     ");
     LED_PrintValueF(50, 0, Steer_P_diangan, 0);
     LED_P6x8Str(0, 1, "Steer_D");
     LED_P6x8Str(50, 1, "    ");
     LED_PrintValueF(50, 1, Steer_D_diangan, 0);
     LED_P6x8Str(0, 2, "e");
     LED_P6x8Str(50, 2, "          ");
     LED_PrintValueF(50, 2, diangan_e, 3);
     LED_P6x8Str(0, 3, "e1");
     LED_P6x8Str(50, 3, "     ");
     LED_PrintValueI(50, 3, e1);
     LED_P6x8Str(0, 5, "e2");
     LED_P6x8Str(50, 5, "    ");
     LED_PrintValueI(50, 5 , e2);
     LED_P6x8Str(0, 6, "Kp1");
     LED_P6x8Str(50, 6, "      ");
     LED_PrintValueI(50, 6, Kp1);
     LED_P6x8Str(0, 7, "Kp2");
     LED_P6x8Str(50, 7, "      ");
     LED_PrintValueI(50, 7, Kp2);
 }

 /*******************************************************************************
 *  @brief      Oled_view_dianji����
 *  @note       OLED��ʾ���Բ鿴�ĵ�����ٵĲ���
 *  @data       2020-7-28
 ******************************************************************************/
 void Oled_view_dianji()
 {
     LED_P6x8Str(0, 0, "PWM_L");
     LED_P6x8Str(50, 0, "     ");
     LED_PrintValueI(50, 0, Motor_Ctrl_Left);
     LED_P6x8Str(0, 1, "PWM_R");
     LED_P6x8Str(50, 1, "     ");
     LED_PrintValueI(50, 1, Motor_Ctrl_Right);
     //LED_P6x8Str(0, 2, "car_e");
     //LED_P6x8Str(50, 2, "          ");
     //LED_PrintValueF(50, 2, diangan_car_e, 3);
     LED_P6x8Str(0, 5, "want_L");
     LED_P6x8Str(50, 5, "    ");
     LED_PrintValueI(50, 5, speed_want_left);
     LED_P6x8Str(0, 6, "want_R");
     LED_P6x8Str(50, 6, "    ");
     LED_PrintValueI(50, 6, speed_want_right);
 }

 /*******************************************************************************
 *  @brief      Oled_view_chasu����
 *  @note       OLED��ʾ���Բ��ٿ���ת���Ĳ���
 *  @data       2020-7-28
 ******************************************************************************/
 void Oled_view_chasu()
 {
     LED_PrintValueF(0, 0, speed_eRule[0], 0);
     LED_PrintValueF(0, 1, speed_eRule[1], 0);
     LED_PrintValueF(0, 2, speed_eRule[2], 0);
     LED_PrintValueF(0, 3, speed_eRule[3], 0);
     LED_PrintValueF(0, 4, speed_eRule[4], 0);
     LED_PrintValueF(50, 0, speed_Rule[0], 0);
     LED_PrintValueF(50, 1, speed_Rule[1], 0);
     LED_PrintValueF(50, 2, speed_Rule[2], 0);
     LED_PrintValueF(50, 3, speed_Rule[3], 0);
     LED_PrintValueF(50, 4, speed_Rule[4], 0);
     LED_PrintValueF(50, 5, diff_confficient2, 0);
 }

 /*******************************************************************************
 *  @brief      OLED_Clear����
 *  @note       ����OLED����
 *  @data       2020-7-27
 ******************************************************************************/
 void OLED_Clear()
 {
     LED_P6x8Str(0, 0, "                          ");
     LED_P6x8Str(0, 1, "                          ");
     LED_P6x8Str(0, 2, "                          ");
     LED_P6x8Str(0, 3, "                          ");
     LED_P6x8Str(0, 4, "                          ");
     LED_P6x8Str(0, 5, "                          ");
     LED_P6x8Str(0, 6, "                          ");
     LED_P6x8Str(0, 7, "                          ");
 }

 /*******************************************************************************
 *  @brief      Kp_change����
 *  @note       �������ĵ���ٶ�
 *  @data       2020-7-17
 ******************************************************************************/ 
 void Kp_change()
 {
     if(gpio_get(BM1) == 1 &&
        gpio_get(BM2) == 0 &&
        gpio_get(BM3) == 0 &&
        gpio_get(BM4) == 0)
     {
         OLED_Clear();
         while(gpio_get(BM1) == 1 && gpio_get(BM2) == 0 && gpio_get(BM3) == 0 &&gpio_get(BM4) == 0)
         {
             Oled_view_duoji();
             if(gpio_get(K1) == 1)
             {
                 systick_delay_ms(100);
                 if(gpio_get(K1) == 1)
                     Kp1 += 1;
                 while(gpio_get(K1));
             }
             if(gpio_get(K2) == 1)
             {
                 systick_delay_ms(100);
                 if(gpio_get(K2) == 1)
                     Kp1 -= 1;
                 while(gpio_get(K2));
             }
             if(gpio_get(K3) == 1)
             {
                 systick_delay_ms(100);
                 if(gpio_get(K3) == 1)
                     Kp2 += 1;
                 while(gpio_get(K3));
             }
             if(gpio_get(K4) == 1)
             {
                 systick_delay_ms(100);
                 if(gpio_get(K4) == 1)
                     Kp2 -= 1;
                 while(gpio_get(K4));
             }
         }
         OLED_Clear();
     }
 }
 
 /*******************************************************************************
 *  @brief      Kd_change����
 *  @note       ��������Kp1ֵ
 *  @data       2020-7-17
 ******************************************************************************/ 
void Kd_change()
 {
     if(gpio_get(BM1) == 1 &&
        gpio_get(BM2) == 1 &&
        gpio_get(BM3) == 0 &&
        gpio_get(BM4) == 0)
    {
        OLED_Clear();
        while(gpio_get(BM1) == 1 && gpio_get(BM2) == 1 && gpio_get(BM3) == 0 &&gpio_get(BM4) == 0)
        {
            Oled_view_duoji();
            if(gpio_get(K1) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K1) == 1)
                    Steer_D_diangan += 1;
                while(gpio_get(K1));
            }
            if(gpio_get(K2) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K2) == 1)
                    Steer_D_diangan -= 1;
                while(gpio_get(K2));
            }
        }
        OLED_Clear();
    }
 } 

 /*******************************************************************************
 *  @brief      e_change����
 *  @note       ��Ƭ����ʾ�����Ը���Kpֵ
 *  @data       2020-7-17
 ******************************************************************************/
 void e_change()
 {
     if(gpio_get(BM1) == 1 &&
        gpio_get(BM2) == 1 &&
        gpio_get(BM3) == 1 &&
        gpio_get(BM4) == 0)
    {
        OLED_Clear();
        while(gpio_get(BM1) == 1 && gpio_get(BM2) == 1 && gpio_get(BM3) == 1 &&gpio_get(BM4) == 0)
        {
            Oled_view_duoji();
            if(gpio_get(K1) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K1) == 1)
                    e1 += 1;
                while(gpio_get(K1));
            }
            if(gpio_get(K2) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K2) == 1)
                    e1 -= 1;
                while(gpio_get(K2));
            }
            if(gpio_get(K3) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K3) == 1)
                    e2 += 1;
                while(gpio_get(K3));
            }
            if(gpio_get(K4) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K4) == 1)
                    e2 -= 1;
                while(gpio_get(K4));
            }
        }
        OLED_Clear();
    }
 }
 
 /*******************************************************************************
 *  @brief      diangan_view����
 *  @note       �鿴�ĸ����ֵ��С
 *  @data       2020-7-17
 ******************************************************************************/ 
 void diangan_view()
 {
     if(gpio_get(BM1) == 0 &&gpio_get(BM2) == 0 )
     {
        OLED_Clear();
        while(gpio_get(BM1) == 0 && gpio_get(BM2) == 0)
        {
            LED_PrintValueI(0, 0, ADCAverage[0]);
            LED_PrintValueI(0, 1, ADCAverage[1]);
            LED_PrintValueI(0, 2, ADCAverage[2]);
            LED_PrintValueI(0, 3, ADCAverage[3]);
            LED_PrintValueI(50, 0, ad[0]);
            LED_PrintValueI(50, 1, ad[1]);
            LED_PrintValueI(50, 2, ad[2]);
            LED_PrintValueI(50, 3, ad[3]);
            LED_PrintValueI(50, 4, ad[4]);
            LED_PrintValueI(50, 5, ad[5]);
            LED_PrintValueI(50, 6, ad[6]);
        }
        OLED_Clear();
     }
 }

 /*******************************************************************************
 *  @brief      Kp_change����
 *  @note       ��������Kp2ֵ
 *  @data       2020-7-18
 ******************************************************************************/ 
 void chasu_change()
 {
     if(gpio_get(BM1) == 0 &&
        gpio_get(BM2) == 1 &&
        gpio_get(BM3) == 0 &&
        gpio_get(BM4) == 0)
    {
        OLED_Clear();
        while(gpio_get(BM1) == 0 && gpio_get(BM2) == 1 && gpio_get(BM3) == 0 &&gpio_get(BM4) == 0)
        {
            Oled_view_chasu();
            if(gpio_get(K1) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K1) == 1)
                    diff_confficient2 += 1;
                while(gpio_get(K1));
            }
            if(gpio_get(K2) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K2) == 1)
                    diff_confficient2 -= 1;
                while(gpio_get(K2));
            }
            if(gpio_get(K4) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K4) == 1)
                    Oled_view_dianji();
                while(gpio_get(K4));
            }
        }
        OLED_Clear();
    }
 }

 /*******************************************************************************
 *  @brief      e_change_xiao����
 *  @note       ��������e1ֵ
 *  @data       2020-7-18
 ******************************************************************************/ 
 /*void e_change_xiao()
 {
     if(gpio_get(BM1) == 0 &&
        gpio_get(BM2) == 1 &&
        gpio_get(BM3) == 1 &&
        gpio_get(BM4) == 0)
    {
        while(gpio_get(BM1) == 0 && gpio_get(BM2) == 1 && gpio_get(BM3) == 1 &&gpio_get(BM4) == 0)
        {
            Oled_view_dianji();
            if(gpio_get(K1) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K1) == 1)
                    e1 += 1;
                while(gpio_get(K1));
            }
            if(gpio_get(K2) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K2) == 1)
                    e1 -= 1;
                while(gpio_get(K2));
            }
        }
    }
 }*/

 /*******************************************************************************
 *  @brief      e_change_da����
 *  @note       ��������e2ֵ
 *  @data       2020-7-19
 ******************************************************************************/ 
 /*void e_change_da()
 {
     if(gpio_get(BM1) == 0 &&
        gpio_get(BM2) == 1 &&
        gpio_get(BM3) == 0 &&
        gpio_get(BM4) == 0)
    {
        while(gpio_get(BM1) == 0 && gpio_get(BM2) == 1 && gpio_get(BM3) == 0 &&gpio_get(BM4) == 0)
        {
            Oled_view_duoji();
            if(gpio_get(K1) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K1) == 1)
                    e2 += 1;
                while(gpio_get(K1));
            }
            if(gpio_get(K3) == 1)
            {
                systick_delay_ms(100);
                if(gpio_get(K3) == 1)
                    e2 -= 1;
                while(gpio_get(K3));
            }
        }
    }
 }*/

 /*******************************************************************************
 *  @brief      ksilsnys����
 *  @note       ���ò��뿪��ʵ�������������ݵĴ���Ͽ�
 *  @data       2020-7-29
 ******************************************************************************/ 
 void kailanya()
 {
   
   if(gpio_get(BM4) == 1 && bluetooth == 1)
     {
         bluetooth = 0;
     }
     if(gpio_get(BM4) == 0 && bluetooth == 0)
     {
        bluetooth = 1;
     }
   
   //bluetooth = 0;
 }