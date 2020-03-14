/*
 *  pointers.c - an exercise in memory allocation with pointers.
 *
 *  compile with: gcc pointers.c -o pointers -std=c99
 *  run with ./pointers
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <malloc.h>


// return void ** through function
void singleInt(void *num, void **value)
{
    *value = num;
}


// return void ** through function
void charPtr(void *mess, void **val)
{
    *val = mess;
}


int main()
{
    int luckyNumber = 6;
    int luckyNumber_2 = 7;
    char *mess = "Hello";
    char *mess_2 = "Jonathan";

    void *value = NULL; 
    void *val_1 = NULL;
    void *value_2 = NULL;
    void *value_3 = NULL;


    charPtr(mess, &value_2);
    singleInt(&luckyNumber, &value);
    charPtr(mess_2, &value_3);
    singleInt(&luckyNumber_2, &val_1);

    printf("void ptr -> int: %d\n", *(int*)value);
    printf("void ptr -> int: %d\n", *(int*)val_1);
    printf("void ptr -> char: %s\n", (char*)value_2);
    printf("void ptr -> char: %s\n", (char*)value_3);

    
    exit(0);
}
