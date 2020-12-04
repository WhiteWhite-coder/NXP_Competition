/*!
 * @file       Send.c
 * @brief      ADC���ݲɼ��Ӿ�ֵ�˲�
 * @author     
 * @version    v1.0
 * @date       2020--7-16
 */

 #include "headfile.h"
 #include "smartcar.h" 

uint16 AI_ADC[7] = {0};   //��ʾ����AI�����е�е�ֵ������ʾ

 /*******************************************************************************
 *  @brief      AI_diangan_get����
 *  @note       �鿴����AI���߸���е�ֵ���������Դ������ݵ���ȷ��
 *  @data       2020-7-16 
 ******************************************************************************/
void AI_diangan_get()
{
    uint i = 0;
    uint16 a[7] = {0.0};
    for(i=0;i<5;i++)
    {
        a[0] = adc_convert(ADC_1,AI_ADC1);
        AI_ADC[0] = AI_ADC[0] + a[0];
        a[1] = adc_convert(ADC_1,AI_ADC2);
        AI_ADC[1] = AI_ADC[1] + a[1];
        a[2] = adc_convert(ADC_1,AI_ADC3);
        AI_ADC[2] = AI_ADC[2] + a[2];
        a[3] = adc_convert(ADC_1,AI_ADC4);
        AI_ADC[3] = AI_ADC[3] + a[3];
        a[4] = adc_convert(ADC_1,AI_ADC5);
        AI_ADC[4] = AI_ADC[4] + a[4];
        a[5] = adc_convert(ADC_1,AI_ADC6);
        AI_ADC[5] = AI_ADC[5] + a[5];
        a[6] = adc_convert(ADC_1,AI_ADC7);
        AI_ADC[6] = AI_ADC[6] + a[6];
    }
    AI_ADC[0] = AI_ADC[0] / 5;
    AI_ADC[1] = AI_ADC[1] / 5;
    AI_ADC[2] = AI_ADC[2] / 5;
    AI_ADC[3] = AI_ADC[3] / 5;
    AI_ADC[4] = AI_ADC[4] / 5;
    AI_ADC[5] = AI_ADC[5] / 5;
    AI_ADC[6] = AI_ADC[6] / 5;
}
 
