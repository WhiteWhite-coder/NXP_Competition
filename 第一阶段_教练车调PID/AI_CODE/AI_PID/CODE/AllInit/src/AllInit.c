/*!
 * @file       AllInit.c
 * @brief      初始化函数
 * @author     
 * @version    v1.0
 * @date       2020-3-4
 */

#include "headfile.h"
#include "smartcar.h"

/*******************************************************************************
 *  @brief      All_Init函数
 *  @note       所有器件初始化函数
 *  @date    2020-3-4 
 ******************************************************************************/
void All_Init()
{
/**************控制电感初始化***************/
    adc_init(ADC_2,SteerADC1,ADC_12BIT);
    adc_init(ADC_2,SteerADC2,ADC_12BIT);
    adc_init(ADC_2,SteerADC3,ADC_12BIT);
    adc_init(ADC_2,SteerADC4,ADC_12BIT);
/**************舵机初始化***************/
    pwm_init(DUOJI_Channel, 50, MidSteering*TIMES);   //50Hz
/**************电机初始化***************/
    pwm_init(Motor_Go_L, 13*1000, 300*TIMES*10);   //13kHz
    pwm_init(Motor_Go_R, 13*1000, 300*TIMES*10);
    pwm_init(Motor_Return_L, 13*1000, 0*TIMES*10);
    pwm_init(Motor_Return_R, 13*1000, 0*TIMES*10);
/**************模型电感初始化***************/
    adc_init(ADC_1,AI_ADC1,ADC_8BIT);
    adc_init(ADC_1,AI_ADC2,ADC_8BIT);
    adc_init(ADC_1,AI_ADC3,ADC_8BIT);
    adc_init(ADC_1,AI_ADC4,ADC_8BIT);
    adc_init(ADC_1,AI_ADC5,ADC_8BIT);
    adc_init(ADC_1,AI_ADC6,ADC_8BIT);
    adc_init(ADC_1,AI_ADC7,ADC_8BIT);
/**************蜂鸣器**************/
    gpio_init(BEEP,GPO,1,GPIO_PIN_CONFIG);   //输出
/**************串口转蓝牙初始化**************/
    uart_init (USART_8,115200,UART8_TX,UART8_RX);
/**************OLED初始化**************/
    OLED_Init();
/**************编码器初始化**************/    
    qtimer_quad_init(QTIMER_1,Speed_A1,Speed_B1);
    qtimer_quad_init(QTIMER_1,Speed_A2,Speed_B2);
/**************按键初始化**************/
    gpio_init(K1,GPI,0,GPIO_PIN_CONFIG);
    gpio_init(K2,GPI,0,GPIO_PIN_CONFIG);
    gpio_init(K3,GPI,0,GPIO_PIN_CONFIG);
    gpio_init(K4,GPI,0,GPIO_PIN_CONFIG);
/**************拨码开关初始化**************/
    gpio_init(BM1,GPI,0,GPIO_PIN_CONFIG);
    gpio_init(BM2,GPI,0,GPIO_PIN_CONFIG);
    gpio_init(BM3,GPI,0,GPIO_PIN_CONFIG);
    gpio_init(BM4,GPI,0,GPIO_PIN_CONFIG);
/**************gpio中断上升沿初始化**************/
    gpio_interrupt_init(CarStop,FALLING,GPIO_INT_CONFIG);
    NVIC_SetPriority(GPIO2_Combined_16_31_IRQn,15);
}

/*******************************************************************************
 *  @brief      pitinit函数
 *  @note       定时器通道初始化，暂时初始化通道pit0(10ms)，pit1(10ms)
 *  @date       2020-4-14
 ******************************************************************************/
void pitinit()
{
    pit_init();                     //初始化pit外设
    pit_interrupt_ms(PIT_CH0,10);   //初始化pit通道0 周期10ms
    pit_interrupt_ms(PIT_CH1,10);   //初始化pit通道1 周期10ms
    //pit_interrupt_ms(PIT_CH2,2300);
    NVIC_SetPriority(PIT_IRQn,0);  //设置中断优先级 范围0-15 越小优先级越高 四路PIT共用一个PIT中断函数
}
