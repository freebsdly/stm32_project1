#ifndef __LED_H
#define __LED_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx_hal.h"

#define LED1_Pin GPIO_PIN_0
#define LED1_GPIO_Port GPIOB

#define LED0_Pin GPIO_PIN_1
#define LED0_GPIO_Port GPIOB

/* LED 端口操作定义 */
#define LED0(x)                                                                                                                  \
  do                                                                                                                             \
  {                                                                                                                              \
    x ? HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET); \
  } while (0)

#define LED1(x)                                                                                                                  \
  do                                                                                                                             \
  {                                                                                                                              \
    x ? HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET); \
  } while (0) /* LED1 翻转 */

/* LED 电平翻转定义 */
#define LED0_TOGGLE()                             \
  do                                              \
  {                                               \
    HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin); \
  } while (0) /* LED0 = !LED0 */

#define LED1_TOGGLE()                             \
  do                                              \
  {                                               \
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin); \
  } while (0) /* LED1 = !LED1 */

  /* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif