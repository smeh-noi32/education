/*
2) Создание массива структур из предыдущего задания. Размер массива 3 элемента. 
Заполнение всех полей каждой структуры и вывод на экран при помощи цикла.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct InteriorElement {
    float length, height, width;
    char title[51], color[16];
} fur;

fur input(fur s){
    fur tmp = s;
    printf("Enter Title Interior Element: ");
    scanf("%s", tmp.title);
    printf("Enter color: ");
    scanf("%s", tmp.color);
    printf("Enter length: ");
    scanf("%f", &tmp.length);
    printf("Enter height: ");
    scanf("%f", &tmp.height);    
    printf("Enter width: ");
    scanf("%f", &tmp.width);
    return tmp;
}

fur output(fur s){
    fur tmr = s;
    printf("%s\n", tmr.title);
    printf("Color: %s\n", tmr.color);
    printf("Length: %.2f\n", tmr.length);
    printf("Height: %.2f\n", tmr.height);
    printf("Width: %.5f\n", tmr.width);
    return tmr;
}

int main(){

    fur a_fur[3];
    int i;

    for (i = 0; i < 3; i++){
        a_fur[i] = input(a_fur[i]);
        printf("\n");
    }

    for (i = 0; i < 3; i++){
        a_fur[i] = output(a_fur[i]);
        printf("\n");
    }
    
    system("pause");
    return 0;
}