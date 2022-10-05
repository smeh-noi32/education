#include <stdio.h>
#include <stdlib.h>

int main () {
    int buf, a[] = {9, 5, 0, 6, 7, 2, 8, 4, 1, 3};
    int length = sizeof(a)/sizeof(a[0]);

    printf("Source: ");
    for (int i = 0; i < 10; i++) {
        printf(" %d,", a[i]);
    }
    printf("\n");
 
    int min = 0;
    int max= length - 1;
    while (min <= max) {
        for (int i = max; i > min; --i) {
            if (a[i - 1] > a[i]) {
                buf = a[i];
                a[i] = a[i-1];
                a[i-1] = buf;
            }
        }
        ++min;
        for (int i = min; i < max; ++i) {
            if (a[i] > a[i + 1]) {
                buf = a[i];
                a[i] = a[i+1];
                a[i+1] = buf;
            }
        }
        --max;
    }

    printf("Result: ");
    for (int i = 0; i < 10; i++) {
        printf(" %d,", a[i]);
    }
    printf("\n");
    
    system("pause");
    return 0;    
}