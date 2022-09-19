/*Запрос у пользователя символов 'Y' или 'N'. На основе этого запускается ветка с system("pause") либо заканчивается программа*/

#include <stdio.h>
#include <conio.h>

int main() {

    char answer[1];
    printf("Pause the programm?\nenter Y or N \n-> ");
    scanf("%s", answer);
    while ( answer[0] != 'Y'){
        printf("Yor enter is %s\nAnswer is incorrect\nenter Y or N \n-> ", answer);
        scanf("%s", answer);
        if (answer[0] == 'Y' || answer[0] == 'N'){
            break;
        }
    }


    if (answer[0] == 'Y') {
        printf("You have chosen to pause\n");
        system("pause");
	    return 0; 
    }

    else {
        return 0;
    }

}