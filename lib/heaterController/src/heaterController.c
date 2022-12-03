/** @file heaterController.c
 * @brief Module managing the heater control
 * @ingroup heaterController
 */

/*--------------------Includes--------------------*/
#include "heaterController.h"
#include "halGpio.h"

/*----------------Type definitions----------------*/
/*--------------------Constants-------------------*/
/*--------------------Variables-------------------*/
/*----------Static function declarations----------*/
/*--------------Function definitions--------------*/
int heaterControllerSetValue(int heatNeeded)
{
    return (1 == halGpioSetValue(14, heatNeeded));
}

/*-----------Static function definitions----------*/