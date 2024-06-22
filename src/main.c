/*
 * main.c
 *
 *  Created on: Jun 18, 2024
 *      Author: Eng Habeba
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include "Bit_Operations.h"
#include "Gpio.h"
#include "Std_Types.h"
#include "LED.h"
#include "WDGDRV.h"
#include "WDGM.h"
#include "Timer.h"
#include <util/delay.h>


int main() {

	Gpio_Init();
	LED_Init();
	WDGDrv_Init();
	WDGM_Init();
	Timer_Init();



	unsigned int wdgm_counter = 0;


	while (1) {
		_delay_ms(10);
		LED_Manage();


		wdgm_counter += 10;
		if (wdgm_counter >= 20) {
			wdgm_counter = 0;
			WDGM_MainFunction();
		}
	}

	return 0;

}
