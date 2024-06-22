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


#define WDCE        4  // Watchdog Change Enable
#define WDE         3  // Watchdog Enable
#define WDP1        1  // Watchdog Timer Prescaler 1
volatile uint16 timer_counter = 0;


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


//void WDGDrv_Init(void)
//{
//	disable_interrupt();
//
//	// This bit is set if a watchdog system reset occurs.
//	//The bit is reset by writing a logic zero to the flag.
//	MCUSR &= ~(1<<WDRF);
//	wdt_reset();
//	MCUSR |= (1<<WDRF);
//	WDTCSR &= ~(1<<WDCE);
//	WDTCSR |= (1<<WDCE);
//	WDTCSR &= ~(1<<WDE);
//	WDTCSR |= (1<<WDE);
//
//	/* Set new prescaler(time-out) value = 64ms*/
//	// set WDP1 to 1 and WDP0 to 0 so that we get 64ms
//	WDTCSR |= (1<<WDE);
//	WDTCSR |= (1<<WDP1);
//	WDTCSR &= ~(1 << WDP0);
//
//	enable_interrupt();
//}




void WDGDrv_IsrNotification(void) {
	timer_counter += 50;

	    if (timer_counter % 100 != 0 ) {
	        // After 50ms, check if WDGM_MainFunction has been executed
	        //wdgm_mainfunction_executed = true => not stuck
	    	if (!wdgm_mainfunction_executed) {
	    		//refresh because the main function is not stuck
	    		wdt_reset();
	        }
	        else{
	        	//if main function is stuck
	        	wdgm_mainfunction_executed = 0;
				status = NOK;
	        }
	    } else if (timer_counter % 100 == 0) {
	        // After 100ms, check the two conditions
	        if (wdgm_mainfunction_executed && (WDGM_PovideSuppervisionStatus() == OK)) {
	            wdt_reset(); // Refresh the watchdog timer
	        }
	        // Reset flags and counter for the next period
	        wdgm_mainfunction_executed = 0;
	        status = NOK;
	        timer_counter = 0;
	    }

}
