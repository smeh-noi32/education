#include "../Headers/arr.h"

void switchMethod (int *arrF, int vol) {
    switch (Method) {
        case 1:
            bubbleFunc(arrF, vol);
            break;
        case 2:
            shakeFunc(arrF, vol);;
            break;
        case 3:
            insertionFunc(arrF, vol);
            break;
        case 4:
            combFunc(arrF, vol);
            break;
        case 5:
            selectionFunc (arrF, vol);
            break;
                
        default:
            printf("\n\nSorting failed\n\n");
            break;
        }
}