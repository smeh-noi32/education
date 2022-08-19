//2) Вывыод на экран двумерного массива со значением "5" в пятой строке и значением "3" в третьем столбце
#include <stdio.h>
#include <stdlib.h>

int main(){

    int i,k;
    int m[9][9];
    for (k = 0; k < 9; k++) {
        for ( i = 0; i < 9; i++) {
            
            m[k][i] = 1;
            
            if (k == 4){
                m[k][i] = 5;
            }

            if (i == 2){
                m[k][i] = 3;
            }

            m[4][2] = 15;
            printf("%d\t", m[k][i]);

        }
        
        printf("\n");
    }
    
    system("pause");
    return 0;
}