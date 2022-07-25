/*СОздайте две переменных целого типа, присвойте им значения и отобразите на экране.
Напишите процедуру, которая увеличивает значение первого на 1, а второго в 2 раза.
С помощью процедуры измените значения двух ваших переменных.

Измените процедуру из первого задания так, чтобы она меняла местами значения двух входных переменных.
*/
#include <stdio.h>
#include <stdlib.h>

void increase(int *a, int *b){
    *a = *a + 1;
    *b = *b * 2;
    
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int s=14, z=8;

    printf("%d      %d\n", s, z);

    increase(&s, &z);

    printf("%d      %d\n", s, z);
    
    system("pause");
    return 0;
}