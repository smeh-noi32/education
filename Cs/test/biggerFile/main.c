#include <stdio.h>
#include <stdlib.h>

#include "./headers/allHead.h"

int main () {
    PRINTA_H_INCLUDED
    
    printA();
    system("pause");

    PRINTB_H_INCLUDED
    
    printB();
    system("pause");

    return 0;
}