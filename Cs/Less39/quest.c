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
    POINT sz;
} loc;

void loc_LoadFromFile(char *fileName) {     //Процедура загрузки в локацию информации из файла
    memset(&loc.map, ' ', sizeof(loc));     //Заполнение матрицы map символом пробела
    for (int i = 0; i < height; i++) {      //Заполнение последнего столбца символом конца строки
        loc.map[i][width] = '\0';
    }

    FILE *f = fopen(fileName, "r");     //Открытие файла на чтение
    char c[80];     //переменная хранящая текущую строку заполенеия локации
    int line = 0;   //Заполнение начинается с нулевой строки
    loc.sz.x = 0;
    loc.sz.y = 0;
    while(!feof(f)){        //Читаем кажду строку, пока файл не кончится
        fgets(c, width, f);
        int cnt = strlen(c);        //длина строки без символа конца строки
        if (c[cnt-1] == '\n') cnt--;        //Если в конце строки стоит символ перевода строки, то уменьшаем длину на 1
        strncpy(loc.map[line], c, cnt);      //Копируем все в текущую строку локации
        line++;                             //Переход на следущую строку
        if ( cnt > loc.sz.x) loc.sz.x = cnt;        
    }
    loc.sz.y = line;
    fclose(f);

    loc.map[height-1][width-1] = '\0';      //Последний символ последний строки заполняем символом конца строки, чтобы курсор не переходил на следуюшую строку
}

void setCurPos (){
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition ( GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char map[height][width+1];      //массив хранящий карту

void map_Show() {       //Процедура отображения карты на экране
    setCurPos();
    for (int i = 0; i < height; i++) {
        printf("%s\n", map[i]);
    }
}

void loc_PutOnMap () {      //Процедура копирования локации перед отображением
    memcpy(map, loc.map, sizeof(map));      //Копирование всех байтов из источника (loc.map) в приёмник (map)
}

struct {
    char name[20];
    POINT pos;
    POINT locPos;
} player;

void player_Init (int xLoc, int yLoc, int x, int y, char *name) {
    player.pos.x = x;
    player.pos.y = y;
    sprintf(player.name, name);
    player.locPos.x = xLoc;
    player.locPos.y = yLoc;
}

void player_PutOnMap(){
    map[player.pos.y][player.pos.x] = 'A';
}

void player_Control(){
    POINT old = player.pos;
    if (GetKeyState('W') < 0) player.pos.y--;
    if (GetKeyState('S') < 0) player.pos.y++;
    if (GetKeyState('A') < 0) player.pos.x--;
    if (GetKeyState('D') < 0) player.pos.x++;
    if (map[player.pos.y][player.pos.x] !=' ')
        player.pos = old;

    if (player.pos.x > loc.sz.x -2) {
        player.locPos.x++;
        player_LoadLocation();
        player.pos.x = 1;
    }

    if (player.pos.x < 1){
        player.locPos.x--;
        player_LoadLocation();
        player.pos.x = loc.sz.x -2;
    }

    if (player.pos.y > loc.sz.y -2) {
        player.locPos.y++;
        player_LoadLocation();
        player.pos.y = 1;
    }

    if (player.pos.y < 1){
        player.locPos.y--;
        player_LoadLocation();
        player.pos.y = loc.sz.y -2;
    }
}

void player_Save(){
    FILE *f = fopen(player.name, "wb");
        fwrite(&player, sizeof(player), 1, f);
    fclose(f);
}

void player_Load(char *name){
    FILE *f = fopen(name, "rb");
        if ( f == NULL)
            player_Init(0, 0, 5, 5, name);
        else 
            fread(&player, sizeof(player), 1, f);
    fclose(f);
}

void player_LoadLocation(){
    char c[100];
    sprintf(c, "map_%d_%d.txt", player.locPos.x, player.locPos.y);
    loc_LoadFromFile(c);
}

int main () {

    player_Load("Victor");
    player_LoadLocation();
    
    do {
        player_Control();
        loc_PutOnMap();
        player_PutOnMap();
        map_Show();
        Sleep(50);
    } while (GetKeyState(VK_ESCAPE) >= 0);
    
    player_Save();

    system("pause");
    return 0;
}