#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main () {
    int buf, max = 0, a[] = {9, 5, 0, 6, 7, 2, 8, 4, 1, 3};
    int length = sizeof(a)/sizeof(a[0]);
    bool sort;

    printf("Source: ");
    for (int i = 0; i < 10; i++) {
        printf(" %d,", a[i]);
    }
    printf("\n");

    while (sort == false) {
        sort = true;
        for (int i = 0; i < length - 1 - max; i++) {
            //printf("a[%d] = %d, a[%d] = %d\n", i, a[i], (i+1), a[i+1]);
            if (a[i] > a[i+1]) {
                buf = a[i];
                a[i] = a[i+1];
                a[i+1] = buf;
                sort = false;
            }
            //printf("a[%d] = %d, a[%d] = %d\n", i, a[i], (i+1), a[i+1]);
        }
        max++;
    }

    printf("Result: ");
    for (int i = 0; i < 10; i++) {
        printf(" %d,", a[i]);
    }
    printf("\n");
    

    system("pause");
    return 0;    
}