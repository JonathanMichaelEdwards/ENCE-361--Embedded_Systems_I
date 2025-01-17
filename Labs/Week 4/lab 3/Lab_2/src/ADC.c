//*****************************************************************************
//
// ADCdemo1.c - Simple interrupt driven program which samples with AIN0
//
// Author:  P.J. Bones  UCECE
// Last modified:   8.2.2018
//    written by them, modified by Jonathan
//
//*****************************************************************************
// Based on the 'convert' series from 2016
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/adc.h"
#include "driverlib/pwm.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "driverlib/debug.h"
#include "utils/ustdlib.h"
#include "circBufT.h"
#include "driverlib/uart.h"

#include "ADC.h"



//*****************************************************************************
// Constants
//*****************************************************************************
//#define BUF_SIZE 10
//#define SAMPLE_RATE_HZ 10
//#define MAX_STR_LEN 16

//*****************************************************************************
// Global variables
//*****************************************************************************
//char statusStr[MAX_STR_LEN + 1];
//static circBuf_t intBuffer;        // Buffer of size BUF_SIZE integers (sample values)
//static uint32_t adcSampleCount;    // Counter for the interrupts



// written by them, modified by Jonathan
//*****************************************************************************
// The interrupt handler for the for SysTick interrupt.
//*****************************************************************************
static void SysTickIntHandler(void)
{
    // Initiate a conversion
    ADCProcessorTrigger(ADC0_BASE, 3);
    adcSampleCount++;
}

//void  // for uartDemo.c  need to create another seperate handler
//SysTickIntHandler (void)
//{
//    static uint8_t tickCount = 0;
//    const uint8_t ticksPerSlow = SYSTICK_RATE_HZ / SLOWTICK_RATE_HZ;
//
//    updateButtons ();       // Poll the buttons
//    if (++tickCount >= ticksPerSlow)
//    {                       // Signal a slow tick
//        tickCount = 0;
//        slowTick = true;
//    }
//
//}


//*****************************************************************************
//
// The handler for the ADC conversion complete interrupt.
// Writes to the circular buffer.
//
//*****************************************************************************
void ADCIntHandler(void)
{
    uint32_t ulValue;


    // Get the single sample from ADC0.  ADC_BASE is defined in
    // inc/hw_memmap.h
    ADCSequenceDataGet(ADC0_BASE, 3, &ulValue);

    // Place it in the circular buffer (advancing write index)
    writeCircBuf(&intBuffer, ulValue);

    // Clean up, clearing the interrupt
    ADCIntClear(ADC0_BASE, 3);
}


//*****************************************************************************
// Initialisation functions for the clock (incl. SysTick), ADC, display
//*****************************************************************************
void initIntHandler(void)
{
    // Set up the period for the SysTick timer.  The SysTick timer period is
    // set as a function of the system clock.
    SysTickPeriodSet(SysCtlClockGet() / SAMPLE_RATE_HZ);
//    SysTickPeriodSet (SysCtlClockGet () / SYSTICK_RATE_HZ);  // uartDemo.c

    // Register the interrupt handler
    SysTickIntRegister(SysTickIntHandler);

    // Enable interrupt and device
    SysTickIntEnable();
    SysTickEnable();
}


void initADC(uint32_t channel)
{
    // Setup ADC0 configuration.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

    // Enable sample sequence 3 with a processor signal trigger.  Sequence 3
    // will do a single sample when the processor sends a signal to start the conversion
    ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);

    // Configure step 0 on sequence 3.  Sample channel 0 (ADC_CTL_CH0) in
    // single-ended mode (default) and configure the interrupt flag
    // (ADC_CTL_IE) to be set when the sample is done.  Tell the ADC logic
    // that this is the last conversion on sequence 3 (ADC_CTL_END).  Sequence
    // 3 has only one programmable step.  Sequence 1 and 2 have 4 steps, and
    // sequence 0 has 8 programmable steps.  Since we are only doing a single
    // conversion using sequence 3 we will only configure step 0.  For more
    // on the ADC sequences and steps, refer to the LM3S1968 datasheet.
    ADCSequenceStepConfigure(ADC0_BASE, 3, 0, channel | ADC_CTL_IE |
                             ADC_CTL_END);
//    default = ADC_CTL_CH0
//    ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH9 | ADC_CTL_IE |
//                                 ADC_CTL_END);  // read the datasheet pg 802 to change to analog pin
//         analogue pins

    // Enable sample sequence
    ADCSequenceEnable(ADC0_BASE, 3);

    // Register the interrupt handler
    ADCIntRegister (ADC0_BASE, 3, ADCIntHandler);

    // Enable interrupts for ADC0 sequence 3 (clears any outstanding interrupts)
    ADCIntEnable(ADC0_BASE, 3);
}


// Enable interrupts to the processor.
void intEnable(void)
{
    IntMasterEnable();
}
