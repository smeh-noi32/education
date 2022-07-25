#include <stdio.h>
#include <stdlib.h>

#define size 10

int main(){
    
    int *mas = NULL, sizePlus;
    mas = malloc(sizeof(int) * size);

    mas[0] = 1;
    printf("%d\n", mas[0]);

    for (int i = 1; i < size; i++) {
        mas[i] = mas[i-1]*2;
        printf("%d\n", mas[i]);
    }

    sizePlus = size + 4;
    mas = realloc(mas, sizeof(*mas) * sizePlus);
    for (int i = size ; i < sizePlus; i++) {
        mas[i] = 777;
        printf("%d\n", mas[i]);

    }
    

    free(mas);
    mas = NULL;

    system("pause");
    return 0;
}