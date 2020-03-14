/*
 * DutyCycleBlinky.c
 *
 *  Created on: 22/02/2020
 *      Author: Jonathan Michael Edwards
 */


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// TivaWare Library Includes:
#include "inc/hw_memmap.h"        // defines GPIO_PORTF_BASE
#include "inc/tm4c123gh6pm.h"     // defines interrupt vectors
                                  //   and register addresses
#include "driverlib/gpio.h"       // defines for GPIO peripheral
#include "driverlib/sysctl.h"     // system control functions

#include "delay.h"

// LED's
#define RED_LED   GPIO_PIN_1
#define BLUE_LED  GPIO_PIN_2
#define GREEN_LED GPIO_PIN_3

// BUTTONS
#define SW_1  GPIO_PIN_4
#define SW_2  GPIO_PIN_0



void initTivo(void)
{
    uint8_t i = 0;

    // Set and get the 20 MHz clock
    SysCtlClockSet(SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_SYSDIV_10);
    SysCtlDelay(100);              // Settle oscillator

    // Enable Peripherals
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Set GPIO Port Pins
    for (i=RED_LED; i <= GREEN_LED; i*=2)
        GPIOPadConfigSet(GPIO_PORTF_BASE, i, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPD);
    GPIOPadConfigSet(GPIO_PORTF_BASE, SW_1, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPU);

    // Set GPIO data direction register (DDRx)
    for (i=RED_LED; i <= GREEN_LED; i*=2) 
        GPIODirModeSet(GPIO_PORTF_BASE, i, GPIO_DIR_MODE_OUT);
    GPIODirModeSet(GPIO_PORTF_BASE, SW_1, GPIO_DIR_MODE_IN);

    // Initially write to GPIO Port
    for (i=RED_LED; i <= GREEN_LED; i*=2)
       GPIOPinWrite(GPIO_PORTF_BASE, i, 0x00);
}


int main(void)
{
    initTivo();

    while (1) {
        //  Change Led color every 750 ms
         uint32_t i;
         for (i=RED_LED; i <= GREEN_LED; i*=2) {
             GPIOPinWrite(GPIO_PORTF_BASE, i, i);
             delayMilli(750);
             GPIOPinWrite(GPIO_PORTF_BASE, i, 0x00);
         }
    }
}
