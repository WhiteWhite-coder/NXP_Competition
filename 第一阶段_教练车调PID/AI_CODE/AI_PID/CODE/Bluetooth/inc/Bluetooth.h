/*!
 * @file       Bluetooth.h
 * @brief       ����������ֵ����
 * @author     
 * @version    v1.0
 * @date       2020-3-17
 */
 
 #ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

 #define convert_count 5
 #define remove_count_num 1

 extern uint16 diangan[7][convert_count];   //�ɼ������߸����ֵ
 extern uint16 ADSum[7];
 extern uint8 ad[7];   //ѹ����-128-+127�ĵ��ֵ
 extern uint8 Steernow;   //�����ǰPWMѹ����-128-+127��ֵ
 
 void AD_Convert();   //�ɼ������Ϣ�����ڴ����ģ��ѵ������ǰհ��·���ֵ
 void AD_sort();   //�Բɼ����ĵ��߸����ֵ��������ȥ�������С
 void AD_average();   //���߸���е�ֵȡƽ��������ֵ��-128~127֮��
 void DUOJI_Code();   //�������ת�����PWMѹ����-128-+127
 void Bluetooth_send();   //����������������

#endif
