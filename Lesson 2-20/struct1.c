/*Создание структуры, описывающую предмет интерьера. Включает в себя 3 измерения
(длина, высота, ширина), название предмета в виде строки длиной 50 символов и цвет.
Создание перемнной для этой структуры любым из трёх способов и заполнение всех полей.
После чего отображение на экран.

Создание массива структур из предыдущего задания. Размер массива 3 элемента. 
Заполнение всех полей каждой структуры и вывод на экран при помощи цикла.*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct InteriorElement {
    float length, height, width;
    char title[51], color[16];
} fur;

//typedef struct InteriorElement IE;  //Возможный вариант написания, тоже работает корректно

void input(fur *s){
    printf("Enter Title Interior Element: ");
    scanf("%s", s->title);
    printf("Enter color: ");
    scanf("%s", s->color);
    printf("Enter length: ");
    scanf("%f", &s->length);
    printf("Enter height: ");
    scanf("%f", &s->height);    
    printf("Enter width: ");
    scanf("%f", &s->width);
}

void output(fur s){
    printf("%s\n", s.title);
    printf("Color: %s\n", s.color);
    printf("Length: %.2f\n", s.length);
    printf("Height: %.2f\n", s.height);
    printf("Width: %.5f\n", s.width);
}

int main(){

    fur a_fur;
    input(&a_fur);
    output(a_fur);
    
    system("pause");
    return 0;
}