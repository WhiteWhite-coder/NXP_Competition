/*!
 * @file       Bluetooth.h
 * @brief       蓝牙传输电感值函数
 * @author     
 * @version    v1.0
 * @date       2020-3-17
 */
 
 #ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

 #define convert_count 5
 #define remove_count_num 1

 extern uint16 diangan[7][convert_count];   //采集到的七个电感值
 extern uint16 ADSum[7];
 extern uint8 ad[7];   //压缩到-128-+127的电感值
 extern uint8 Steernow;   //舵机当前PWM压缩到-128-+127的值
 
 void AD_Convert();   //采集电感信息，用于传输给模型训练，短前瞻七路电感值
 void AD_sort();   //对采集到的的七个电感值进行排序并去除最大最小
 void AD_average();   //对七个电感的值取平均，所得值在-128~127之间
 void DUOJI_Code();   //将舵机的转向输出PWM压缩到-128-+127
 void Bluetooth_send();   //利用蓝牙传输数据

#endif
