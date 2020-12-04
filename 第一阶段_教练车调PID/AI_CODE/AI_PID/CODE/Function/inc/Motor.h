/*!
 * @file       Motor.h
 * @brief      电机控制函数
 * @author     
 * @version    v1.0
 * @date       2020-3-9
 */

#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "headfile.h"
#include "smartcar.h"

extern uint16 Motor_Ctrl_Left;
extern uint16 Motor_Ctrl_Right;
extern uint16 Motor_Last_Left;
extern uint16 Motor_Last_Right;
extern int16 Motor_error_Left;
extern int16 Motor_error_Right;
extern uint16 MaxMotoring;
extern uint16 MinMotoring;
extern float diff_confficient2 ;
extern uint16 speed_want;
extern uint8 stop_flag;

extern float speed_e;  
extern float speed_ec; 
extern float speed_Fuzzy[7];
extern int16 speed_want_error;
extern uint8 speed_pe;
extern uint8 speed_pec;
extern float speed_eRule[7];   
extern float speed_ec_Rule[7];
extern float speed_Rule[7];
extern int speed_rule[8][8];
extern uint16 motor_speed;
extern uint8 dat;
extern int16 number1;
extern int16 motor;
extern uint8 number;
extern uint8 bluetooth;

void Motor_Ctrl();
void speed_fuzzy_mem_cal_forecast(void);
void speed_fuzzy_query_forecast(void);
void speed_fuzzy_solve_forecast(void);
void Speed_forecast();
void motor_l();
void Stop_car();

#endif