/** @file halLed.c
 * @brief Hardware abstraction layer for GPIO interfaces.
 * @ingroup halLed
 */

/*--------------------Includes--------------------*/
#include "halLed.h"
#include "driver/gpio.h"

/*----------------Type definitions----------------*/
/*--------------------Constants-------------------*/
int halLedGpio = 0; //!< LED GPIO number

/*--------------------Variables-------------------*/
/*----------Static function declarations----------*/
/*--------------Function definitions--------------*/
int halLedInitialize(int ledGpio)
{
    int retCode = 0;
    halLedGpio = ledGpio;
    if (ESP_OK == gpio_set_direction(ledGpio, GPIO_MODE_OUTPUT))
        retCode = 1;
    return retCode;
}

void halLedSetValue(int value)
{
    if (halLedGpio)
    {
        if (value < 2 && value > -1)
            gpio_set_level(halLedGpio, value);
    }
}

int halLedToggleValue(void)
{
    int currentLedStatus = gpio_get_level(halLedGpio);
    gpio_set_level(halLedGpio, !currentLedStatus);
    return !currentLedStatus;
}

/*-----------Static function definitions----------*/
