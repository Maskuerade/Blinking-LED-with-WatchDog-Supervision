/*
 * GPIO_private.h
 *
 *  Created on: Jun 18, 2024
 *      Author: Eng Habeba
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_
#include "Std_Types.h"
#include "Utils.h"

 #define GPIOB_BASE_ADDR    (volatile uint8*)0x23
 #define GPIOC_BASE_ADDR    (volatile uint8*)0x26
 #define GPIOD_BASE_ADDR    (volatile uint8*)0x29

typedef struct {
	uint8 GPIO_PINx; // input, read-only
	uint8 GPIO_DDRx; // 1->O/P 0->I/P
	uint8 GPIO_PORTx; // output, write
} GpioType;

#endif /* GPIO_PRIVATE_H_ */
