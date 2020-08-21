#include "main.h"
#include "string.h"
#include "stdio.h"

u8 x=0, y=0, z=0;
void main()
{
  
   Config_Pin_Input();
   while(1){
      x=   GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5);
      y =  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6);
      z =  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7);
   }
}
