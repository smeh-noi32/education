/*Создание строки длинной 8 символов и заполнение её символом '#', при помощи цикла. Отображение результата
на экране.
Посимвольное отображение на экране строки при помощи любого цикла*/

#include <stdio.h>
#include <conio.h>

int main(){

    int i, j =0; 
    char str[9];

    for ( i=0; i < 8; i++){
        str[i] = '#';
    }
    
    printf("String ' %s '\n", str);

    while (j < 8)
    {
        printf("Symbol '%c' of the string\n", str[j]);
        j++;
    }
    
    system("pause");
    return 0;
}