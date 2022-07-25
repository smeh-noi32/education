/*Цикл 'for' выводящий на экран четные числа от 2 до 18. Тоже самое при помощи двух других циклов*/

#include <stdio.h>
#include <conio.h>

int main(){

    int a = 1, b = 1, c = 1, i;
    int arr[10];

    void NumberIs (int i) {
        arr[i] = i;
        if (arr[i] % 2 == 0)  printf("Number %d is even (i%d)\n", arr[i], i);
    }
    
    printf("Loop 'for'\n");

    for ( a = 1; a < 20; a++) {
        NumberIs(a);
    } 
    
    printf("\nLoop 'while'\n");

    while (b < 20) {
        NumberIs(b);
        b++;
    }

    printf("\nLoop 'do - while'\n");

    do {
        NumberIs(c);
        c++;
    } while (c < 20);
        
    system ("pause");
    return 0;
}