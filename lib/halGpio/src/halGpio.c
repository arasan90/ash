/** @file halGpio.c
 * @brief Hardware abstraction layer for GPIO interfaces.
 * @ingroup halGpio
 */

/*--------------------Includes--------------------*/
#include "halGpio.h"
#include "driver/gpio.h"

/*----------------Type definitions----------------*/
/*--------------------Constants-------------------*/
/*--------------------Variables-------------------*/
/*----------Static function declarations----------*/
/*--------------Function definitions--------------*/
int halGpioInit(halGpioConfiguration_t *gpioConfig_p)
{
    int retValue = 0;
    if (gpioConfig_p)
    {
        gpio_config_t io_conf = {0};
        io_conf.intr_type = GPIO_INTR_DISABLE;
        io_conf.mode = (halGpioMode_INPUT == gpioConfig_p->gpioMode) ? GPIO_MODE_INPUT : GPIO_MODE_OUTPUT;
        io_conf.pin_bit_mask = 1ULL << gpioConfig_p->gpioNumber;
        io_conf.pull_down_en = gpioConfig_p->pullDownEnabled;
        io_conf.pull_up_en = gpioConfig_p->pullUpEnabled;
        if (ESP_OK == gpio_config(&io_conf))
            retValue = 1;
    }
    return retValue;
}

int halGpioGetValue(int gpio)
{
    return gpio_get_level(gpio);
}

int halGpioSetValue(int gpio, int value)
{
    return (ESP_OK == gpio_set_level(gpio, value));
}
/*-----------Static function definitions----------*/
