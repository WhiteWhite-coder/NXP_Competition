/*!
 * @file       FuzzyPID.h
 * @brief       ģ������PID����
 * @author     
 * @version    v1.0
 * @date       2020-1-26
 */

#ifndef __FUZZYPID_H__
#define __FUZZYPID_H__

//���ģ�����Ʋ���
extern float e_Rule_diangan[5];  //������e���ķ�Χ���ɸ����� 
extern float ec_Rule_diangan[5];   //�������仯�ʣ�ec���ķ�Χ���ɸ�����
extern float kp_Rule_diangan[5];   //�����Pֵ�ķ�Χ
extern float kd_Rule_diangan[5];   //�����Dֵ�ķ�Χ
//ģ�����������ȼ���
extern float eFuzzy[2];   //���e����ǰ������ģ������������
extern float ecFuzzy[2];   //���ec����ǰ������ģ������������
//��ѯģ�������ʱ��¼�����ȵ�λ��
extern uint8 pe;   //���e�������ȵ�λ��
extern uint8 pec;   //���ec�������ȵ�λ��
//��ѯģ��������ÿ��ģ���Ӽ��������Ȼ�ԭ
extern float Fuzzy_kp[6];   //Pֵģ�������������Ȼ�ԭ
extern float Fuzzy_kd[6];   //Dֵģ�������������Ȼ�ԭ
//���ģ�����ƽ��
extern float Steer_P_diangan;   //��н���Ķ�������ֵ
extern float Steer_D_diangan;

extern uint16 Variable;
//
extern float D_diangan;
extern float P_diangan;
//���ƹ����
extern int kp_Rule_table[6][6];   //Pֵģ�������
extern int kd_Rule_table[6][6];   //Dֵģ�������
//���PIDֵ
extern float Motor_P;
extern float Motor_I;
extern float Motor_D;
//ģ����ʼ������
extern uint16 Kp1;
extern uint16 Kp2;   
extern uint16 e1;
extern uint16 e2;

void fuzzy_canshu_init();
void fuzzy_mem_cal_diangan();   //�����ȼ��㺯��
void fuzzy_query_diangan();   //��ѯģ�������
void fuzzy_solve_diangan();   //���ķ���ģ��

#endif