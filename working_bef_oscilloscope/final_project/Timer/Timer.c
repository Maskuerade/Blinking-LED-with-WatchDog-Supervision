/*
 * Timer.c
 *
 *  Created on: Jun 20, 2024
 *      Author: Eng Habeba
 */

#include "Timer.h"
#include "Std_Types.h"
#include "WDGDRV.h"
//To use ISR only
#include <avr/interrupt.h>

// Define register addresses and bit positions manually
// Control Regs ex: mode of operation and clock (pre-scalar)
// initially zeroes by default
#define TCCR1A  (*(volatile uint8 *)(0x80))
#define TCCR1B  (*(volatile uint8 *)(0x81))

// holds the value to be compared with that in TCNT1 (count value to stop at)
//for channel A (OCF1A flag)
#define OCR1A  (*(volatile uint16 *)(0x88))
#define TIMSK1  (*(volatile uint8 *)(0x6F))
#define TCNT1L  (*(volatile uint8 *)(0x84))
#define TCNT1H  (*(volatile uint8 *)(0x85))

//Pre-scalar bits
#define CS12    2
#define CS11    1
#define CS10    0
#define WGM12   3
#define OCIE1A  1


void Timer_Init(void) {
    // Initialize counter to zero
    TCNT1L = 0;
    TCNT1H = 0;

    // Set Timer1 to CTC mode
    TCCR1B |= (1 << WGM12);

    // Set OCR1A to 49 for 50ms interval with 1024 prescaler
    OCR1A = 49;

    // Enable compare interrupt
    TIMSK1 |= (1 << OCIE1A);

    // Start timer with 1024 prescaler
    TCCR1B |= (1 << CS12) | (1 << CS10);
}



//void Timer_Init(void) {
//    // Initialize counter to zero
//    TCNT1L = 0;
//    TCNT1H = 0;
//
//    // Set Timer1 to CTC mode
//    TCCR1B |= (1 << WGM12);
//
//    // Set OCR1A to 780 for 50ms interval with 1024 prescaler
//    OCR1A = 390;
//
//    // Enable compare interrupt
//    TIMSK1 |= (1 << OCIE1A);
//
//    // Start timer with 1024 prescaler
//    TCCR1B |= (1 << CS12) | (1 << CS10);
//}

ISR(TIMER1_COMPA_vect) {
    WDGDrv_IsrNotification();
}
