/*1) Запишите в файл 10 любых строк текста. Проверьте правильность записи с помощью любого редактора.
2) Прочитайте все строки из файла из задания 1 и отобразите на экране.
Измените файл с помощью любого редактора, добавив или удалив строки, и снова прочитайте его с помощью программы.
3) С помощью любого редактора создайте файл и запишите в него 5 чисел.
Считайте все числа из файла удвойте их значение и отобразите на экране.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MasLenght 10

char arr1[MasLenght+1][MasLenght];

void filingArr(){
    int rn;
    srand(time(NULL));
    for (int i=0; i <MasLenght; i++){
        rn = (rand() % 8 + 1);
        for ( int j = 0; j < rn+1; j++){
            if (j > rn)
                arr1[i][j] = '\0';
            else{
                arr1[i][j] = rand()%(122-97+1) + 97;
            }
        }
    }
}

void displaying(FILE *f){
    f = fopen("001.txt", "r");
    if (f == NULL)
        printf("fopen read error");
    else {
        for (int i = 0; i < MasLenght; i++) {
            fscanf(f, "%s", arr1[i]);
            printf("%s\n", arr1[i]);
        }
    }
    fclose(f);
}

void firstPoint(FILE *f){
    filingArr();
    f = fopen("001.txt", "w");
        for (int i = 0; i < MasLenght; i++) {
            fprintf(f, "%s\n", arr1[i]);
        }
    fclose(f);

    printf("The '001.txt' file contains 10 lines of text. Check the correctness of the entry in any text editor and go further.\n");
    system("pause");
}

void secondPoint(FILE *f){
    system("cls");
    displaying(f);

    printf("The contents of the '001.txt' file are displayed on the screen.\nOpen this file in any text editor and change its contents. Then press any key.\n");
    system("pause");

    displaying(f);
    printf("Compare the values\n");
    system("pause");
}

void thirdPoint(FILE *f){
    char name[20];
    float a;
    printf("Use any editor to create a text file and write some numbers into it.\nWrite down each number from a new line.\nEnter the name of the text file in the 'name.txt' format:");
    scanf("%s", name);
    f = fopen(name, "r");
    if (f == NULL)
        printf("fopen read error");
    else {
        for (int i = 0; i < 5; i++) {      
            fscanf(f, "%g", &a);
            printf("%g\n", a*2);
        }
    }
    fclose(f);
    system("pause");
}

int main(){

    FILE *f;
    int tn;

    printf("Enter numper task:");
    scanf("%d", &tn);

    switch (tn)
    {
    case 1:
        firstPoint(f);
        break;
    case 2:
        secondPoint(f);
        break;
    case 3:
        thirdPoint(f);
        break;
    
    default: printf("incorrect number");
        break;
    }

    return 0;
}