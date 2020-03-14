/*
 * delay.c
 *
 *  Created on: 09/04/2020
 *      Author: Jonathan Michael Edwards
 */

#ifndef DISPLAY_H
#define DISPLAY_H


void initDisplay();
void printMessage(char *message, uint8_t index);
void printDisplay(char *str1, char *str2, int16_t num, uint8_t charLine);


#endif // DISPLAY_H
