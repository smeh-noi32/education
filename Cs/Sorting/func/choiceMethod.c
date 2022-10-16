#include "../Headers/arr.h"

int choiceMethod (){
    input = false;
    printf("Select a sorting method from the list:\n");
    printf("1) bubble\n");
    printf("2) cocktail\n");
    printf("3) comb\n");
    printf("4) insertion\n");
    printf("5) selection\n");
    printf("Enter the number of the selected option and press enter.\n");
    while (!input) {
        scanf("%s", stringTMP);
        //printf("%s\n", arrTypeTMP);
        
        if (stringTMP[0] == '1' || stringTMP[0] == '2' || stringTMP[0] == '3' || stringTMP[0] == '4' || stringTMP[0] == '5'){
            input = true;
        }
    }
    Method = atoi(stringTMP);
    return arrType;
}