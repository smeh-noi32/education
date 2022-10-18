#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./Combined project/Headers/arr.h"

int main () {
    printArr();

    
    for (int i = 0; i < arrCout; i++) {
        if (size[i] >= 2) {
            int stop = size[i] - 1;
            max=0;
            sort = false;
        
            while (sort == false) {
                sort = true;
                for (int j = 0; j < stop - max; j++) {
                    if (arr[i][j] > arr[i][j+1]) {
                        buf = arr[i][j];
                        arr[i][j] = arr[i][j+1];
                        arr[i][j+1] = buf;
                        sort = false;
                    }
                }
                max++;
            }
        }
    }

    printf("Result:\n");
    printArr();

    return 0;
}