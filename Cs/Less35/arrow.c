/*1)Создайте массив вещественных чисел. Проинициализируйте его и отобразите на экране.
2) Создайте массив строк, проинициализируйте его и отобразите.
3) Создайте структуру с двумя полями - "Имя" и "Рост".
Создайте обычный тип для данной структуры. Создайте переменную этого типа и проинициализируйте структуру после чего выведите на экран.
Создайте тип данных указатель для этой структуры. С его помощью поменяйте значения полей.
4) Создайте массив структур из задания 3, проинициализируйте его и отобразите на экране.
5) Создайте процедуру, которая будет инициализировать структуру из задания 3. С её помощью измените значение ячеек массива из задания 4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MasLenght 10

float n, arr[MasLenght+1];
char arr1[MasLenght+1][MasLenght];

typedef struct {
    char Name[20];
    int height;
} Params;


void firstPoint(){
    printf("First task\n");

    srand(time(NULL));
    for (int i=0; i <MasLenght; i++){
        n = (rand() % 100);
        arr[i] = n / 0.23 * 0.15;
        printf("%g\n", arr[i]);
    }
}

void secondPoint(){
    printf("\nSecond task\n");

    int rn;
    srand(time(NULL));
    for (int i=0; i <MasLenght; i++){
        rn = (rand() % 5 + 1);
        for ( int j = 0; j < rn+1; j++){
            if (j > rn)
                arr1[i][j] = '\0';
            else{
                arr1[i][j] = rand()%(122-97+1) + 97;
                printf("%c ",arr1[i][j]);
            }
        }

        printf("\n");
    }
}

void structPoint(Params *p){
    printf("\nThird task\nEnter Name: ");
    scanf("%s", p->Name);
    printf("Enter Height: ");
    scanf("%d", &p->height); 

    printf("Name: %s \nHeight: %d\n\n", p->Name, p->height);
}

void endPoint(Params *pp){
    printf("Recent tasks\n");

    pp[MasLenght];
    for (int i = 0; i < MasLenght; i++) {
        strcpy(pp[i].Name, arr1[i]);
        pp[i].height = arr[i];
        printf("Name: %s Height: %d\n", pp[i].Name, (int)round(pp[i].height));
    }
    
}

int main() {

    Params *Pms;
    
    firstPoint();
    secondPoint();
    structPoint(&Pms);
    endPoint(&Pms);

    system("pause");
    return 0;
}