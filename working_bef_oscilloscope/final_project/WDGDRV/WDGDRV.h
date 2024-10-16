/*
 * WDGDRV.h
 *
 *  Created on: Jun 18, 2024
 *      Author: Eng Habeba
 */

#ifndef WDGDRV_H_
#define WDGDRV_H_
#include "Std_Types.h"
extern volatile uint8 reset_occured;


void WDGDrv_Init(void);
void WDGDrv_IsrNotification(void);

#endif /* WDGDRV_H_ */
