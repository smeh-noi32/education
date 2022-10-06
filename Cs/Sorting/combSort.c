#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./Headers/arr.h"

int main () {
    
    for (int i = 0; i < length; i++) {
        printf(" %d,", a[i]);
    }
    printf("\n");

    int delta = length;

    sort = false;

    while (!sort || delta !=1) {
        if (delta > 1) {
            delta = delta * 10 / 13;        // Эквивалент delta/1.3
        }
        else 
            delta = 1;
        
        sort = true;
        for (int i = delta; i < length; i++) {
            if (a[i-delta] > a[i]){
                buf = a[i];
                a[i] = a[i - delta];
                a[i - delta] = buf;
                sort = false;
            }
        }
        
    }
    
    for (int i = 0; i < length; i++) {
        printf(" %d,", a[i]);
    }
    printf("\n");
    
    system("pause");
    return 0;
}