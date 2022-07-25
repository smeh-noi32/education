/*Создание константы, макроса = 10 и отображение на экране
Создание массива целочисленного типа, указав в качестве длины массива константу объявленную ранее.
И отображение массива на экране.

Создание переменной целочисленного типа и заполнение её случайным число в диапазоне 
от 10 до 19 включительно.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define con 10

int main(){

    int arr[con], i, r;
    for ( i =0; i < 10; i++) {
        arr[i] = i+1;
        printf(" %d ", arr[i]);
    }

    printf("\n%d\n", con);

    srand(time(NULL));
    r = rand()%(19 - 10 +1) + 10;
    printf("%d\n", r);

    system("pause");
    return 0;
}