/**********************************************************
 *
 * readAcc.c
 *
 * Example code which reads acceleration in
 * three dimensions and displays the reulting data on
 * the Orbit OLED display.
 *
 *    C. P. Moore
 *    11 Feb 2020
 *
 **********************************************************/

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
//#include "OrbitOLED/OrbitOLEDInterface.h"
#include "utils/ustdlib.h"
#include "acc.h"
#include "display.h"
#include "i2c_driver.h"


#define RED_LED   GPIO_PIN_1
#define BLUE_LED  GPIO_PIN_2
#define GREEN_LED GPIO_PIN_3



/**********************************************************
 * Constants
 **********************************************************/
// Systick configuration
#define SYSTICK_RATE_HZ    10

/*******************************************
 *      Local prototypes
 *******************************************/
//void initClock (void);
//void initDisplay (void);
void displayUpdate (char *str1, char *str2, int16_t num, uint8_t charLine);
//void initAccl (void);
//vector3_t getAcclData (void);

/***********************************************************
 * Initialisation functions: clock, SysTick, PWM
 ***********************************************************
 * Clock
 ***********************************************************/
void
initClock (void)
{
    // Set the clock rate to 20 MHz
    SysCtlClockSet (SYSCTL_SYSDIV_10 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_16MHZ);
}

/*********************************************************
 * initDisplay
 *********************************************************/
//void
//initDisplay (void)
//{
//    // Initialise the Orbit OLED display
////    OLEDInitialise ();
//    initDisplay();
//}

////*****************************************************************************
//// Function to display a changing message on the display.
//// The display has 4 rows of 16 characters, with 0, 0 at top left.
////*****************************************************************************
//void
//displayUpdate (char *str1, char *str2, int16_t num, uint8_t charLine)
//{
//    char text_buffer[17];           //Display fits 16 characters wide.
//
//    // "Undraw" the previous contents of the line to be updated.
//    OLEDStringDraw ("                ", 0, charLine);
//    // Form a new string for the line.  The maximum width specified for the
//    //  number field ensures it is displayed right justified.
//    usnprintf(text_buffer, sizeof(text_buffer), "%s %s %3d", str1, str2, num);
//    // Update line on display.
//    OLEDStringDraw (text_buffer, 0, charLine);
//}

/*********************************************************
 * initAccl
 *********************************************************/
//void
//initAccl (void)
//{
//    char    toAccl[] = {0, 0};  // parameter, value

//    /*
//     * Enable I2C Peripheral
//     */
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
//    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C0);
//
//    /*
//     * Set I2C GPIO pins
//     */
//    GPIOPinTypeI2C(I2CSDAPort, I2CSDA_PIN);
//    GPIOPinTypeI2CSCL(I2CSCLPort, I2CSCL_PIN);
//    GPIOPinConfigure(I2CSCL);
//    GPIOPinConfigure(I2CSDA);
//
//    /*
//     * Setup I2C
//     */
//    I2CMasterInitExpClk(I2C0_BASE, SysCtlClockGet(), true);
//
//    GPIOPinTypeGPIOInput(ACCL_INT2Port, ACCL_INT2);
//    initI2C();
//    initAcc();
//    //Initialize ADXL345 Acceleromter
//
//    // set +-2g, 13 bit resolution, active low interrupts
//    // range is changed
//    toAccl[0] = ACCL_DATA_FORMAT;
//    toAccl[1] = (ACCL_RANGE_2G | ACCL_FULL_RES);  // added ACCL_RANGE_2G (want max resolution)
//    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);
//
//    toAccl[0] = ACCL_PWR_CTL;
//    toAccl[1] = ACCL_MEASURE;
//    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);
//
//
//    toAccl[0] = ACCL_BW_RATE;
//    toAccl[1] = ACCL_RATE_100HZ;
//    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);
//
//    toAccl[0] = ACCL_INT;
//    toAccl[1] = 0x00;       // Disable interrupts from accelerometer.
//    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);
//
//    toAccl[0] = ACCL_OFFSET_X;
//    toAccl[1] = 0x00;
//    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);
//
//    toAccl[0] = ACCL_OFFSET_Y;
//    toAccl[1] = 0x00;
//    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);
//
//    toAccl[0] = ACCL_OFFSET_Z;
//    toAccl[1] = 0x00;
//    I2CGenTransmit(toAccl, 1, WRITE, ACCL_ADDR);
//}


///********************************************************
// * Function to read accelerometer
// ********************************************************/
//vector3_t
//getAcclData (void)
//{
//    char    fromAccl[] = {0, 0, 0, 0, 0, 0, 0}; // starting address, placeholders for data to be read.
//    vector3_t acceleration;
//    uint8_t bytesToRead = 6;
//
//    fromAccl[0] = ACCL_DATA_X0;
//    I2CGenTransmit(fromAccl, bytesToRead, READ, ACCL_ADDR);
//
//    acceleration.x = (fromAccl[2] << 8) | fromAccl[1]; // Return 16-bit acceleration readings.
//    acceleration.y = (fromAccl[4] << 8) | fromAccl[3];
//    acceleration.z = (fromAccl[6] << 8) | fromAccl[5];
//
//    return acceleration;
//}

// uint8_t _buffer[21];
// /* transform the accel and gyro axes to match the magnetometer axes */
// const int16_t tX[3] = {0,  1,  0};

//const float G = 981.0f; // 9.81 x 100 => m to cm
//const int16_t c = 256.f;

/********************************************************
 * main
 ********************************************************/
int
main (void)
{
    ///// need to initialize here if u want to use accelerometer
    float accX, accY, accZ = 0;
    float rollPer, pitchPer = 0;

//    vector3_t acceleration_raw; // lsb
    // convert to g / lsb =?

    initClock();
        initDisplay();
//    initAccl ();
//    OLEDInitialise();

    initI2C();
    initAccl();


    // led stuff
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
//    GPIOPadConfigSet(GPIO_PORTF_BASE, GREEN_LED, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPD);
//    GPIODirModeSet(GPIO_PORTF_BASE, GREEN_LED, GPIO_DIR_MODE_OUT);
//    GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0x00);

//    OLEDStringDraw ("Accelerometer", 0, 0);
        printMessage("Accelerometer", 0);
//    acceleration_raw = getAcclData();

//    int16_t ax_init = acceleration_raw.x;
//    int16_t ay_init = acceleration_raw.y;

    while (1)
    {
//        SysCtlDelay (SysCtlClockGet () / 6);    // Approx 2 Hz
//        acceleration_raw = getAcclData();
//
//        float _ax = (((float)acceleration_raw.x * G) / c);
//        float _ay = (((float)acceleration_raw.y * G) / c);
////        int16_t _az = (((float)acceleration_raw.z * G) / c);


//        if ((-100 <= _ax && _ax <= 100) && (-100 <= _ay && _ay <= 100))
//            GPIOPinWrite(GPIO_PORTF_BASE,  GREEN_LED, GREEN_LED);
//        else
//            GPIOPinWrite(GPIO_PORTF_BASE,  GREEN_LED, 0x00);

        getAccelData(&accX, &accY, &accZ);

        getAccelPer(&accX, &accY, &rollPer, &pitchPer);

        printDisplay("Accl", "Roll", rollPer, 1);
        printDisplay("Accl", "Pitch", pitchPer, 2);


        // conversion to percentage
//        int8_t _roll_percentage = accX / 9.81;
//        int8_t _pitch_percentage = accY / 9.81;
//
//        // capping roll and pitch at 100 % the accelerometor is not perferct
////        if  pitch and roll is less then 100 % then change value
//        int8_t pitch_percentage = (abs(_pitch_percentage) < 100 ? _pitch_percentage : 100);
//        int8_t roll_percentage = (abs(_roll_percentage) < 100 ? _roll_percentage : 100);

//        displayUpdate ("Accl", "Roll", rollPer, 1);
//        displayUpdate ("Accl", "Pitch", pitchPer, 2);
//        displayUpdate ("Accl", "Y", _az, 3);


//        displayUpdate ("Accl", "X", (int16_t)(float)acceleration_raw.x * (8192.0f /218.0f), 1);
//        displayUpdate ("Accl", "Y", (int16_t)(float)acceleration_raw.y * (8192.0f /218.0f), 2);
//        displayUpdate ("Accl", "Z", (int16_t)(float)acceleration_raw.z * (8192.0f /218.0f), 3);
    }
}


// rot
//displayUpdate ("Accl", "X", (int16_t)((acceleration_raw.x) / (9.81*4.2)), 1);
