#ifndef ARR_H_INCLUDED
#define ARR_H_INCLUDED

#include <stdbool.h>

int buf, min = 0, max = 0;
bool sort, input;
int arrType, Method;
char stringTMP[20];

#define arrCout 6

int arr[arrCout][10] = {{},
    {4},
    {1, 1, 1, 1, 1, 1},
    {90, 2, 6, 9, 4, 37, 7},
    {9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};

int size[] = {0, 1, 6, 7, 10, 10};

void printArr ();
int choiceArr ();
int enterARR ();
int choiceMethod ();
void switchMethod (int *arrF, int vol);
int bubbleFunc (int *arrF, int vol);
int shakeFunc (int *arrF, int vol);
int insertionFunc (int *arrF, int vol);
int combFunc (int *arrF, int vol);
int selectionFunc (int *arrF, int vol);

#include "../func/choiceArr.c"
#include "../func/choiceMethod.c"
#include "../func/switchMethod.c"
#include "../func/enterARR.c"
#include "../func/printArr.c"
#include "../func/bubbleFunc.c"
#include "../func/shakeFunc.c"
#include "../func/insertionFunc.c"
#include "../func/combFunc.c"
#include "../func/selectionFunc.c"

#endif 