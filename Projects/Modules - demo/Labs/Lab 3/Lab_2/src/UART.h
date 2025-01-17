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


#ifndef UART_H
#define UART_H


// Constants
#define SYSTICK_RATE_HZ 100
#define SLOWTICK_RATE_HZ 4
#define MAX_STR_LEN 16

// Global variables
char statusStr[MAX_STR_LEN + 1];
uint8_t slowTick;


//SysTickIntHandler_UART(void);   /// this function is exactly the same but modified in ADC, need to create own handler...
void initIntHandler(void);        // this function is exactly the same but modified in ADC, combine them...
void initUSB_UART (void);
void UARTSend (char *pucBuffer);


#endif // UART_H
