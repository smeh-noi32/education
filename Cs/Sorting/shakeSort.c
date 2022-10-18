#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./Combined project/Headers/arr.h"

int main () {
    printArr();

    for (int i = 0; i < arrCout; i++) {
        if (size[i] >= 2) {
            min = 0;
            max = size[i] - 1;
            while (min <= max) {
                for (int j = max; j > min; j--) {
                    if (arr[i][j - 1] > arr[i][j]) {
                        buf = arr[i][j];
                        arr[i][j] = arr[i][j-1];
                        arr[i][j-1] = buf;
                    }
                }
                min++;
                for (int j = min; j < max; j++) {
                    if (arr[i][j] > arr[i][j + 1]) {
                        buf = arr[i][j];
                        arr[i][j] = arr[i][j+1];
                        arr[i][j+1] = buf;
                    }
                }
                max--;
            }
        }
    }

    printf("Result:\n");
    printArr();
  
    return 0;    
}