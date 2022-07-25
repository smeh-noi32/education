/*Создайте несколько указателей разных типов и выделите для них память.
Далее присвойте им значения и выведите их на экран. Помнитепро очистку памяти
и проверку наличия адреса.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *x = NULL;
    float *y = NULL;
    char *z = NULL;

    x = malloc(sizeof(int));
    y = malloc(sizeof(float));
    z = malloc(sizeof(char));

    if ( x != NULL){
        *x = 333;
        printf("%d\n", *x);
    }

    if ( y != NULL){
        *y = 333;
        printf("%f\n", *y);
    }

    if ( z != NULL){
        *z = "tree";
        printf("%s\n", *z);
    }

    free(x);
    free(y);
    free(z);
    x = NULL;
    y = NULL;
    z = NULL;

    system("pause");
    return 0;
}