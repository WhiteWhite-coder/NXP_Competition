/*!
 * @file       GetMessage.c
 * @brief      采集信息函数
 * @author     
 * @version    v1.0
 * @date       2020-3-5
 */

#include "headfile.h"
#include "smartcar.h"

//----------------------------------------------------------------------------------
//需要测量待采集的赛道最大值
//需要确定diangan_e1和diangan_e2是否为两横和两竖
//----------------------------------------------------------------------------------

uint16 ADCMessage[Number][SamplingNum] = {0};   //Number个电感采集SamplingNum组信息
uint16 ADCSum[Number] = {0};   //每个电感的采集信息之和
uint16 ADCAverage[Number] = {0};   //每个电感的平均值
float ADCNormal[Number] = {0.0};   //电感归一化
uint16 ADCMaxing[Number] = {3600,3600,3600,3600};   //赛道最大值
float diangan_e = 0.0;   //本次误差
float diangan_e1 = 0.0;   //误差1
float diangan_e2 = 0.0;   //误差2
float diangan_last_e = 0.0;   //上次误差
float diangan_ec = 0.0;   //本次误差变化率
uint16 speed_now_left = 0;   //左轮当前速度
uint16 speed_want_left = 0;   //左轮期望速度
uint16 speed_e_left = 0;   //左轮本次速度误差
uint16 speed_last_e_left = 0;   //左轮上次速度误差
uint16 speed_ec_left = 0;   //左轮本次速度误差变化率
uint16 speed_last_ec_left = 0;   //左轮上次速度误差变化率
uint16 speed_now_right = 0;   //右轮当前速度
uint16 speed_want_right = 0;   //右轮期望速度
uint16 speed_e_right = 0;   //右轮本次速度误差
uint16 speed_last_e_right = 0;   //右轮上次速度误差
uint16 speed_ec_right = 0;   //右轮本次速度误差变化率
uint16 speed_last_ec_right = 0;   //右轮上次速度误差变化率

/*******************************************************************************
 *  @brief      GetMessage函数
 *  @note       采集电感信息，Number个电感采集SamplingNum次
 *  @data       2020-3-5 
 ******************************************************************************/
void GetMessage()
{
    uint8 i;
    for(i=0;i<SamplingNum;i++)   //每个电感每组采集SamplingNum次电感值
    {
        ADCMessage[0][i] = adc_convert(ADC_2,SteerADC1);
        ADCMessage[1][i] = adc_convert(ADC_2,SteerADC2);
        ADCMessage[2][i] = adc_convert(ADC_2,SteerADC3);
        ADCMessage[3][i] = adc_convert(ADC_2,SteerADC4);
    }
}

/*******************************************************************************
 *  @brief      ADC_Sort函数
 *  @note       采集到的电感信息排序，方便掐头去尾取平均
 *  @date       2020-3-5 
 ******************************************************************************/
void ADC_Sort()   
{
    uint8 i,j,k;
    uint16 temp;
    for(i=0;i<(SamplingNum-1);i++)   //冒泡排序法，去除最大值和最小值
    {
        for(j=0;j<(SamplingNum-i);j++)
        {
            for(k=0;k<4;k++)
            {
                if(ADCMessage[k][i]>ADCMessage[k][i+1])
                {
                    temp = ADCMessage[k][i];
                    ADCMessage[k][i] = ADCMessage[k][j];
                    ADCMessage[k][j] = temp;
                }
            }
        }
    }
}

/*******************************************************************************
 *  @brief      ADC_Average函数
 *  @note       求电感平均值函数，掐头去尾取平均
 *  @date       2020-3-5 
 ******************************************************************************/
void ADC_Average()   
{
    uint8 k,j;
    for(k=0;k<4;k++)
    {
        for(j=Min_SamplingNum;j<(SamplingNum-Min_SamplingNum);j++)   //电感值求和
        {
            ADCSum[k] += ADCMessage[k][j];
        }
        ADCAverage[k] = ADCSum[k] / (SamplingNum-2*Min_SamplingNum);   //求去除最大值和最小值后的平均值
        ADCSum[k] = 0;
    }
}

/*******************************************************************************
 *  @brief      Normal函数
 *  @note       电感归一化函数
 *  @date       2020-3-5 
 ******************************************************************************/
void Normal()
{
    uint8 k;
    for(k=0;k<4;k++)
    {
        ADCNormal[k] = (float)ADCAverage[k] / (float)ADCMaxing[k];
    }
    if(ADCNormal[0]<=0.001)  ADCNormal[0]=0.001;   //若电感值过小，取0.001 
    if(ADCNormal[1]<=0.001)  ADCNormal[1]=0.001; 
    if(ADCNormal[2]<=0.001)  ADCNormal[2]=0.001; 
    if(ADCNormal[3]<=0.001)  ADCNormal[3]=0.001; 
}

/*******************************************************************************
 *  @brief      Cal_error函数
 *  @note       电感误差计算函数 ,偏差法求出误差和误差变化率
 *  @date       2020-3-5 
 ******************************************************************************/
void Cal_error()   
{
    diangan_last_e = diangan_e;   //上一次误差
    diangan_e1 = sqrt(ADCNormal[0]*ADCNormal[0]+ADCNormal[1]*ADCNormal[1]);   //√(x1*x1+x2*x2)
    diangan_e2 = sqrt(ADCNormal[2]*ADCNormal[2]+ADCNormal[3]*ADCNormal[3]);   //√(x3*x3+x4*x4)
    diangan_e = (int16)(((sqrt(diangan_e1)-sqrt(diangan_e2)) / (diangan_e1+diangan_e2)) * 100);   //√e1-√e2
    if(diangan_e>=250)   diangan_e = 250;   //抗饱和积分                                        ---------
    if(diangan_e<=-250)   diangan_e = -250;                                                     //e1+e2
    diangan_ec = diangan_e - diangan_last_e;//误差变化率
}

/*******************************************************************************
 *  @brief      ADC_Processing函数
 *  @note       ADC全部的动作
 *  @date       2020-3-5 
 ******************************************************************************/
void ADC_Processing()
{                               //对pid电感进行采集和处理
    GetMessage();               //采集
    ADC_Sort();                 //冒泡，掐头去尾
    ADC_Average();              //求平均
    Normal();                   //归一化
    Cal_error();                //计算误差
}

/*******************************************************************************
 *  @brief      Speed_error_Left函数
 *  @note       左轮误差计算函数
 *  @date       2020-3-7
 ******************************************************************************/
void Speed_error_Left()
{
    speed_last_e_left = speed_e_left;
    speed_last_ec_left = speed_ec_left;
    speed_e_left = speed_want_left - speed_now_left;
    speed_ec_left = speed_e_left - speed_last_e_left;
}

/*******************************************************************************
 *  @brief      Speed_error_Right函数
 *  @note       右轮误差计算函数
 *  @date       2020-3-8
 ******************************************************************************/
void Speed_error_Right()
{
    speed_last_e_right = speed_e_right; 
    speed_last_ec_right = speed_ec_right;
    speed_e_right = speed_want_right - speed_now_right;
    speed_ec_right = speed_e_right - speed_last_e_right;
}



