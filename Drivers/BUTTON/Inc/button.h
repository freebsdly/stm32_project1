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

#define KEY_UP_STATE 1
#define KEY_DOWN_STATE 0
#define WKUP_UP_STATE 0
#define WKUP_DOWN_STATE 1

#define KEY0_DOWN 1
#define KEY1_DOWN 2
#define KEY2_DOWN 3
#define KEYUP_DOWN 4

    /** 按键扫描 */
    uint8_t key_scan(uint8_t mode)
    {
        /** 按键松开标志 */
        static uint8_t key_up = 1;
        uint8_t keyval = 0;
        if (mode)
            key_up = 1;

        /* 支持连按 */
        if ((key_up) && (KEY0 == KEY_DOWN_STATE || KEY1 == KEY_DOWN_STATE || KEY2 == KEY_DOWN_STATE || KEYUP == WKUP_DOWN_STATE))
        {
            /** 去抖动 */
            HAL_Delay(10);
            key_up = 0;

            if (KEY0 == KEY_DOWN_STATE)
                keyval = KEY0_DOWN;
            if (KEY1 == KEY_DOWN_STATE)
                keyval = KEY1_DOWN;
            if (KEY2 == KEY_DOWN_STATE)
                keyval = KEY2_DOWN;
            if (KEYUP == WKUP_DOWN_STATE)
                keyval = KEYUP_DOWN;
        }
        else if (KEY0 == KEY_UP_STATE && KEY1 == KEY_UP_STATE && KEY2 == KEY_UP_STATE && KEYUP == WKUP_UP_STATE)
        {
            key_up = 1;
        }

        return keyval;
    }

#ifdef __cplusplus
}
#endif

#endif