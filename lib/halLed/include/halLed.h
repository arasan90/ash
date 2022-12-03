/** @file halLed.h
 * @brief Hardware abstraction layer for LED interfa.
 * @ingroup halLed
 */

#ifndef HAL_LED_H
#define HAL_LED_H
/*--------------------Includes--------------------*/
#include <stdint.h>

/*----------------Type definitions----------------*/
/*--------------Function declarations-------------*/

/**
 * @brief Initialize LED GPIO
 *
 * @param ledGpio GPIO number for LED
 * @return 1 if initialization is successfull, 0 otherwise
 */
int halLedInitialize(int ledGpio);

/**
 * @brief Set the LED status
 *
 * @param value LED status to set: 1 for LED ON, 0 for LED OFF
 */
void halLedSetValue(int value);

/**
 * @brief Toggle the LED status
 *
 * @return latest LED status. 1 for LED ON, 0 for LED OFF
 */
int halLedToggleValue(void);

#endif /* HAL_LED_H */