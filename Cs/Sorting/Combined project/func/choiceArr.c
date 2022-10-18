#include "../Headers/arr.h"

int choiceArr (){
    printf("Hello!\n");
    printf("You have launched a program for sorting integer arrays.\n");
    printf("Do you want to enter an array from the keyboard?\n");
    printf("(1 - yes, 0 - no): ");
    while (!input) {
        scanf("%s", stringTMP);
        if (stringTMP[0] == '0' || stringTMP[0] == '1'){
            input = true;
        }
    }
    
    arrType = atoi(stringTMP);
}