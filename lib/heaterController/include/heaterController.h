/** @file heaterController.h
 * @brief Module managing the heater control
 * @ingroup heaterController
 */

#ifndef HEATERCONTROLLER_H
#define HEATERCONTROLLER_H
/*--------------------Includes--------------------*/
#include <stdint.h>

/*----------------Type definitions----------------*/
/*--------------Function declarations-------------*/

/**
 * @brief Switch the heater ON or OFF
 * @param heatNeeded 1 to switch the heater ON, 0 to switch it off
 * @return 1 on success, 0 otherwise
 */
int heaterControllerSetValue(int heatNeeded);

#endif /* HEATERCONTROLLER_H */