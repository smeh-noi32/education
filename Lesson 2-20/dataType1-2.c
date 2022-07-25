#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int i;
    char str[21], ans[1];
    bool input = true;

    while(input) {
        printf("Run program 1 or 2?\nAnswer: ");
        scanf("%s", ans);
        if (ans[0] == '1' || ans[0] == '2')
            input = false;
    }


    for (i = 0; i < 20; i++){
        (ans[0] == '1') ? (str[i] = rand()) : (str[i] = rand()%(122-97+1) + 97);
        printf("%c %d\n", str[i], i);
    }

    system("pause");
    return 0;
}