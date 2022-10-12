#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./Headers/arr.h"

int main () {
    printArr();

    for (int i = 0; i < arrCout; i++) {
        if (size[i] >= 2) {
            for (int j = 0; j < size[i]; j++){
                min = j;
                for (int k = j + 1; k < size[i]; k++){
                    if (arr[i][min] > arr[i][k]){
                        min = k;
                    }
                }
                buf = arr[i][min];
                arr[i][min] = arr[i][j];
                arr[i][j] = buf;
            }
        }
    }

    printf("Result:\n");
    printArr();

    return 0;
}