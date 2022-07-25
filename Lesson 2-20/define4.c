//Заполнение массива, случайными числами от 20 до 39 включительно.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define con 10

int main(){

    int arr[con], i, r;
    srand(time(NULL));

    for ( i =0; i < 10; i++) {
        r = rand()%(39 - 20 +1) + 20;
        arr[i] = r;
        printf(" %d ", arr[i]);
    }

    printf("\n");

    system("pause");
    return 0;
}