/*!
 * @file       Steer.c
 * @brief      倶字陣崙痕方
 * @author     
 * @version    v1.0
 * @date       2020-3-7
 */

#include "headfile.h"
#include "smartcar.h"

//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
//倶字屎嶄峙俶勣霞協
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
int16 MidSteering = 714;   //倶字屎嶄PWM峙
int16 SteerCtrl = 714,SteerLastCtrl = 714;   //倶字媼腎曳
int16 Steererror = 0;
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
//倶字恣諾陶峙才嘔諾陶峙俶勣霞協
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
int16 MaxSteering = 789,MinSteering = 639;   //倶字隠擦恣諾陶/倶字嘔諾陶

/*******************************************************************************
 *  @brief       Steer_Ctrl痕方
 *  @note       倶字陣崙痕方
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
    SteerCtrl = MidSteering + (Steererror / 50);   //列餓廬晒葎PWM
    if(SteerCtrl<=MinSteering)   SteerCtrl = MinSteering;   //恣諾陶/嘔諾陶隠擦
    if(SteerCtrl>=MaxSteering)   SteerCtrl = MaxSteering;
}