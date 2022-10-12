#ifndef ARR_H_INCLUDED
#define ARR_H_INCLUDED

int buf = 0, min = 0, max = 0;
bool sort;

#define arrCout 6

int arr[arrCout][10] = {{},
    {4},
    {1, 1, 1, 1, 1, 1},
    {90, 2, 6, 9, 4, 37, 7},
    {9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};

int size[] = {0, 1, 6, 7, 10, 10};

int printArr ();

#include "../func/printArr.c"

#endif 