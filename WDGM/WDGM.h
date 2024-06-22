/*
 * WDGM.h
 *
 *  Created on: Jun 18, 2024
 *      Author: Eng Habeba
 */

#ifndef WDGM_H_
#define WDGM_H_
#include "Std_Types.h"
extern volatile uint8 wdgm_mainfunction_executed;
extern volatile uint8 is_refreshed;
extern volatile uint8 ledm_call_count;
typedef enum {OK = 0, NOK = 1}WDGM_StatusType;
extern WDGM_StatusType status ;
void WDGM_Init(void);
void WDGM_MainFunction(void);
WDGM_StatusType WDGM_PovideSuppervisionStatus(void);
void  WDGM_AlivenessIndication(void);


#endif /* WDGM_H_ */
