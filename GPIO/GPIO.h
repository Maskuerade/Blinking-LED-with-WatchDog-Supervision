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
//
//#define GPIO_INPUT  0x00
//#define GPIO_OUTPUT 0x01
//#define GPIO_AF     0x02
//#define GPIO_ANALOG 0x03
//
//
//#define GPIO_PUSH_PULL  0x00
//#define GPIO_OPEN_DRAIN 0x01
//
// maybe 'C'?
#define CURRENT_PORT GPIO_C

#define LOW    0x00
#define HIGH   0x01
//
//
//#define GPIO_NO_PULL   (0x00 << 1)
//#define GPIO_PULL_UP   (0x01 << 1)
// No pull down in avr atmega32
//

#define PinNum 0
#define PinNum1 1
#define PinNum2 2
#define PinNum3 3
#define PinNum4 4
#define PinNum5 5
#define PinNum6 6


void Gpio_Init();
void Gpio_Write(unsigned char PinId, unsigned char PinData);



#endif /* GPIO_H_ */
