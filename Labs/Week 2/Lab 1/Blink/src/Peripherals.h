


#ifndef PERIPHERALS_H
#define PERIPHERALS_H


#include "inc/hw_memmap.h"        // defines GPIO_PORTF_BASE
#include "inc/tm4c123gh6pm.h"     // defines interrupt vectors
                                  //   and register addresses
#include "driverlib/gpio.h"       // defines for GPIO peripheral
#include "driverlib/sysctl.h"     // system control functions


// Port's
#define PORT_E    GPIO_PORTE_BASE
#define PORT_F    GPIO_PORTF_BASE
#define PORT_G    GPIO_PORTG_BASE
#define PORT_H    GPIO_PORTH_BASE

// LED's
#define RED_LED      GPIO_PIN_1
#define BLUE_LED     GPIO_PIN_2
#define GREEN_LED    GPIO_PIN_3

// BUTTONS
#define SW_1  GPIO_PIN_4
#define SW_2  GPIO_PIN_0

#define HIGH    0x01
#define LOW     0x00


// functions ...
void initPeripherals();
void initLED(uint32_t portX, uint8_t pinX);
void initSwitch(uint32_t portX, uint8_t pinX);

int32_t pinRead(uint32_t portX, uint8_t pinX);
void pinWrite(uint32_t portX, uint8_t pinX, uint8_t val);


#endif // PERIPHERALS_H
