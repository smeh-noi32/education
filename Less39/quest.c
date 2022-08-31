/*
Игра квест
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define width 80
#define height 25

struct {                            //Структура данных о локации
    char map[height][width+1];
} loc;

void loc_LoadFromFile(char *fileName) {     //Процедура загрузки в локацию информации из файла
    memset(&loc.map, ' ', sizeof(loc));     //Заполнение матрицы map символом пробела
    for (int i = 0; i < height; i++) {      //Заполнение последнего столбца символом конца строки
        loc.map[i][width] = '\0';
    }

    FILE *f = fopen(fileName, "r");     //Открытие файла на чтение
    char c[80];     //переменная хранящая текущую строку заполенеия локации
    int line = 0;   //Заполнение начинается с нулевой строки
    while(!feof(f)){        //Читаем кажду строку, пока файл не кончится
        fgets(c, width, f);
        int cnt = strlen(c);        //длина строки без символа конца строки
        if (c[cnt-1] == '\n') cnt--;        //Если в конце строки стоит символ перевода строки, то уменьшаем длину на 1
        strncpy(loc.map[line], c, cnt);      //Копируем все в текущую строку локации
        line++;                             //Переход на следущую строку
    }
    fclose(f);

    loc.map[height-1][width-1] = '\0';      //Последний символ последний строки заполняем символом конца строки, чтобы курсор не переходил на следуюшую строку
}

char map[height][width+1];      //массив хранящий карту

void map_Show() {       //Процедура отображения карты на экране
    for (int i = 0; i < height; i++) {
        printf("%s\n", loc.map[i]);
    }
}

void loc_PutOnMap () {      //Процедура копирования локации перед отображением
    memcpy(map, loc.map, sizeof(map));      //Копирование всех байтов из источника (loc.map) в приёмник (map)
}

struct {
    POINT pos;
} player;

void player_Init (int x, int y) {
    player.pos.x = x;
    player.pos.y = y;
}

void player_PutOnMap(){
    map[player.pos.y][player.pos.x] = 'A';
}

int main () {

    player_Init(5,5);
    loc_LoadFromFile("map_0_0.txt");
    loc_PutOnMap();
    player_PutOnMap();
    map_Show();

    system("pause");
    return 0;
}