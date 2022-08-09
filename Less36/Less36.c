/*1) Запишите в файл 10 любых строк текста. Проверьте правильность записи с помощью любого редактора.
2) Прочитайте все строки из файла из задания 1 и отобразите на экране.
Измените файл с помощью любого редактора, добавив или удалив строки, и снова прочитайте его с помощью программы.
3) С помощью любого редактора создайте файл и запишите в него несколько чисел.
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

int main(){

    FILE *f;
    int d;
    float a;

    filingArr();

    f = fopen("001.txt", "w");
        for (int i = 0; i < MasLenght; i++) {
            fprintf(f, "%s\n", arr1[i]);
        }
    fclose(f);

    f = fopen("001.txt", "r");
    if (f == NULL)
        printf("fopen read error");
    else {
        for (int i = 0; i < MasLenght; i++) {
            fscanf(f, "%s", arr1[i]);
            printf("%s\n", arr1[i]);
        }
        /*
        fscanf(f, "%d", &d);
        fscanf(f, "%g", &a);
        printf("%d   %g\n", d, a);
        */
    }
    fclose(f);

    system("pause");
    return 0;
}