/*
1) Создайте перечисление арифметических операций и создайте из него тип данных.
2) Создайте функцию, которая принимает 2 параметра целлого типа и операцию из задания 1.
 Воспользуйтесь этой функцией и отобразите значение на экране.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum operations { add = '+', sub = '-', mult = '*', divi = '/'};
typedef enum operations OP;

float result;

float action ( float x, float y, OP oper) {
    switch (oper) {
    case add:
        result = x + y;
        break;
    case sub:
        result = x - y;
        break;
    case mult:
        result = x * y;
        break;
    case divi:
        result = x / y;
        break;
    }
    return result;
}

int main() {
    float a, b;
    char c[20];
    bool quit = false;

    printf("Enter an expression, without spaces, using signs ( '+', '-', '*', '/' ).\nFor example: '2+2' or '3/3'\n");
    printf("Enter '0e0' for quit\n");

    while (!quit) {
        scanf("%g%c%g", &a, c, &b);
        if (a == 0 || c[0] == 'q'|| b == 0){
            quit = true;
        }
        else
            printf("Result: %g\n", action(a, b, c[0]));
    }

    system("pause");
    return 0;
}