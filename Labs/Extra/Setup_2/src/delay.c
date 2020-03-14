/*
 * delay.c
 *
 *  Created on: 22/02/2020
 *      Author: Jonathan Michael Edwards
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "driverlib/sysctl.h"     // system control functions
#include "delay.h"

#define F_CPU         20000000     // 20 MHz Clock
#define ONE_SEC       F_CPU / 3
#define SEC_TO_MILLI  1000
#define SEC_TO_MICRO  1000000


// delay in milli seconds.
// returns the delay in milli seconds
void delayMilli(uint32_t milliSec) 
{
	SysCtlDelay((ONE_SEC / SEC_TO_MILLI) * milliSec);
}


// delay in micro seconds.
// returns the delay in micro seconds
void delayMicro(uint32_t microSec) 
{
	SysCtlDelay((ONE_SEC / SEC_TO_MICRO) * microSec);
}
