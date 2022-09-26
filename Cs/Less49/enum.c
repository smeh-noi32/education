/*
1) Создайте перечисление арифметических операций и создайте из него тип данных.
2) Создайте функцию, которая принимает 2 параметра целлого типа и операцию из задания 1.
 Воспользуйтесь этой функцией и отобразите значение на экране.
*/

#include <stdio.h>
#include <stdlib.h>

enum operations { add = '+', sub = '-', mult = '*', divi = '/'};
typedef enum operations OP;

int result;

int action ( int x, int y, OP oper) {
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
    int a, b;
    char c[20];
/*
    printf("Enter a number 1: ");
    scanf("%d", &a);
    printf("Enter a mathematical operation ( '+', '-', '*', '/' ): ");
    scanf("%s", c);
    printf("Enter a number 2: ");
    scanf("%d", &b);
*/

    printf("Enter an expression, without spaces, using signs ( '+', '-', '*', '/' ).\nFor example: '2+2' or '3/3'\n");
    scanf("%d%c%d", &a, c, &b);

    printf("Result: %d\n", action(a, b, c[0]));
    system("pause");
    return 0;
}