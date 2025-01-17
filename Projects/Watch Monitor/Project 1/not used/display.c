/*
 * delay.c
 *
 *  Created on: 09/04/2020
 *  Authors: Grace Kaye-Blake, Jonathan Edwards, Riley Symon
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utils/ustdlib.h"
#include "OrbitOLED/OrbitOLEDInterface.h"

#include "display.h"



//
//void initDisplay()
//{
//    OLEDInitialise();
//}


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


//*****************************************************************************
// Function to display the mean ADC value (10-bit value, note) and sample count.
//*****************************************************************************
void displayMeanVal(int16_t meanValX, int16_t meanValY, int16_t meanValZ, uint32_t count)
{
    char string[17];  // 16 characters across the display

    // Form a new string for the line.  The maximum width specified for the
    //  number field ensures it is displayed right justified.
    usnprintf (string, sizeof(string), "Mean X = %5d       ", meanValX);
    // Update line on display.
    OLEDStringDraw (string, 0, 0);
    usnprintf (string, sizeof(string), "Mean Y = %5d       ", meanValY);
    // Update line on display.
    OLEDStringDraw (string, 0, 1);
    usnprintf (string, sizeof(string), "Mean Z = %5d       ", meanValZ);
    // Update line on display.
    OLEDStringDraw (string, 0, 2);

    usnprintf (string, sizeof(string), "Sample # %5d       ", count);
    OLEDStringDraw (string, 0, 3);
}

//
//*****************************************************************************
// Function to display the mean ADC value (10-bit value, note) and sample count.
// modified displayMeanValue that displays the given integers divided by 100.
//*****************************************************************************
void displayMeanValf(int32_t meanValX, int32_t meanValY, int32_t meanValZ, uint32_t count)
{
    char string[17];  // 16 characters across the display
    int32_t wholeX = abs(meanValX / 100);
    int32_t decimalX = abs(meanValX - (100 * wholeX));
    int32_t wholeY = abs(meanValY / 100);
    int32_t decimalY = abs(meanValY - (100 * wholeY));
    int32_t wholeZ = abs(meanValZ / 100);
    int32_t decimalZ = abs(meanValZ - (100 * wholeZ));

    if (meanValX >= 0) {
    usnprintf (string, sizeof(string), "Mean X =  %d.%d       ", wholeX, decimalX);
        // Update line on display.
        OLEDStringDraw (string, 0, 0);
    } else {
        usnprintf (string, sizeof(string), "Mean X = -%d.%d       ", wholeX, decimalX);
        // Update line on display.
        OLEDStringDraw (string, 0, 0);
    }

    if (meanValY >= 0) {
        usnprintf (string, sizeof(string), "Mean Y =  %d.%d       ", wholeY, decimalY);
        // Update line on display.
        OLEDStringDraw (string, 0, 1);
    } else {
        usnprintf (string, sizeof(string), "Mean Y = -%d.%d       ", wholeY, decimalY);
        // Update line on display.
        OLEDStringDraw (string, 0, 1);
    }

    if (meanValZ >= 0) {
        usnprintf (string, sizeof(string), "Mean Z =  %d.%d       ", wholeZ, decimalZ);
        // Update line on display.
        OLEDStringDraw (string, 0, 2);
    } else {
        usnprintf (string, sizeof(string), "Mean Z = -%d.%d       ", wholeZ, decimalZ);
        // Update line on display.
        OLEDStringDraw (string, 0, 2);
        }

    // usnprintf (string, sizeof(string), "Sample # %5d", count);
    // OLEDStringDraw (string, 0, 3);
}
