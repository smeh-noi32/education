#include "../Headers/arr.h"

int selectionFunc (int *arrF, int vol) {
    if (vol >=2){ 
        for (int i = 0; i < vol; i++) {
            min = i;
            for (int j = i + 1; j < vol; j++)
                if (arrF[min] > arrF[j]){
                    min = j;
                }
            buf = arrF[min];
            arrF[min] = arrF[i];
            arrF[i] = buf;
        }
    }
}