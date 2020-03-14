///


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// TivaWare Library Includes:
#include "inc/hw_memmap.h"        // defines GPIO_PORTF_BASE
#include "inc/tm4c123gh6pm.h"     // defines interrupt vectors
                                  //   and register addresses
#include "driverlib/gpio.h"       // defines for GPIO peripheral
#include "driverlib/sysctl.h"     // system control functions

#include "Peripherals.h"



///
void initPeripherals()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
}


///
void initLED(uint32_t portX, uint8_t pinX)
{
    // Set GPIO Port Pins
    GPIOPadConfigSet(portX, pinX, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPD);

    // Set GPIO data direction register (DDRx)
    GPIODirModeSet(portX, pinX, GPIO_DIR_MODE_OUT);

    // Initially write to GPIO Port
    GPIOPinWrite(portX, pinX, 0x00);
}


///
void initSwitch(uint32_t portX, uint8_t pinX)
{
    // Set GPIO Port Pins
    GPIOPadConfigSet(portX, pinX, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPU);

    // Set GPIO data direction register (DDRx)
    GPIODirModeSet(portX, pinX, GPIO_DIR_MODE_IN);
}


//
int32_t pinRead(uint32_t portX, uint8_t pinX)
{
    GPIOPinRead(portX, pinX);
}


//
void pinWrite(uint32_t portX, uint8_t pinX, uint8_t val)
{
    GPIOPinWrite(portX, pinX, val);
}
