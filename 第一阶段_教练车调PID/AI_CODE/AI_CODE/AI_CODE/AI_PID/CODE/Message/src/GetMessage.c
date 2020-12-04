/*!
 * @file       GetMessage.c
 * @brief      �ɼ���Ϣ����
 * @author     
 * @version    v1.0
 * @date       2020-3-5
 */

#include "headfile.h"
#include "smartcar.h"

//----------------------------------------------------------------------------------
//��Ҫ�������ɼ����������ֵ
//��Ҫȷ��diangan_e1��diangan_e2�Ƿ�Ϊ���������
//----------------------------------------------------------------------------------

uint16 ADCMessage[Number][SamplingNum] = {0};   //Number����вɼ�SamplingNum����Ϣ
uint16 ADCSum[Number] = {0};   //ÿ����еĲɼ���Ϣ֮��
uint16 ADCAverage[Number] = {0};   //ÿ����е�ƽ��ֵ
float ADCNormal[Number] = {0.0};   //��й�һ��
uint16 ADCMaxing[Number] = {3600,3600,3600,3600};   //�������ֵ
float diangan_e = 0.0;   //�������
float diangan_e1 = 0.0;   //���1
float diangan_e2 = 0.0;   //���2
float diangan_last_e = 0.0;   //�ϴ����
float diangan_ec = 0.0;   //�������仯��
uint16 speed_now_left = 0;   //���ֵ�ǰ�ٶ�
uint16 speed_want_left = 0;   //���������ٶ�
uint16 speed_e_left = 0;   //���ֱ����ٶ����
uint16 speed_last_e_left = 0;   //�����ϴ��ٶ����
uint16 speed_ec_left = 0;   //���ֱ����ٶ����仯��
uint16 speed_last_ec_left = 0;   //�����ϴ��ٶ����仯��
uint16 speed_now_right = 0;   //���ֵ�ǰ�ٶ�
uint16 speed_want_right = 0;   //���������ٶ�
uint16 speed_e_right = 0;   //���ֱ����ٶ����
uint16 speed_last_e_right = 0;   //�����ϴ��ٶ����
uint16 speed_ec_right = 0;   //���ֱ����ٶ����仯��
uint16 speed_last_ec_right = 0;   //�����ϴ��ٶ����仯��

/*******************************************************************************
 *  @brief      GetMessage����
 *  @note       �ɼ������Ϣ��Number����вɼ�SamplingNum��
 *  @data       2020-3-5 
 ******************************************************************************/
void GetMessage()
{
    uint8 i;
    for(i=0;i<SamplingNum;i++)   //ÿ�����ÿ��ɼ�SamplingNum�ε��ֵ
    {
        ADCMessage[0][i] = adc_convert(ADC_2,SteerADC1);
        ADCMessage[1][i] = adc_convert(ADC_2,SteerADC2);
        ADCMessage[2][i] = adc_convert(ADC_2,SteerADC3);
        ADCMessage[3][i] = adc_convert(ADC_2,SteerADC4);
    }
}

/*******************************************************************************
 *  @brief      ADC_Sort����
 *  @note       �ɼ����ĵ����Ϣ���򣬷�����ͷȥβȡƽ��
 *  @date       2020-3-5 
 ******************************************************************************/
void ADC_Sort()   
{
    uint8 i,j,k;
    uint16 temp;
    for(i=0;i<(SamplingNum-1);i++)   //ð�����򷨣�ȥ�����ֵ����Сֵ
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
 *  @brief      ADC_Average����
 *  @note       ����ƽ��ֵ��������ͷȥβȡƽ��
 *  @date       2020-3-5 
 ******************************************************************************/
void ADC_Average()   
{
    uint8 k,j;
    for(k=0;k<4;k++)
    {
        for(j=Min_SamplingNum;j<(SamplingNum-Min_SamplingNum);j++)   //���ֵ���
        {
            ADCSum[k] += ADCMessage[k][j];
        }
        ADCAverage[k] = ADCSum[k] / (SamplingNum-2*Min_SamplingNum);   //��ȥ�����ֵ����Сֵ���ƽ��ֵ
        ADCSum[k] = 0;
    }
}

/*******************************************************************************
 *  @brief      Normal����
 *  @note       ��й�һ������
 *  @date       2020-3-5 
 ******************************************************************************/
void Normal()
{
    uint8 k;
    for(k=0;k<4;k++)
    {
        ADCNormal[k] = (float)ADCAverage[k] / (float)ADCMaxing[k];
    }
    if(ADCNormal[0]<=0.001)  ADCNormal[0]=0.001;   //�����ֵ��С��ȡ0.001 
    if(ADCNormal[1]<=0.001)  ADCNormal[1]=0.001; 
    if(ADCNormal[2]<=0.001)  ADCNormal[2]=0.001; 
    if(ADCNormal[3]<=0.001)  ADCNormal[3]=0.001; 
}

/*******************************************************************************
 *  @brief      Cal_error����
 *  @note       ��������㺯�� ,ƫ�����������仯��
 *  @date       2020-3-5 
 ******************************************************************************/
void Cal_error()   
{
    diangan_last_e = diangan_e;   //��һ�����
    diangan_e1 = sqrt(ADCNormal[0]*ADCNormal[0]+ADCNormal[1]*ADCNormal[1]);   //��(x1*x1+x2*x2)
    diangan_e2 = sqrt(ADCNormal[2]*ADCNormal[2]+ADCNormal[3]*ADCNormal[3]);   //��(x3*x3+x4*x4)
    diangan_e = (int16)(((sqrt(diangan_e1)-sqrt(diangan_e2)) / (diangan_e1+diangan_e2)) * 100);   //��e1-��e2
    if(diangan_e>=250)   diangan_e = 250;   //�����ͻ���                                        ---------
    if(diangan_e<=-250)   diangan_e = -250;                                                     //e1+e2
    diangan_ec = diangan_e - diangan_last_e;//���仯��
}

/*******************************************************************************
 *  @brief      ADC_Processing����
 *  @note       ADCȫ���Ķ���
 *  @date       2020-3-5 
 ******************************************************************************/
void ADC_Processing()
{                               //��pid��н��вɼ��ʹ���
    GetMessage();               //�ɼ�
    ADC_Sort();                 //ð�ݣ���ͷȥβ
    ADC_Average();              //��ƽ��
    Normal();                   //��һ��
    Cal_error();                //�������
}

/*******************************************************************************
 *  @brief      Speed_error_Left����
 *  @note       ���������㺯��
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
 *  @brief      Speed_error_Right����
 *  @note       ���������㺯��
 *  @date       2020-3-8
 ******************************************************************************/
void Speed_error_Right()
{
    speed_last_e_right = speed_e_right; 
    speed_last_ec_right = speed_ec_right;
    speed_e_right = speed_want_right - speed_now_right;
    speed_ec_right = speed_e_right - speed_last_e_right;
}



