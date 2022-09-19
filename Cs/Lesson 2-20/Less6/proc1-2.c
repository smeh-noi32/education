#include <stdio.h>
#include <conio.h>

/*1) Написание процедуры, которая имеет входной параметр Х типа int, и если X < 10, то выводит на экран, иначе выводит "Error\n".
2) Написание процедуры, имеющей два входных параметра типа int и возвращает результат типа int. Если a > b, функция возвращает 1, иначе 0.
Вывод на экран при помощи процедуры.*/

void proc1(int x){
    if (x < 10){
        printf("x = %d\n", x);
    }

    else {
        printf("Error\n");
    }
}
void proc2 (int a, int b){
    (a > b) ? proc1(1) : proc1(0);
}

int main(){

    proc2(5, 15);
    proc2(15, 5);
    system ("pause");
    return 0;
}