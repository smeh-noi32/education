/*
1) Напишите процедуру с переменным количеством аргументов, которая 
считает среднее арифметическое целых чисел и возвращает результат в виде вещественного числа.
2) Измените процедуру из задания 1 так, чтобы она работала с целыми и вещественными числами одновременно.
*/

#include <stdio.h>
#include <stdlib.h>
//#include <stdarg.h>

double summa(int cnt,...) {
    double res = 0;
    double *ptr = &cnt + 1;
    for ( ; cnt > 0; cnt--) {
        res += *(ptr+=2);
    }
    return res;
}

int main() {
    
    printf("%f\n", summa(1.2, 2.3));

    system("pause");
    return 0;
}