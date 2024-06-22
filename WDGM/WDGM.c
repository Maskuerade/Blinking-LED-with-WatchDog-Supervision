/*
 * WDGM.c
 *
 *  Created on: Jun 18, 2024
 *      Author: Eng Habeba
 */


#include "WDGM.h"
#include "Std_Types.h"
#include "Gpio.h"
volatile uint8 ledm_call_count;
WDGM_StatusType status;// = NOK;
static unsigned int check_counter;
volatile uint8 wdgm_mainfunction_executed;// = 0;
volatile uint8 is_refreshed;


void WDGM_Init(void) {
	check_counter = 0;
    ledm_call_count = 0;
    status = NOK;
    wdgm_mainfunction_executed = 0;
    is_refreshed = 1;

}




void WDGM_MainFunction(void) {
//	static unsigned int check_counter = 0;
	//Gpio_Write(2, 1);

    check_counter += 20; // Called every 20ms
    wdgm_mainfunction_executed += 1;
    if (check_counter >= 100) { // 100ms period

    	check_counter = 0;
        if (ledm_call_count >= 8 && ledm_call_count <= 12) {
            status = OK;
        } else {
            status = NOK;
        }
        // set the wdgm_mainfunction_executed with 1 bec it is not stuck
        ledm_call_count = 0;


    }



}




WDGM_StatusType WDGM_PovideSuppervisionStatus(void) {
	return status;
}

void WDGM_AlivenessIndication(void) {
    ledm_call_count++;
}
