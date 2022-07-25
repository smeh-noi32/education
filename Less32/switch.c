#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randFilm(){
    srand(time(NULL));
    int k;
    k = rand()%(10 - 7+1) + 7;
    switch (k){
    case 9:
        printf("SKALA\n");
        break;
    case 8:
        printf("Master\n");
        break;
    case 7:
        printf("300\n");
        break;
    default:
        printf("you are not worthy!\n");
        break;
    }
}

int main(){

    randFilm();
    system("pause");
    return 0;
}