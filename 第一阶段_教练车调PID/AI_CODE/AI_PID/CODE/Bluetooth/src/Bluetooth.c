/*!
 * @file       Bluetooth.c
 * @brief      ����������ֵ����
 * @author     
 * @version    v1.0
 * @date       2020-3-17
 */
 
 #include "headfile.h"
 #include "smartcar.h"
 
 uint16 diangan[7][convert_count] = {0};   //�ɼ������߸����ֵ
 uint8 ad[7] = {0};   //ѹ����-128-+127�ĵ��ֵ
 uint16 ADSum[7] = {0};   //���ȡƽ��������͵�����
 uint8 Steernow = 0;   //�����ǰPWMѹ����-128-+127��ֵ
 
 /*******************************************************************************
 *  @brief      AD_Convert����
 *  @note       �ɼ������Ϣ�����ڴ����ģ��ѵ������ǰհ��·���ֵ
 *  @data       2020-7-21 
 ******************************************************************************/
 void AD_Convert()
{
    uint8 i;
    for(i=0;i<convert_count;i++)   //ÿ�����ÿ��ɼ�SamplingNum�ε��ֵ
    {
        diangan[0][i] = adc_convert(ADC_1,AI_ADC1);
        diangan[1][i] = adc_convert(ADC_1,AI_ADC2);
        diangan[2][i] = adc_convert(ADC_1,AI_ADC3);
        diangan[3][i] = adc_convert(ADC_1,AI_ADC4);
        diangan[4][i] = adc_convert(ADC_1,AI_ADC5);
        diangan[5][i] = adc_convert(ADC_1,AI_ADC6);
        diangan[6][i] = adc_convert(ADC_1,AI_ADC7);
    }
}

 /*******************************************************************************
 *  @brief      AD_sort����
 *  @note       �Բɼ������߸���н��д�С�����Ա���ȥ�������С����ƽ��
 *  @data       2020-7-21 
 ******************************************************************************/
 void AD_sort()
{
    uint8 i,j,k;
    uint16 temp;
    for(i=0;i<(convert_count-1);i++)   //ð�����򷨣�ȥ�����ֵ����Сֵ
    {
        for(j=0;j<(convert_count-i);j++)
        {
            for(k=0;k<7;k++)
            {
                if(diangan[k][i]>diangan[k][i+1])
                {
                    temp = diangan[k][i];
                    diangan[k][i] = diangan[k][j];
                    diangan[k][j] = temp;
                }
            }
        }
    }
}

 /*******************************************************************************
 *  @brief      AD_average����
 *  @note       �Բɼ������߸������ƽ��
 *  @data       2020-7-21
 ******************************************************************************/
 void AD_average()
{
    uint8 k,j;
    for(k=0;k<7;k++)
    {
        for(j=remove_count_num;j<(convert_count-remove_count_num);j++)
        {
            ADSum[k] += diangan[k][j];
        }
        ad[k] = (uint8)(ADSum[k]/3);
        ADSum[k]=0;
    }
}
/*******************************************************************************
 *  @brief      DUOJI_Code����
 *  @note       �������ת�����PWMѹ����-128-+127
 *  @data       2020-3-17 
 ******************************************************************************/
 void DUOJI_Code()
{
   Steernow  = (uint8)(((float)(SteerCtrl - MinSteering)/(float)(MaxSteering - MinSteering))*255);
}

/*******************************************************************************
 *  @brief      Bluetooth_Send����
 *  @note       ����������������
 *  @data       2020-3-17 
 ******************************************************************************/
 void Bluetooth_send()
{
    uint8 i = 0;
    AD_Convert();
    AD_sort();
    AD_average();
    DUOJI_Code();
    for(i=0;i<7;i++)
    {
        uart_putchar(USART_8,ad[i]);
    }
    uart_putchar(USART_8,Steernow);
    uart_putchar(USART_8,0x5A);
}


