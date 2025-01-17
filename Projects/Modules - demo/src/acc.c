/*******************************************************
 *
 * acc.c
 *
 * Support for interfacing with the ADXL345 accelerometer
 * on the Orbit BoosterPack.
 *
 * Author: Jonathan Edwards
 *
*******************************************************/


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_i2c.h"
#include "driverlib/pin_map.h" //Needed for pin configure
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/i2c.h"
#include "utils/ustdlib.h"

#include "acc.h"
#include "i2c_driver.h"
#include "delay.h"


#define  GRAVITY             9.81
#define  GRAVITY_IN_CM       981.f
#define  ACCEL_SENSITVITY    256.f  // data sheet


typedef struct{
    int16_t x;
    int16_t y;
    int16_t z;
} vector3_t;


// Initialize ADXL345 Acceleromter
// set +-2g, 13 bit resolution, active low interrupts
void initAccl(void)
{
    char toAccl[] = {0, 0};  // parameter, value


    toAccl[0] = ACCL_DATA_FORMAT;
    toAccl[1] = (ACCL_RANGE_2G | ACCL_FULL_RES);  // max resolution of +-2g
    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);

    toAccl[0] = ACCL_PWR_CTL;
    toAccl[1] = ACCL_MEASURE;
    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);


    toAccl[0] = ACCL_BW_RATE;
    toAccl[1] = ACCL_RATE_100HZ;
    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);

    toAccl[0] = ACCL_INT;
    toAccl[1] = 0x00;
    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);

    toAccl[0] = ACCL_OFFSET_X;
    toAccl[1] = 0x00;
    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);

    toAccl[0] = ACCL_OFFSET_Y;
    toAccl[1] = 0x00;
    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);

    toAccl[0] = ACCL_OFFSET_Z;
    toAccl[1] = 0x00;
    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);
}


//
void initI2C(void)
{
    // Enable I2C Peripheral
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C0);

    // Set I2C GPIO pins
    GPIOPinTypeI2C(I2CSDAPort, I2CSDA_PIN);
    GPIOPinTypeI2CSCL(I2CSCLPort, I2CSCL_PIN);
    GPIOPinConfigure(I2CSCL);
    GPIOPinConfigure(I2CSDA);

    // Setup I2C
    I2CMasterInitExpClk(I2C0_BASE, SysCtlClockGet(), true);

    GPIOPinTypeGPIOInput(ACCL_INT2Port, ACCL_INT2);
}


/********************************************************
 * Reads raw data from the accelerometer
 * function was given to use ...
 ********************************************************/
vector3_t getAcclRawData(void)
{
    char fromAccl[] = {0, 0, 0, 0, 0, 0, 0}; // starting address, placeholders for data to be read.
    vector3_t acceleration;
    uint8_t bytesToRead = 6;

    fromAccl[0] = ACCL_DATA_X0;
    I2CGenTransmit(fromAccl, bytesToRead, READ, ACCL_ADDR);

    acceleration.x = (fromAccl[2] << 8) | fromAccl[1]; // Return 16-bit acceleration readings.
    acceleration.y = (fromAccl[4] << 8) | fromAccl[3];
    acceleration.z = (fromAccl[6] << 8) | fromAccl[5];

    return acceleration;
}


// Convert the raw accl data to acceleration
// data travels through each pointer
void getAccelData(float *accX, float *accY, float *accZ)
{
    delayMilli(500);                      // Approx 2 Hz - (************ change to interuppt *****************)
    vector3_t accRaw = getAcclRawData();

    *accX = (((float)accRaw.x * GRAVITY_IN_CM) / ACCEL_SENSITVITY);
    *accY = (((float)accRaw.y * GRAVITY_IN_CM) / ACCEL_SENSITVITY);
    *accZ = (((float)accRaw.z * GRAVITY_IN_CM) / ACCEL_SENSITVITY);
}


// find the roll and pitch percentage
void getAccelPer(float *accX, float *accY, float *rollPer, float *pitchPer)
{
    // conversion to percentage
    float _rollPer = *accX / GRAVITY;
    float _pitchPer = *accY / GRAVITY;

    // capping roll and pitch at 100 % the accelerometor is not perferct
    //        if  pitch and roll is less then 100 % then change value
    *pitchPer = (abs(_pitchPer) < 100 ? _pitchPer : 100);
    *rollPer = (abs(_rollPer) < 100 ? _rollPer : 100);
}
