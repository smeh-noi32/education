#include "../Headers/arr.h"

void outArr (int *arrF, int vol) {
    printf("array: [");
    for (int i = 0; i < vol; i++) {
        printf("%d", arrF[i]);
        if (i < vol-1) 
            printf(", ");
    }
    printf("]\n");
}

int enterARR () {
    int vol;
    printf("Input N: ");
    scanf("%d", &vol);
    int* arrF;
    arrF = (int *)malloc(vol * sizeof(int));
    printf("Input the array elements:\n");
    for (int i = 0; i < vol; i++){
        scanf("%d", &arrF[i]);
    }

    system("cls");
    outArr(arrF, vol);

    choiceMethod ();

    system("cls");
    printf("Original ");
    outArr(arrF, vol);

    switchMethod (arrF, vol);
 
    printf("Sorted ");
    outArr(arrF, vol);
    system("pause");

    free(arrF);
    return 0;
}