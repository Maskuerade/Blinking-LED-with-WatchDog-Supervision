/*
 * LED.c
 *
 *  Created on: Jun 18, 2024
 *      Author: Eng Habeba
 */
#include "LED.h"
#include "Gpio.h"
#include "WDGM.h"

static uint32 led_state = 0;
static uint32 counter = 0;
void LED_Init() {
	led_state = 0;
}

void LED_Manage(void) {

    //Gpio_Write(1, 1);
    counter += 10;
    if (counter >= 500) {
        led_state = !led_state;
        Gpio_Write(PinNum, led_state);
        counter = 0;
    }

//    WDGM_AlivenessIndication();
}



