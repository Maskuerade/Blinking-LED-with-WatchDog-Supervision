/*
 * GPIO.h
 *
 *  Created on: Jun 18, 2024
 *      Author: Eng Habeba
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "Std_Types.h"
#include "Bit_Operations.h"

#define GPIO_B 'B'
#define GPIO_C 'C'
#define GPIO_D 'D'

#define CURRENT_PORT GPIO_C

#define LOW    0x00
#define HIGH   0x01

#define PinNum 0
#define RESET_LED_PIN 1
//#define PinNum2 2
#define PinNum3 3
//#define PinNum4 4
//#define PinNum5 5
//#define PinNum6 6


void Gpio_Init();
void Gpio_Write(unsigned char PinId, unsigned char PinData);



#endif /* GPIO_H_ */
