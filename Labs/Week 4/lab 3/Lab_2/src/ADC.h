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


#ifndef ADC_H
#define ADC_H



// Constants
#define BUF_SIZE 10
#define SAMPLE_RATE_HZ 10
#define MAX_STR_LEN 16

// for uartDemo.c
//#define SYSTICK_RATE_HZ 100
//#define SLOWTICK_RATE_HZ 4
//#define MAX_STR_LEN 16

// Global variables
char statusStr[MAX_STR_LEN + 1];
circBuf_t intBuffer;        // Buffer of size BUF_SIZE integers (sample values)
uint32_t adcSampleCount;    // Counter for the interrupts


void initIntHandler(void);
void initADC(uint32_t channel);
void ADCIntHandler(void);

void intEnable(void);


#endif // ADC_H
