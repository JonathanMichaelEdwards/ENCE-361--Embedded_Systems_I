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



char *initPtr(const char *message)
{
    char *me = (char*)malloc(sizeof(char) * strlen(message)*100+1);
    return me;
}


void concatMessage()
{
    char *message1 = "Hello";
    char *message2 = " Jonathan";

    char *name = malloc(sizeof(char) * strlen(message1));  // initial
    memcpy(name, message1, 5);  // copy the first message

    name = realloc(name, sizeof(char) * 16);

    memcpy(&name[5], message2, 9);  // concaternate the second message with the first

    puts(name);
}


// Concaternating extra characters by reallocating memory
void addOn(const char *message_1, const char *message_2, char *text)
{
    text = (char*)realloc(text, sizeof(char) * (strlen(message_1)+strlen(message_2)+1));

    for (int i = 0; i < strlen(message_2); i++)
        text[strlen(message_1)+i] = message_2[i];
}


// note: Use this when 'NOT' using threads
// Passing a single pointer into a function
void singlePoninter(const char *message, char *text)
{
    const char *type = "from the SINGLE pointer.";

    for (int i = 0; i < strlen(message); i++) 
        text[i] = message[i];
    
    addOn(message, type, text);  // Adding extra text
}


void singlePoninter_2(const char *message, char *text)
{
    printf("inside *2:  %p\n", text);
    
    text[0] = 'H';
    text[1] = 'i';
}


void doublePoninter_2(const char *message, char **text)
{
    char *_text = (char*)malloc(sizeof(char) * 50);  // temp pointer
    printf("inside dbl *2:  %p\n", text);
    
    _text[0] = 'H';
    _text[1] = 'i';
    
    *text = _text;
}


// note: Use this when 'USING' threads
// Using the reference of the single pointer for the double pointer
void doublePoninter(const char *message, char **cpyText)
{
    const char *type = "from the DOUBLE pointer.";
    char *text = (char*)malloc(sizeof(char) * strlen(message)+1);  // temp pointer
    
    for (int i = 0; i < strlen(message); i++) 
        text[i] = message[i];
    
    addOn(message, type, text);  // Adding extra text
   
    *cpyText = text;             // Pointing the double pointer to the text
}


void singleInt(const int num, int *value)
{
    *value = num;
}

// dont like
void doubleInt(const int num, int **value)
{
    *value = (int*)&num;
}

void doubleInt_2(const int num, int **value)
{
    int *_val = (int*)malloc(sizeof(int) * 50);  // temp pointer
    
    _val[0] = num;

    *value = _val;

    // free(_val);  // cant do this will lose the information from ptr link
    // free at the end
}





int main()
{
    const char *message = "Hello I am Jonathan: ";
    const int luckyNumber = 6;

    // pre-allocate some space - before passing into function (only need single ptr)
    // need enough space either overlapping will occur
    char *cpyText_1 = initPtr(message);
    char *cpyText_2 = initPtr(message);

    // if pre defined NULL - then we need a dble ptr
    // char *cpyText_3 = NULL;
    // char *cpyText_4 = NULL;

    // int value = 0;
    // int *value_2 = 0;
    int a = 1;
    int *value_2 = &a;

    // string pointers
    doubleInt_2(luckyNumber, &value_2);
    
    singlePoninter(message, cpyText_1);
    printf("outside *2: %p\n", cpyText_2);
    singlePoninter_2(message, cpyText_2);

    doublePoninter(message, &cpyText_2);  // reference of the first pointer
    // printf("outside dbl *1:  %p\n", cpyText_3);
    // doublePoninter_2(message, &cpyText_3); 
    // printf("outside dbl *1:  %p\n", cpyText_3);

    puts(cpyText_1);
    puts(cpyText_2);

    // puts(cpyText_3);
    // puts(cpyText_4);

    // concatMessage();  // extra


    // int pointers
    // singleInt(luckyNumber, &value);
    // doubleInt_2(luckyNumber, &value_2);
    // _value_2 = *value_2;
    
    
    // printf("The Value of the SINGLE Pointer '%d' should be %d\n", value, luckyNumber);
    printf("The Value of the Double Pointer '%d' should be %d\n", *value_2, luckyNumber);
    // printf("The Value of the DOUBLE Pointer '%d' should be %d\n", _value_2, luckyNumber);
    // free(value_2);
    
    exit(0);
}
