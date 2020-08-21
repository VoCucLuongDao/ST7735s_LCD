#include "button.h"
#include "main.h"
extern uint8_t status_new, status_current;
extern uint8_t mode, settime;
void Config_Led()
{
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);
  
  GPIO_InitTypeDef GPIO_Initstructure;
  GPIO_Initstructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_Initstructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Initstructure.GPIO_Speed = GPIO_Speed_25MHz;
  GPIO_Initstructure.GPIO_OType = GPIO_OType_PP;
  GPIO_Initstructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOE,&GPIO_Initstructure);
  GPIO_SetBits(GPIOE,GPIO_Pin_0);
}

void Config_Pin_Input()
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;
    GPIO_InitStruct.GPIO_Speed=GPIO_Speed_2MHz;
    GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_DOWN;
    GPIO_Init(GPIOB,&GPIO_InitStruct);
}

void Pin_interrup(){
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
    GPIO_InitStruct.GPIO_Speed=GPIO_Speed_2MHz;
    GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_UP;
    GPIO_Init(GPIOD,&GPIO_InitStruct);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource1);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource2);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource3);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource4);
    
    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_InitStruct.EXTI_Line = EXTI_Line1;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_Init(&EXTI_InitStruct);
    
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = EXTI1_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStruct);

    EXTI_InitStruct.EXTI_Line = EXTI_Line2;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_Init(&EXTI_InitStruct);
    
    NVIC_InitStruct.NVIC_IRQChannel = EXTI2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 10;
    NVIC_Init(&NVIC_InitStruct);
  
    EXTI_InitStruct.EXTI_Line = EXTI_Line3;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_Init(&EXTI_InitStruct);
    
    NVIC_InitStruct.NVIC_IRQChannel = EXTI3_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 10;
    NVIC_Init(&NVIC_InitStruct);
    
    EXTI_InitStruct.EXTI_Line = EXTI_Line4;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_Init(&EXTI_InitStruct);
    
    NVIC_InitStruct.NVIC_IRQChannel = EXTI4_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 10;
    NVIC_Init(&NVIC_InitStruct);
}
