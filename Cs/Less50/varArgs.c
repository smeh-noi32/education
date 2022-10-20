/*
1) Напишите процедуру с переменным количеством аргументов, которая 
считает среднее арифметическое целых чисел и возвращает результат в виде вещественного числа.
2) Измените процедуру из задания 1 так, чтобы она работала с целыми и вещественными числами одновременно.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void func (int a, int b, int c) {
    printf("%d %d %d\n", &a, &b, &c);
    int *ptr = &a;
    printf("%d\n", *(ptr++));
    printf("%d\n", *(ptr++));
    printf("%d\n", *(ptr++));
}

int sumInt(int cnt,...) {
    int res = 0;
    int *ptr = &cnt + 1;
    for ( ; cnt > 0; cnt--) {
        res += *(ptr++);
    } 
    return res;
}

double averageInt(int cnt,...) {
    int res = 0;
    int buf = cnt;
    int *ptr = &cnt + 1;
    for ( ; cnt > 0; cnt--) {
        res += *(ptr++);
    }

    double aveInt = (double)res/(double)buf;
    return aveInt;
}

double summa(int cnt,...) {
    double res = 0;
    double *ptr = &cnt + 1;
    for ( ; cnt > 0; cnt--) {
        res += *(ptr++);
    } 
    return res;
}

double average (int cnt, ...) {
    double res = 0;
    double buf = cnt;
    double *ptr = &cnt + 1;
    for ( ; cnt > 0; cnt--) {
        res += *(ptr++);
    } 
    return res/buf;
}

double averageMulty (int cnt, ...) {
    double res = 0;
    double buf = cnt;
    va_list ptr;
    va_start(ptr, cnt);
    for ( ; cnt > 0; cnt--) {
        res += va_arg(ptr, double);
    }
    va_end(ptr);
    return res/buf;
}

void SuperMegaPrint (char *prm, ...) {
    va_list ptr;
    va_start (ptr, prm);
    while (*prm) {
        if (*prm == 'i')
            printf("--%d--\n", va_arg(ptr, int));
        else if (*prm == 'd')
            printf("--%f--\n", va_arg(ptr, double));
        else if (*prm == 'c')
            printf("--%c--\n", va_arg(ptr, int));
        else if (*prm == 's')
            printf("--%s--\n", va_arg(ptr, char*));
        prm++;
    }
    va_end(ptr);
}

int main() {

    func(10, 20, 30);
    
    printf("%d\n", sumInt(4, 2, 2, 3, 1));
    printf("%f\n", summa(4, 1.2, 2.3, 1.0, (double)6));
    printf("%g\n", average(4, 3.2, 2.3, 88.5, (double)6));
    printf("%g\n", averageInt(4, 3, 2, 88, 6));
    printf("%g\n", averageMulty(4, 3.2, 2.0, 88.5, 6.0));

    SuperMegaPrint("icds", 45, 'e', 18.2, "pop");

    system("pause");
    return 0;
}