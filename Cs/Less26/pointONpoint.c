#include <stdio.h>
#include <stdlib.h>

void CreateInt(int **p){
    *p = malloc(sizeof(int));
}

void aFree(void **f){
    free(*f);
    *f = NULL;

}

int main(){
    int *a = NULL;

    CreateInt(&a);

    if ( a !=NULL){
        *a = 777;
        printf("%d\n", *a);
    }

    aFree(&a);

    if (a == NULL){
        printf("Memory cleared\n");
    }

    system("pause");
    return 0;
}