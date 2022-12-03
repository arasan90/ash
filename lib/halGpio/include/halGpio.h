/** @file halGpio.h
 * @brief Hardware abstraction layer for GPIO interfaces.
 * @ingroup halGpio
 */

#ifndef HAL_GPIO_H
#define HAL_GPIO_H
/*--------------------Includes--------------------*/
#include <stdint.h>

/*----------------Type definitions----------------*/
typedef enum halGpioMode_e
{
    halGpioMode_INPUT   = 0,
    halGpioMode_OUTPUT  = 1,
}   halGpioMode_t;

typedef struct halGpioConfiguration_s
{
    int gpioNumber;
    halGpioMode_t gpioMode;
    int pullUpEnabled;
    int pullDownEnabled;
}   halGpioConfiguration_t;
/*--------------Function declarations-------------*/

/**
 * @brief Initialize a GPIO
 *
 * @param gpioConfig_p pointer to GPIO configuration
 * @return 1 if initialization was successfull, 0 otherwise
 */
int halGpioInit(halGpioConfiguration_t *gpioConfig_p);

/**
 * @brief Get the GPIO value
 *
 * @param gpio GPIO number
 * @return GPIO value
 */
int halGpioGetValue(int gpio);

/**
 * @brief Set the GPIO value
 *
 * @param gpio GPIO number
 * @param value value to set on the GPIO
 * @return 1 on success, 0 otherwise
 */
int halGpioSetValue(int gpio, int value);

#endif /* HAL_GPIO_H */