/*
1) Напишите макрос возведения числа в квадрат и воспользуйтесь им только еслши он есть.
2) Напишите макрос получения модуля числа и воспользуйтесь им.
3) Создайте макросы из заданий 1 и 2 только если есть какой либо ещё макрос,
в противном случае отобразите ошибку с помощью директивы error
4) Создайте макрос хранящий длину. Поставьте проверку, что если его длина меньше 10,
то отобразите ошибку с помощью директивы error.
*/

#include <stdio.h>
#include <stdlib.h>

#define Key
#ifdef Key
    #define sqri(a) (a)*(a)
    #define module(b) (b < 1) ? ((b) * (-1)) : b
#else
    #error key is missing
#endif

int firstPoint(int s){
    #ifdef sqri
        printf("the square of the number %d is %d\n", s, sqri(s));
    #endif
}

int secondPoint (int m){
    #ifdef module
        printf("the modulus of the number %d is %d\n", m, module(m));
    #endif
}

void fourthPoint (){
    #define length 7
    #if length < 10
        #error too short
    #endif
}

int main () {

    firstPoint(6);

    secondPoint(-45);

    fourthPoint();

    system("pause");
    return 0;
}