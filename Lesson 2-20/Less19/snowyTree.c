#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define h 25
#define w 80

char mas[h][w+1];

void init()
{
    for (int i = 0; i < w; i++)
        mas[0][i] = ' ';
    mas[0][w] = '\0';
    for (int i = 1; i < h; i++)
        sprintf(mas[i], mas[0]);
}

void putTree()
{
    mas[h-1][w-40] = '&';
    mas[h-2][w-40] = '&';
    for (int i = w - 46; i < (w - 46 + 13); i++)
        mas[h-3][i] = '#';
    for (int i = w - 45; i < (w - 45 + 11); i++)
        mas[h-4][i] = '#';
    for (int i = w - 44; i < (w - 44 + 9); i++)
        mas[h-5][i] = '#';
    for (int i = w - 43; i < (w - 43 + 7); i++)
        mas[h-6][i] = '#';
    for (int i = w - 42; i < (w - 42 + 5); i++)
        mas[h-7][i] = '#';
    for (int i = w - 41; i < (w - 41 + 3); i++)
        mas[h-8][i] = '#';
    for (int i = w - 40; i < (w - 40 + 1); i++)
        mas[h-9][i] = '#';
    if (mas[h-1][w-47] == '_')
        for (int i = w - 46; i < (w - 46 + 2); i++)
            mas[h-1][i] = '_';
    if (mas[h-1][w-32] == '_')
        for (int i = w - 35; i < (w - 33); i++)
            mas[h-1][i] = '_';
}

void show()
{
    mas[h-1][w-1] = '\0';
    for (int i = 0; i < h; i++)
        printf("%s\n", mas[i]);
}

void newSnow()
{
    for (int i = 0; i < w; i++)
        if (rand() % 35 == 1)
            mas[0][i] = '*';
}

void moveSnow()
{
    int dx;
    for (int j = h - 1; j >= 0; j--)
        for (int i = 0; i < w; i++)
            if (mas[j][i] == '*')
            {
                dx = 0;
                if(mas[j][i] != '_')
                    mas[j][i] = ' ';
                if (rand() % 10 < 1) dx++;
                if (rand() % 10 < 1) dx--;
                dx += i;
                if ((dx >= 0) && (dx < w) && (j + 1 < h-1))
                    mas[j+1][dx] = '*';
            }
}

void snowOnGround()
{
    for (int i = 0; i < w; i++)
    {
        if (mas[h-2][i] == '*')
            mas[h-1][i] = '_';
        if (mas[h-1][i] == '_' && mas[h-1][i+1] == '_')
            mas[h-1][i] = '-';
        if (mas[h-1][i] == '-' && mas[h-1][i+1] == '-')
            mas[h-1][i] = '~';
        if (mas[h-1][i] == '~' && mas[h-1][i+1] == '~')
            mas[h-1][i] = '=';
    }
}

void setCur(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    init();
    do
    {
        setCur(0, 0);
        moveSnow();
        newSnow();
        putTree();
        snowOnGround();
        show();
        Sleep(120);
    }
    while (GetKeyState(VK_ESCAPE) >= 0);

    return 0;
}