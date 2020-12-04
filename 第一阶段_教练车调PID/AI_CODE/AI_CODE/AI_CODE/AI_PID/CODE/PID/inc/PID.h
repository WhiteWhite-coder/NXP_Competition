/*!
 * @file       FuzzyPID.h
 * @brief       模糊控制PID函数
 * @author     
 * @version    v1.0
 * @date       2020-1-26
 */

#ifndef __FUZZYPID_H__
#define __FUZZYPID_H__

//电感模糊控制参数
extern float e_Rule_diangan[5];  //输入误差（e）的范围，由负到正 
extern float ec_Rule_diangan[5];   //输入误差变化率（ec）的范围，由负到正
extern float kp_Rule_diangan[5];   //输出的P值的范围
extern float kd_Rule_diangan[5];   //输出的D值的范围
//模糊控制隶属度计算
extern float eFuzzy[2];   //误差e属于前后两个模糊集的隶属度
extern float ecFuzzy[2];   //误差ec属于前后两个模糊集的隶属度
//查询模糊规则表时记录隶属度的位置
extern uint8 pe;   //误差e的隶属度的位置
extern uint8 pec;   //误差ec的隶属度的位置
//查询模糊规则表后每个模糊子集的隶属度还原
extern float Fuzzy_kp[6];   //P值模糊规则表的隶属度还原
extern float Fuzzy_kd[6];   //D值模糊规则表的隶属度还原
//电感模糊控制结果
extern float Steer_P_diangan;   //电感结果的舵机的输出值
extern float Steer_D_diangan;

extern uint16 Variable;
//
extern float D_diangan;
extern float P_diangan;
//控制规则表
extern int kp_Rule_table[6][6];   //P值模糊规则表
extern int kd_Rule_table[6][6];   //D值模糊规则表
//电机PID值
extern float Motor_P;
extern float Motor_I;
extern float Motor_D;
//模糊初始化参数
extern uint16 Kp1;
extern uint16 Kp2;   
extern uint16 e1;
extern uint16 e2;

void fuzzy_canshu_init();
void fuzzy_mem_cal_diangan();   //隶属度计算函数
void fuzzy_query_diangan();   //查询模糊规则表
void fuzzy_solve_diangan();   //重心法解模糊

#endif