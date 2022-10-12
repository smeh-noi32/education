#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./Headers/arr.h"

int main () {
    
    printArr();

    for (int i = 0; i < arrCout; i++) {
        if (size[i] >= 2) {
            int delta = size[i];

            sort = false;

            while (!sort || delta != 1) {
                if (delta > 1) {
                    delta = delta * 10 / 13;        // Эквивалент delta/1.3
                }
                else 
                    delta = 1;
                
                sort = true;
                for (int j = delta; j < size[i]; j++) {
                    if (arr[i][j-delta] > arr[i][j]){
                        buf = arr[i][j];
                        arr[i][j] = arr[i][j - delta];
                        arr[i][j - delta] = buf;
                        sort = false;
                    }
                }  
            }
        }
    }
    
    printf("Result:\n");
    printArr();
    
    return 0;
}