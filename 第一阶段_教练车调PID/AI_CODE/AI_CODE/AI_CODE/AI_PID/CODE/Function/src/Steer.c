/*!
 * @file       Steer.c
 * @brief      ¶æ»ú¿ØÖÆº¯Êý
 * @author     
 * @version    v1.0
 * @date       2020-3-7
 */

#include "headfile.h"
#include "smartcar.h"

//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¶æ»úÕýÖÐÖµÐèÒª²â¶¨
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
int16 MidSteering = 714;   //¶æ»úÕýÖÐPWMÖµ
int16 SteerCtrl = 714,SteerLastCtrl = 714;   //¶æ»úÕ¼¿Õ±È
int16 Steererror = 0;
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
//¶æ»ú×óÂúÆ«ÖµºÍÓÒÂúÆ«ÖµÐèÒª²â¶¨
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
int16 MaxSteering = 789,MinSteering = 639;   //¶æ»ú±£»¤×óÂúÆ«/¶æ»úÓÒÂúÆ«

/*******************************************************************************
 *  @brief       Steer_Ctrlº¯Êý
 *  @note       ¶æ»ú¿ØÖÆº¯Êý
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
    Steererror = (int16)(P_diangan*diangan_e     //P*£¨E£¨k£©-E£¨k-1£©£©
                        + D_diangan*diangan_ec);   //D*£¨E£¨k£©-2E£¨k-1£©+E£¨k-2£©£©
    SteerLastCtrl = SteerCtrl;
    SteerCtrl = MidSteering + (Steererror / 50);   //Îó²î×ª»¯ÎªPWM
    if(SteerCtrl<=MinSteering)   SteerCtrl = MinSteering;   //×óÂúÆ«/ÓÒÂúÆ«±£»¤
    if(SteerCtrl>=MaxSteering)   SteerCtrl = MaxSteering;
}