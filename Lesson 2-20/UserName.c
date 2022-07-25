#include <stdio.h>
#include <conio.h>

/*Запрос имени и Фамилии у пользователя, с последующим выводом их на экран*/

int main() {

      char name[15];
      char fam[20];
      printf("Your name?\n");
      printf("enter yor first and last Name and press Enter\n");
      printf("->");
      scanf("%s",&name);
      scanf("%s",&fam);
      printf("Hello, %s %s!\n",name,fam);
      printf("\npress Enter to close");
      getch();
      
   }