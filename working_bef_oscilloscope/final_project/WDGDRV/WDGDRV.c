/*
 * WDGDRV.c
 *
 *  Created on: Jun 18, 2024
 *      Author: Eng Habeba
 */


#include "WDGDRV.h"
#include "WDGM.h"
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include "Bit_Operations.h"
#include "Std_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include "Gpio.h"

#define SREG_I 7
#define WDCE        4  // Watchdog Change Enable
#define WDE         3  // Watchdog Enable
#define WDP1        1  // Watchdog Timer Prescaler 1

#define WDTCSR  (*(volatile uint8 *)(0x60)) // Watchdog Timer Control Register#define WDCE        4  // Watchdog Change Enable
#define MCUSR   (*(volatile uint8 *)(0x54)) // MCU Status Register

volatile uint16 timer_counter = 0;
volatile uint8 reset_occured;// = 0;


static inline void disable_interrupt() {
    SREG &= ~(1 << SREG_I);
}

// Enable global interrupts
static inline void enable_interrupt() {
    SREG |= (1 << SREG_I);
}


void WDGDrv_Init(void)
{
	disable_interrupt();
	MCUSR &= ~(1<<WDRF);
	wdt_reset();
	WDTCSR |= (1<<WDCE) | (1<<WDE);
	/* Set new prescaler(time-out) value = 64ms*/
	WDTCSR = (1<<WDE) | (1<<WDP1);
	enable_interrupt();
}


void WDGDrv_IsrNotification(void) {
	timer_counter += 50;
	    if (timer_counter % 100 != 0 ) {
	        // After 50ms, check if WDGM_MainFunction has been executed
	        //wdgm_mainfunction_executed = true => not stuck

	    	if (wdgm_mainfunction_executed == 2 && ledm_call_count == 5) {
	    		//refresh because the main function is not stuck
	    		wdt_reset();
	        }
	    }
	    if (timer_counter % 100 == 0) {
	        // After 100ms, check the two conditions
	        if (wdgm_mainfunction_executed >= 4 && (WDGM_PovideSuppervisionStatus() == OK)) {
	            wdt_reset(); // Refresh the watchdog timer
	        }
	        // Reset flags and counter for the next period
	        wdgm_mainfunction_executed = 0;
	        status = NOK;
	        timer_counter = 0;
	    }
}
