/*!
 * @file       AllInit.c
 * @brief      ��ʼ������
 * @author     
 * @version    v1.0
 * @date       2020-3-4
 */

#include "headfile.h"
#include "smartcar.h"

/*******************************************************************************
 *  @brief      All_Init����
 *  @note       ����������ʼ������
 *  @date    2020-3-4 
 ******************************************************************************/
void All_Init()
{
/**************���Ƶ�г�ʼ��***************/
    adc_init(ADC_2,SteerADC1,ADC_12BIT);
    adc_init(ADC_2,SteerADC2,ADC_12BIT);
    adc_init(ADC_2,SteerADC3,ADC_12BIT);
    adc_init(ADC_2,SteerADC4,ADC_12BIT);
/**************�����ʼ��***************/
    pwm_init(DUOJI_Channel, 50, MidSteering*TIMES);   //50Hz
/**************�����ʼ��***************/
    pwm_init(Motor_Go_L, 13*1000, 300*TIMES*10);   //13kHz
    pwm_init(Motor_Go_R, 13*1000, 300*TIMES*10);
    pwm_init(Motor_Return_L, 13*1000, 0*TIMES*10);
    pwm_init(Motor_Return_R, 13*1000, 0*TIMES*10);
/**************ģ�͵�г�ʼ��***************/
    adc_init(ADC_1,AI_ADC1,ADC_8BIT);
    adc_init(ADC_1,AI_ADC2,ADC_8BIT);
    adc_init(ADC_1,AI_ADC3,ADC_8BIT);
    adc_init(ADC_1,AI_ADC4,ADC_8BIT);
    adc_init(ADC_1,AI_ADC5,ADC_8BIT);
    adc_init(ADC_1,AI_ADC6,ADC_8BIT);
    adc_init(ADC_1,AI_ADC7,ADC_8BIT);
/**************������**************/
    gpio_init(BEEP,GPO,1,GPIO_PIN_CONFIG);   //���
/**************����ת������ʼ��**************/
    uart_init (USART_8,115200,UART8_TX,UART8_RX);
/**************OLED��ʼ��**************/
    OLED_Init();
/**************��������ʼ��**************/    
    qtimer_quad_init(QTIMER_1,Speed_A1,Speed_B1);
    qtimer_quad_init(QTIMER_1,Speed_A2,Speed_B2);
/**************������ʼ��**************/
    gpio_init(K1,GPI,0,GPIO_PIN_CONFIG);
    gpio_init(K2,GPI,0,GPIO_PIN_CONFIG);
    gpio_init(K3,GPI,0,GPIO_PIN_CONFIG);
    gpio_init(K4,GPI,0,GPIO_PIN_CONFIG);
/**************���뿪�س�ʼ��**************/
    gpio_init(BM1,GPI,0,GPIO_PIN_CONFIG);
    gpio_init(BM2,GPI,0,GPIO_PIN_CONFIG);
    gpio_init(BM3,GPI,0,GPIO_PIN_CONFIG);
    gpio_init(BM4,GPI,0,GPIO_PIN_CONFIG);
/**************gpio�ж������س�ʼ��**************/
    gpio_interrupt_init(CarStop,FALLING,GPIO_INT_CONFIG);
    NVIC_SetPriority(GPIO2_Combined_16_31_IRQn,15);
}

/*******************************************************************************
 *  @brief      pitinit����
 *  @note       ��ʱ��ͨ����ʼ������ʱ��ʼ��ͨ��pit0(10ms)��pit1(10ms)
 *  @date       2020-4-14
 ******************************************************************************/
void pitinit()
{
    pit_init();                     //��ʼ��pit����
    pit_interrupt_ms(PIT_CH0,10);   //��ʼ��pitͨ��0 ����10ms
    pit_interrupt_ms(PIT_CH1,10);   //��ʼ��pitͨ��1 ����10ms
    //pit_interrupt_ms(PIT_CH2,2300);
    NVIC_SetPriority(PIT_IRQn,0);  //�����ж����ȼ� ��Χ0-15 ԽС���ȼ�Խ�� ��·PIT����һ��PIT�жϺ���
}
