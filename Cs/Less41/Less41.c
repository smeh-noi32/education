/*
1)Откройте файл на запись и чтение и запишите туда 5 символов. 
Прочитайте все символы начиная с третьего и отобразите их на экране.
2) Откройте файл из задания 1 на добавление и запишите ещё 2 символа.
Прочитайте последние три символа из файла и отобразите на экране.
*/

#include <stdio.h>
#include <stdlib.h>

#define fName "filePLUS.txt"

void firstTask (FILE *f){
    f = fopen( fName, "w+");
        fprintf(f, "aZp5|");

        char buf[20];
        fseek(f, 2, SEEK_SET);
        if (fgets( buf, 20, f) != NULL)
            printf("%s\n", buf);
        
    fclose(f);
}

void secondTask (FILE *f) {
    f = fopen(fName, "a+");
        fprintf(f, "++");

        char buf2[20];
        fseek(f, 4, SEEK_SET);
        if (fgets( buf2, 20, f) != NULL)
            printf("%s\n", buf2);
    fclose(f);
}

int main (){
    
    FILE *f;

    firstTask(f);

    secondTask(f);

    system("pause");
    return 0;
}