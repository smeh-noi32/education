/*
Создайте массив целых чисел из 5 элементов и запишите в файл, открытый в текстовом режиме.
После чего прочитайте и отобразите на экране.
Замените средний элемент на значение "26" и запустите программу.
Откройте файл в бинарном режиме и запустите ещё раз.
*/
#include <stdio.h>
#include <stdlib.h>

#define name "01.txt"

char integ[5] = "56819";
char strin[10] = "";

void write(FILE *f){
    f = fopen( name, "w");
        fprintf(f, integ);
    fclose(f);
}

void read(FILE *f){
    f = fopen( name, "r");
        fread(strin, sizeof(strin), 1, f);
    fclose(f);
}

void writeBinary(FILE *f){
    f = fopen( name, "wb");
        fprintf(f, integ);
    fclose(f);
}

void readBinary(FILE *f){
    f = fopen( name, "rb");
        fread(strin, sizeof(strin), 1, f);
    fclose(f);
}

int main(){

    FILE *f;

    //write(f);

    read(f);

    for (int i = 0; i < 10; i++)
        printf("%d\n", strin[i]);

    system("pause");

    integ[2] = 26;

    writeBinary(f);

    readBinary(f);

    for (int i = 0; i < 10; i++)
        printf("%d\n", strin[i]);

    system("pause");
    return 0;
}