/*
 * delay.c
 *
 *  Created on: 09/04/2020
 *      Author: Jonathan Michael Edwards
 */

#ifndef DISPLAY_H
#define DISPLAY_H


// Constants
#define MAX_STR_LEN 16


void initDisplay(void);

void printMessage(char *message, uint8_t index);
void displayAccel(char *str1, char *str2, int16_t num, uint8_t charLine);
void displayMeanVal(uint16_t meanVal, uint32_t count);
void displayButtonState(char *butStr, char *stateStr, uint8_t numPushes, uint8_t charLine);


#endif // DISPLAY_H
