/*Заполнить массив длинной 10, символом "7". Изменить код так, чтобы последние 5 элементов массива имели значение равное
 их номеру в массиве возведенное в квадрат.*/
 
#include <stdio.h>
#include <conio.h>

int main(){

    int i=0, arr[10];
    int arrLenght = sizeof arr / sizeof arr[0];
    //printf("%u\n", arrLenght);

    while (i < arrLenght) {
        (i < (arrLenght - 5)) ? (arr[i]= 7) : (arr[i] = i*i);
        printf("i%d = %d\n", i, arr[i]);
        i++;
    }

    system("pause");
    return 0;
}