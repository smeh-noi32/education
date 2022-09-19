/*
1) Запишите в файл несколько переменных целого типа, а затем отобразите их на экране.
2) Выполните пункт 1, но вместо целого типа используйте структуру.
3) Запишите в файл и прочитайте несколько переменных разных типов подряд.
4) Попробуйте записать в файл и прочитать структуру, одним из полей которой будет другая структура.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a = 5, b = 6, c = 7, pointNum;

typedef struct {
    int x, y, z;
} intStruct;

typedef struct{
    int u;
    float o;
    char n[20];
} Third;

typedef struct {
    char alfa[20];
    intStruct beta;
} fourth;

void displaying(FILE *f){        //Фунуция считывания и отображения переменных из файла
    
    int g, h, j;
    char v[20], q[20], e[20], gamma[20];
    float k;
    
    if (pointNum == 1){
        f = fopen("001.txt", "r");
        if (f == NULL)
            printf("fopen read error");
        else {
            fread(&g, sizeof(g), 1, f);
            fread(&h, sizeof(h), 1, f);
            fread(&j, sizeof(j), 1, f);
        }
        fclose(f);

        printf("%d  \n%d  \n%d\n", g, h, j);

    }

    if (pointNum == 2){
        f = fopen("002.txt", "r");
        if (f == NULL)
            printf("fopen read error");
        else {
            fread(&g, sizeof(g), 1, f);
            fread(&h, sizeof(h), 1, f);
            fread(&j, sizeof(j), 1, f);
        }
        fclose(f);

        printf("\n%d  \n%d  \n%d\n", g, h, j);
        
    }

    if (pointNum == 3){
        f = fopen("003.txt", "r");
        if (f == NULL)
            printf("fopen read error");
        else {
            fread(&g, sizeof(g), 1, f);
            fread(&k, sizeof(k), 1, f);
            fread(e, sizeof(e), 1, f);
        }
        fclose(f);

        itoa(g, v, 10);

        printf("\n%s\n%g\n%s\n", v, k, e);

    }

    if (pointNum == 4){

        f = fopen("004.txt", "r");
        if (f == NULL)
            printf("fopen read error");
        else {
            fread(gamma, sizeof(gamma), 1, f);
            fread(&g, sizeof(g), 1, f);
            fread(&h, sizeof(h), 1, f);
            fread(&j, sizeof(j), 1, f);
        }
        fclose(f);

        itoa(g, v, 10);
        itoa(h, q, 10);
        itoa(j, e, 10);

        printf("\n%s\n%s\n%s\n%s\n", gamma, v, q, e);

    }
}

void firstPoint(FILE *f){
    pointNum = 1;
    f = fopen("001.txt", "w");
        fwrite(&a, sizeof(a), 1, f);
        fwrite(&b, sizeof(b), 1, f);
        fwrite(&c, sizeof(c), 1, f);
    fclose(f);
    
    displaying(f);

    system("pause");
}

void secondPoint(FILE *f){
    intStruct iS = {a + 2, b + 2, c + 2};

    pointNum = 2;
    f = fopen("002.txt", "w");
        fwrite(&iS, sizeof(iS), 1, f);
    fclose(f);

    displaying(f);

    system("pause");
};

void thirdPoint(FILE *f){
    pointNum = 3;

    Third anyType;

    printf("\nEnter integer: ");
    scanf("%d", &anyType.u);
    printf("Enter float: ");
    scanf("%f", &anyType.o);
    printf("Enter char: ");
    scanf("%s", anyType.n);
    
    f = fopen("003.txt", "w");
        fwrite(&anyType, sizeof(anyType), 1, f);
    fclose(f);

    displaying(f);

    system("pause");
};

void fourthPoint (FILE *f) {
    pointNum = 4;

    fourth call4;

    call4.beta.x = a + 4;
    call4.beta.y = b + 4;
    call4.beta.z = c + 4;

    printf("\nEnter char: ");
    scanf("%s", call4.alfa);
    
    f = fopen("004.txt", "w");
        fwrite(&call4, sizeof(call4), 1, f);
    fclose(f);

    displaying(f);

    system("pause");
};

int main(){

    FILE *f;
    intStruct iS;

    firstPoint(f);

    secondPoint(f);

    thirdPoint(f);

    fourthPoint(f);
    
    system("pause");
    return 0;
}