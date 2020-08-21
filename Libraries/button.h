#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "delay.h"
#include "stdlib.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"
uint8_t dectobcd(int x);
void Config_Led();
void Pin_interrup();
void Config_Pin_Input();
#endif