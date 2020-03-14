/*
 * delay.c
 *
 *  Created on: 09/04/2020
 *      Author: Jonathan Michael Edwards
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utils/ustdlib.h"
#include "OrbitOLED/OrbitOLEDInterface.h"

#include "display.h"



//
void initDisplay()
{
    OLEDInitialise();
}


//
void printMessage(char *message, uint8_t index)
{
    OLEDStringDraw(message, 0, index);
}


// written for us ..
//*****************************************************************************
// Function to display a changing message on the display.
// The display has 4 rows of 16 characters, with 0, 0 at top left.
//*****************************************************************************
void displayAccel(char *str1, char *str2, int16_t num, uint8_t charLine)
{
    char text_buffer[17];           //Display fits 16 characters wide.

    // "Undraw" the previous contents of the line to be updated.
    OLEDStringDraw ("                ", 0, charLine);
    // Form a new string for the line.  The maximum width specified for the
    //  number field ensures it is displayed right justified.
    usnprintf(text_buffer, sizeof(text_buffer), "%s %s %3d", str1, str2, num);
    // Update line on display.
    OLEDStringDraw (text_buffer, 0, charLine);
}


// written for us ...
//*****************************************************************************
// Function to display the mean ADC value (10-bit value, note) and sample count.
//*****************************************************************************
void displayMeanVal(uint16_t meanVal, uint32_t count)
{
    char string[17];  // 16 characters across the display

    OLEDStringDraw ("ADC demo 1", 0, 0);

    // Form a new string for the line.  The maximum width specified for the
    //  number field ensures it is displayed right justified.
    usnprintf (string, sizeof(string), "Mean ADC = %4d", meanVal);
    // Update line on display.
    OLEDStringDraw (string, 0, 1);

    usnprintf (string, sizeof(string), "Sample # %5d", count);
    OLEDStringDraw (string, 0, 3);
}


// written for us
//********************************************************
// Function to display a status message on the OLED
//********************************************************
void displayButtonState(char *butStr, char *stateStr, uint8_t numPushes, uint8_t charLine)
{
    char string[MAX_STR_LEN + 1]; //Display fits 16 characters per line.

    OLEDStringDraw ("                ", 0, charLine);
    usprintf (string, "%s - %s %d", butStr, stateStr, numPushes); // * usprintf
    OLEDStringDraw (string, 0, charLine);
}