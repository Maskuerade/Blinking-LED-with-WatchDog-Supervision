/*
 * GPIO.c
 *
 *  Created on: Jun 18, 2024
 *      Author: Eng Habeba
 */

#include <avr/io.h>
#include "GPIO.h"
#include "GPIO.h"
#include "GPIO_Private.h"
#include "Bit_Operations.h"

uint32 GPIO_Addresses[3] = { GPIOB_BASE_ADDR, GPIOC_BASE_ADDR, GPIOD_BASE_ADDR };

#define GPIO_REG(REG_ID, PORT_ID) ((uint32*)((PORT_ID) + (REG_ID)))

void Gpio_Init() {
	//	uint8 PortId = 0;

	GpioType * gpioReg =  GPIO_Addresses[CURRENT_PORT - 'B'];

	// configure the pins as output
	//IF OTHER PINS NOT USED ----  MAY BE SET ALL OUTPUT
	gpioReg->GPIO_DDRx |= (0x01<<PinNum);
	gpioReg->GPIO_DDRx |= (0x01<<RESET_LED_PIN);
//	gpioReg->GPIO_DDRx |= (0x01<<PinNum2);
	gpioReg->GPIO_DDRx |= (0x01<<PinNum3);
//	gpioReg->GPIO_DDRx |= (0x01<<PinNum4);
//	gpioReg->GPIO_DDRx |= (0x01<<PinNum5);
//	gpioReg->GPIO_DDRx |= (0x01<<PinNum6);


}

void Gpio_Write(unsigned char PinId, unsigned char PinData) {

//	uint8 PortId = 0;

	GpioType * gpioReg =  GPIO_Addresses[CURRENT_PORT - 'B'];

	//check DDxn = 1 meaning this is an output pin
	//READ_BIT(X, BIT) => (((X) >> (BIT)) & 1)
	if (READ_BIT(gpioReg->GPIO_DDRx, PinId) && (PinData < 2)){
		gpioReg->GPIO_PORTx &= ~(0x01<<PinId);
		gpioReg->GPIO_PORTx |= (PinData << PinId);
	}

}


//#include "GPIO.h"
//
//#include "Gpio_Private.h"
//
//uint32 GPIO_Addresses[2] = { GPIOA_BASE_ADDR, GPIOB_BASE_ADDR };
//
//#define GPIO_REG(REG_ID, PORT_ID) ((uint32*)((PORT_ID) + (REG_ID)))
//
//void Gpio_Init() {
//	uint8 PortId = 0;
//	GpioType * gpioReg =  GPIO_Addresses[PortId];
//
//
//	gpioReg->GPIO_MODER &= ~(0x3 << (2 * PinNum));
//	gpioReg->GPIO_MODER |= (1 << (2 * PinNum));
//
//	gpioReg->GPIO_OTYPER  &= ~(0x01 << PinNum);
//	gpioReg->GPIO_OTYPER |= (1 << PinNum);
//
//	gpioReg->GPIO_PUPDR &= ~(0x3 << (2 * PinNum));
//
//}
//
//void Gpio_Write(unsigned char PinId, unsigned char PinData) {
//	uint8 PortId = 0;
//	GpioType * gpioReg =  GPIO_Addresses[PortId];
//	gpioReg->GPIO_ODR &= ~(0x01 << PinId);
//	gpioReg->GPIO_ODR |= (PinData << PinId);
//}
//
//
