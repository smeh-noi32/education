#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "./Headers/arr.h"
 
int main() {
    choiceArr();
    int* arrF;
    int vol;
    if ( arrType == 1){
        enterARR ();
    }
    else {
        choiceMethod ();
        system("cls");
        printf("Orig:\n");
        printArr();
        for (int i = 0; i < arrCout; i++){
            vol = size[i];
            arrF = arr[i];
            switchMethod (arrF, vol);
        }

        printf("Result:\n");
        printArr();
    
        free(arrF);
    }
    return 0;
}