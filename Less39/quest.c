/*
Игра квест
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define width 80
#define height 25

struct {
    char map[height][width+1];
} loc;

void loc_LoadFromFile(char *fileName) {
    memset(&loc.map, ' ', sizeof(loc));
    for (int i = 0; i < height; i++) {
        loc.map[i][width] = '\0';
    }

    FILE *f = fopen(fileName, "r");
    char c[80];
    int line = 0;
    while(!feof(f)){
        fgets(c, width, f);
        int cnt = strlen(c);
        if (c[cnt-1] == '\n') cnt--;
        strcpy(loc.map[line], c, cnt);
        line++;
    }
    fclose(f);

    loc.map[height-1][width-1] = '\0';
}

char map[height][width+1];

void map_Show() {
    for (int i = 0; i < height; i++) {
        printf("%s\n", loc.map[i]);
    }
}

void loc_PutOnMap () {
    memcpy(map, loc.map, sizeof(map));
}

int main () {
    loc_LoadFromFile("map_0_0.txt");
    map_Show();

    return 0;
}