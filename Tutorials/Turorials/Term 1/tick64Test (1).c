//*******************************************************************
//
// tick64Test.c - Test for real-time 64-bit clock - Tiva version
//
// Author:  P.J. Bones	UCECE
// Last modified:	18.3.2018
//*******************************************************************
// Based on pulseInt.c and convertV1.c
//*******************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "utils/ustdlib.h"
#include "stdlib.h"
#include "OrbitOLED/OrbitOLEDInterface.h"

//*******************************************************************
// Maintains a 64-bit real time clock with SysTick interrupts at 100 kHz.
// The background task displays the approximate clock value.
//
//*******************************************************************
// Constants
//*******************************************************************
#define SYSTICK_RATE_HZ 100000ul
#define BITS_TO_TRIM 10
    // Note that 2^(BITS_TO_TRIM) needs to be < SYSTICK_RATE_HZ.

//*******************************************************************
// Global variables
//*******************************************************************
volatile static uint32_t gui32ClockHigh = 0;  // high word ) of 64-bit tick
volatile static uint32_t gui32ClockLow = 0;   // low word  )  count

//*******************************************************************
//
// The interrupt handler for the SysTick interrupt.
//
//*******************************************************************
void
SysTickIntHandler (void)
{
    //
    // Update the 64-bit tick count
    //
    gui32ClockLow++;
    if (gui32ClockLow == 0)
       gui32ClockHigh++;
}

//*******************************************************************
//
// Initialise the processor clock (also the clock for SysTick)
//
//*******************************************************************
void
initClock (void)
{
    // Set the clock rate to 20 MHz
    SysCtlClockSet (SYSCTL_SYSDIV_10 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_16MHZ);
}

//*******************************************************************
//
// Initialise the SysTick interrupts to occur at SYSTICK_RATE_HZ Hz
//
//*******************************************************************
void
initSysTick (void)
{
    //
    // Set up the period for the SysTick timer.  The SysTick timer period is
    // set as a function of the system clock.
    SysTickPeriodSet (SysCtlClockGet () / SYSTICK_RATE_HZ);
    //
    // Register the interrupt handler
    SysTickIntRegister (SysTickIntHandler);
    //
    // Enable interrupt and device
    SysTickIntEnable ();
    SysTickEnable ();
}

//*******************************************************************
//
// Initialise the display
//
//*******************************************************************
void
initDisplay (void)
{
    // intialise the Orbit OLED display
	OLEDInitialise ();
}


//*******************************************************************
//
// Function to display the current time in minutes and seconds
//
//*******************************************************************
void
displayTime (uint32_t ui32Min, uint32_t ui32Sec)
{
    char string[17];  //Display fits 16 characters per line.

    OLEDStringDraw ("tick64Test      ", 0, 0);
    usnprintf (string, sizeof(string), "Minutes: %7d", ui32Min);
    OLEDStringDraw (string, 0, 2);
    usnprintf (string, sizeof(string), "Seconds: %7d", ui32Sec);
    OLEDStringDraw (string, 0, 3);
}


int
main (void)
{
   uint32_t ui32HighTmp, ui32LowTmp;
   uint32_t ui32Num, ui32Denom;  // Used for calculating time
    
   initClock ();
   initSysTick ();
   initDisplay ();
   IntMasterEnable ();

   //
   // Loop forever while the count value is being displayed
   //
   while (1)
   {
      // Critical section: get current 64-bit count
      IntMasterDisable ();
      ui32HighTmp = gui32ClockHigh;
      ui32LowTmp = gui32ClockLow;
      IntMasterEnable ();
      //
      // Convert the 64-bit number into a 32-bit value by discarding LS
      //  bits and combining the remaining bits in the two halves.
      ui32Num = (ui32HighTmp << (32 - BITS_TO_TRIM))
    		  | (ui32LowTmp >> BITS_TO_TRIM);
      ui32Denom = SYSTICK_RATE_HZ >> BITS_TO_TRIM;

      displayTime ((ui32Num / ui32Denom) / 60, (ui32Num / ui32Denom) % 60);
   }
}
