#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./Headers/arr.h"

int main () {
    printArr();

    for (int i = 0; i < arrCout; i++) {
        if (size[i] >= 2) {
            for (int j = 1; j < size[i]; j++) {
                buf = arr[i][j];
                int k = j;
                while (k > 0 && arr[i][k - 1] > buf) {
                    arr[i][k] = arr[i][k - 1];
                    k--;
                }
                arr[i][k] = buf;
            }
        }
    }

    printf("Result:\n");
    printArr();

    return 0;
}