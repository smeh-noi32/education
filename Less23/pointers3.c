/*Добавьте в структуру еще одну любую переменную. в процедуре ShowPoint добавьте вывод 
новой переменной на экран. Добавьте в процедуру SetPoint входной параметр такого же типа
и с помощью него заполните новую переменную  в структуре.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    char z[10];
} TPoint;

void ShowPoint(TPoint point){
    printf("x = %d    y = %d    z = %s\n", point.x, point.y, point.z);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", point.z[i]);
    }
    
}

void SetPoint(TPoint *pointPtr, int xPos, int yPos, char zStr[10]){
    if (pointPtr != NULL){
        (*pointPtr).x = xPos;
        (*pointPtr).y = yPos;
        for (int i= 0; i<10; i++){
            (*pointPtr).z[i] = zStr[i];
        }
    }
}

void characterEnter(TPoint *ent){
    int b;
    char bS[10];
    printf("Enter parameter x: ");
    scanf("%d", &b);
    (*ent).x = b;

    printf("Enter parameter y: ");
    scanf("%d", &b);
    (*ent).y = b;

    printf("Enter parameter z: ");
    scanf("%s", &bS);
    strcpy((*ent).z, &bS[10]);
}

int main(){
    TPoint p;
    TPoint *pPtr = NULL;

    pPtr = &p;

    SetPoint(pPtr, 11, 22, "trololo");
    characterEnter(pPtr);
    ShowPoint(*pPtr);

    system("pause");
    return 0;
}