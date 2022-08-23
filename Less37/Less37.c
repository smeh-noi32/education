/*
1) Запишите в файл несколько переменных целого типа, а затем отобразите их на экране.
2) Выполните пункт 1, но вместо целого типа используйте структуру.
3) Запишите в файл и прочитайте несколько переменных разных типов подряд.
4) Попробуйте записать в файл и прочитать структуру, одним из полей которой будет другая структура.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a = 5, b = 6, c = 7;

typedef struct {
    int x, y, z, pointNum;
} intStruct;

void displaying(FILE *f, intStruct *iS){
    
    int g, h, j;
    
    if (iS->pointNum == 1){
        f = fopen("001.txt", "r");
        if (f == NULL)
            printf("fopen read error");
        else {
            fscanf(f, "%d", &g);
            fscanf(f, "%d", &h);
            fscanf(f, "%d", &j);
            printf("%d\n", g);
            printf("%d\n", h);
            printf("%d\n", j);
        }
        fclose(f);
    }

    if (iS->pointNum == 2){
        f = fopen("002.txt", "r");
        if (f == NULL)
            printf("fopen read error");
        else {
            fscanf(f, "%d", &g);
            fscanf(f, "%d", &h);
            fscanf(f, "%d", &j);
            printf("%d\n", g);
            printf("%d\n", h);
            printf("%d\n", j);
        }
        fclose(f);
    }
}

void firstPoint(FILE *f, intStruct *iS){
    iS->pointNum = 1;
    f = fopen("001.txt", "w");
        fprintf(f, "%d\n", a);
        fprintf(f, "%d\n", b);
        fprintf(f, "%d\n", c);
    fclose(f);
    
    displaying(f, iS);

    system("pause");
}

void secondPoint(FILE *f, intStruct *iS){
    iS->x = a + 2;
    iS->y = b + 2;
    iS->z = c + 2;
    iS->pointNum = 2;
    f = fopen("002.txt", "w");
        fprintf(f, "%d\n", iS->x);
        fprintf(f, "%d\n", iS->y);
        fprintf(f, "%d\n", iS->z);
    fclose(f);

    //system("cls");

    displaying(f, iS);

    system("pause");
};

int main(){

    FILE *f;
    intStruct iS;

    //firstPoint(f, &iS);

    secondPoint(f, &iS);


    system("pause");
    return 0;
}