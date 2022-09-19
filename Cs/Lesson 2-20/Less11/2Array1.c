//1) Показать на экране таблицу умножения от 1 до 9 с помощью двумерного массива
#include <stdio.h>
#include <stdlib.h>

int main(){

    int i,k;
    int m[9][9];
    for (k = 0; k < 9; k++) {
        for ( i = 0; i < 9; i++) {
            m[k][i] = (k + 1) * (i +1);
            printf("%d\t", m[k][i]);
        }
        
        printf("\n");
    }
    
    system("pause");
    return 0;
}