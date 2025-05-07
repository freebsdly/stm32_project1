#ifndef __BUTTON_H
#define __BUTTON_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx_hal.h"

#define KEY0_Pin GPIO_PIN_3
#define KEY0_GPIO_Port GPIOH

#define KEY1_Pin GPIO_PIN_2
#define KEY1_GPIO_Port GPIOH

#define KEY2_Pin GPIO_PIN_13
#define KEY2_GPIO_Port GPIOC

#define KEYUP_Pin GPIO_PIN_0
#define KEYUP_GPIO_Port GPIOA

#define KEY0 HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin)
#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)
#define KEY2 HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)
#define KEYUP HAL_GPIO_ReadPin(KEYUP_GPIO_Port, KEYUP_Pin)

#ifdef __cplusplus
}
#endif

#endif