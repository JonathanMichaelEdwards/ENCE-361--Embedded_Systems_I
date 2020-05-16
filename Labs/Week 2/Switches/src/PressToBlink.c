// // ************************************************************
// // week2_blink
// // Sample code for Week 2 ENCE361 Lab
// // Author:  Phil Bones
// // Last edited:   3.2.2018
// // Based on Texas example code, and additions by Steve Weddell
// //
// // Purpose: This program will cause the LED connected to Pin 3
// // of Port F to blink.
// // ************************************************************
// //

// #include <stdio.h>
// #include <stdint.h>
// #include <stdbool.h>

// // TivaWare Library Includes:
// #include "inc/hw_memmap.h"        // defines GPIO_PORTF_BASE
// #include "inc/tm4c123gh6pm.h"     // defines interrupt vectors
//                                   //   and register addresses
// #include "driverlib/gpio.h"       // defines for GPIO peripheral
// #include "driverlib/sysctl.h"     // system control functions

// #include "delay.h"

// // LED's
// #define RED_LED   GPIO_PIN_1
// #define BLUE_LED  GPIO_PIN_2
// #define GREEN_LED GPIO_PIN_3

// // BUTTONS (value in hex)
// #define SW_1  GPIO_PIN_4  // 16
// #define SW_2  GPIO_PIN_0  // 1


// void init(uint32_t *clkRate)
// {
//     // Set and get the 20 MHz clock
//     SysCtlClockSet(SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_SYSDIV_10);
//     SysCtlDelay(100);              // Settle oscillator
//     *clkRate = SysCtlClockGet();

//     // Enable Peripherals
//     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

//     // Set GPIO Port Pins (PINx)
//     GPIOPadConfigSet(GPIO_PORTF_BASE, GREEN_LED, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPD);
//     GPIOPadConfigSet(GPIO_PORTF_BASE, SW_1, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPU);

//     // Set GPIO data direction register (DDRx)
//     GPIODirModeSet(GPIO_PORTF_BASE, GREEN_LED, GPIO_DIR_MODE_OUT);
//     GPIODirModeSet(GPIO_PORTF_BASE, SW_1, GPIO_DIR_MODE_IN);  // set for input

//     // Initially write to GPIO Port (PORTx)
//     GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0x00);
// }


// int main(void) 
// {
//     uint32_t clkRate = 0;
//     init(&clkRate);
  
//     while (1) {
//         // SW_1 pin is 0 when push with a pull up resistor
//         if (GPIOPinRead(GPIO_PORTF_BASE, SW_1) == 0)
//             GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, GREEN_LED);
//         else
//             GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0x00);
//     }
// }



///////////// switch
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

// BUTTONS (value in hex)
#define TOP_SW_1  GPIO_PIN_7  // 16
// #define SW_2  GPIO_PIN_0  // 1


void init(uint32_t *clkRate)
{
    // Set and get the 20 MHz clock
    SysCtlClockSet(SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_SYSDIV_10);
    SysCtlDelay(100);              // Settle oscillator
    *clkRate = SysCtlClockGet();

    // Enable Peripherals
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);  // reg A

    // Set GPIO Port Pins (PINx)
    GPIOPadConfigSet(GPIO_PORTF_BASE, GREEN_LED, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPD);
    GPIOPadConfigSet(GPIO_PORTA_BASE, TOP_SW_1, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPD);

    // Set GPIO data direction register (DDRx)
    GPIODirModeSet(GPIO_PORTF_BASE, GREEN_LED, GPIO_DIR_MODE_OUT);
    // GPIODirModeSet(GPIO_PORTF_BASE, TOP_SW_1, GPIO_DIR_MODE_IN);  // set for input

    // Initially write to GPIO Port (PORTx)
    GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0x00);
}


int main(void) 
{
    uint32_t clkRate = 0;
    init(&clkRate);
  
    while (1) {
        // SW_1 pin is 0 when push with a pull up resistor
        if (GPIOPinRead(GPIO_PORTA_BASE, TOP_SW_1) == 0)
            GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, GREEN_LED);
        else
            GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0x00);
    }
}

