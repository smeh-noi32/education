#include "../Headers/arr.h"

int printArr () {    
    for (int i = 0; i < arrCout; i++) {
        int stop = size[i];
        printf("arr%d: [", i);
        for (int j = 0; j < stop; j++) {
            printf("%d", arr[i][j]);
            if (j < stop-1) 
                printf(", ");
        }
        printf("]\n");
    }

    system("pause");
}