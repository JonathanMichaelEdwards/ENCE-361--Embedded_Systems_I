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
    uint8_t color = 0;

    // Set and get the 20 MHz clock
    SysCtlClockSet(SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_SYSDIV_10);
    SysCtlDelay(100);              // Settle oscillator

    // Enable Peripherals
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Set GPIO Port Pins
    for (color=RED_LED; color <= GREEN_LED; color*=2)
        GPIOPadConfigSet(GPIO_PORTF_BASE, color, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPD);
    GPIOPadConfigSet(GPIO_PORTF_BASE, SW_1, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPU);

    // Set GPIO data direction register (DDRx)
    for (color=RED_LED; color <= GREEN_LED; color*=2) 
        GPIODirModeSet(GPIO_PORTF_BASE, color, GPIO_DIR_MODE_OUT);
    GPIODirModeSet(GPIO_PORTF_BASE, SW_1, GPIO_DIR_MODE_IN);

    // Initially write to GPIO Port
    for (color=RED_LED; color <= GREEN_LED; color*=2)
       GPIOPinWrite(GPIO_PORTF_BASE, color, 0x00);
}


void dutyCycle_20() 
{
    // 20% Duty Cycle (more in lab notes)
    GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, GREEN_LED);
    delayMilli(1);  //time on
    GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0x00);
    delayMilli(4);  // time off
}


int main(void)
{
    initTivo();

    while (1) {
        // dutyCycle_20();

        uint32_t i, color;
        for (color=RED_LED; color <= GREEN_LED; color*=2) {
            for (i=1; i <= 20; i++) {
                GPIOPinWrite(GPIO_PORTF_BASE, color, color);
                delayMilli(i);     //time on
                GPIOPinWrite(GPIO_PORTF_BASE, color, 0x00);
                delayMilli(21-i);  // time off  
            }

            for (i=20; 1 <= i; i--) {
                GPIOPinWrite(GPIO_PORTF_BASE, color, color);
                delayMilli(i);     //time on
                GPIOPinWrite(GPIO_PORTF_BASE, color, 0x00);
                delayMilli(21-i);  // time off
            }
        }
    }
}
