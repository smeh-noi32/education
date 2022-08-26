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

void displaying(FILE *f){        //Фунуция считывания и отображения переменных из файла
    
    int g, h, j;
    char v[20], q[20], e[20];
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

        printf("%d  \n%d  \n%d\n", g, h, j);
        
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

        printf("%s\n%g\n%s\n", v, k, e);

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

    //system("cls");

    displaying(f);

    system("pause");
};

void thirdPoint(FILE *f){
    pointNum = 3;

    Third anyType;

    printf("Enter integer: ");
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

int main(){

    FILE *f;
    intStruct iS;

    //firstPoint(f);

    //secondPoint(f);

    thirdPoint(f);

    system("pause");
    return 0;
}