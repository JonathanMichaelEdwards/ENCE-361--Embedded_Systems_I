// ************************************************************
// week2_blink
// Sample code for Week 2 ENCE361 Lab
// Author:  Phil Bones
// Last edited:   3.2.2018
// Based on Texas example code, and additions by Steve Weddell
//
// Purpose: This program will cause the LED connected to Pin 3
// of Port F to blink.
// ************************************************************
//

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// TivaWare Library Includes:

#include "delay.h"
#include "Peripherals.h"



//void initPeripherals()
//{
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
//}
//
//
//void initLED()
//{
//    // Set GPIO Port Pins
//    GPIOPadConfigSet(GPIO_PORTF_BASE, GREEN_LED, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPD);
//
//    // Set GPIO data direction register (DDRx)
//    GPIODirModeSet(GPIO_PORTF_BASE, GREEN_LED, GPIO_DIR_MODE_OUT);
//
//    // Initially write to GPIO Port
//    GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0x00);
//}
//
//
//void initButton()
//{
//    // Set GPIO Port Pins
//    GPIOPadConfigSet(GPIO_PORTF_BASE, SW_1, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPU);
//
//    // Set GPIO data direction register (DDRx)
//    GPIODirModeSet(GPIO_PORTF_BASE, SW_1, GPIO_DIR_MODE_IN);
//}



void init(uint32_t *clkRate)
{
    // Set and get the 20 MHz clock
    SysCtlClockSet(SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_SYSDIV_10);
    SysCtlDelay(100);              // Settle oscillator
//    *clkRate = SysCtlClockGet();


    initPeripherals();
    initLED(GPIO_PORTF_BASE, GREEN_LED);
    initSwitch(GPIO_PORTF_BASE, SW_1);
    
    // Enable Peripherals
    // SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Set GPIO Port Pins
    // GPIOPadConfigSet(GPIO_PORTF_BASE, GREEN_LED, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPD);
    // GPIOPadConfigSet(GPIO_PORTF_BASE, SW_1, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPU);

    // // Set GPIO data direction register (DDRx)
    // GPIODirModeSet(GPIO_PORTF_BASE, GREEN_LED, GPIO_DIR_MODE_OUT);
    // GPIODirModeSet(GPIO_PORTF_BASE, SW_1, GPIO_DIR_MODE_IN);

    // Initially write to GPIO Port
    // GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0x00);
}


int main(void) 
{
    uint32_t clkRate = 0;
    init(&clkRate);
  
    while (1) {
        // SW_1 pin is 0 when push with a pull up resistor
        if (pinRead(PORT_F, SW_1) == LOW)
            pinWrite(PORT_F, GREEN_LED, GREEN_LED);
        else
            pinWrite(PORT_F, GREEN_LED, LOW);
    }
}
