/*
 * delay.c
 *
 *  Created on: 09/04/2020
 *  Authors: Grace Kaye-Blake, Jonathan Edwards, Riley Symon
 */

#ifndef DISPLAY_H
#define DISPLAY_H

// Constants
#define MAX_STR_LEN 16

void initDisplay(void);

void printMessage(char *message, uint8_t index);
void displayAccel(char *str1, char *str2, int16_t num, uint8_t charLine);
void displayMeanVal(int16_t meanValX, int16_t meanValY, int16_t meanValZ, uint32_t count);
void displayMeanValf(int32_t meanValX, int32_t meanValY, int32_t meanValZ, uint32_t count);

#endif // DISPLAY_H
