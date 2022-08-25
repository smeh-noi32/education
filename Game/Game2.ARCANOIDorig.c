#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define _USE_MATH_DEFINES

#include <math.h>

#define width 65
#define height 25

typedef struct { //Создание структуры для ракетки
    int x,y;
    int w;
} TRacket;

typedef struct { //Создание структуры для мячика
    float x, y;
    int ix, iy;
    float alfa;
    float speed;
} TBall;

char mas[height][width+1]; //Объявление массива игрового поля
char c[1];
TRacket racket;
TBall ball;
int hitCnt = 0;
int maxHitCnt = 0;

void initBall(){    //Создание мячика
    ball.alfa = -1;
    ball.speed = 0.5;
}


void putBall(){     //Помещение мячика в игровое поле
    mas[ball.iy][ball.ix] = '*';
}


void moveBall(float x, float y){        //Функция перемещения мячика в игровом поле
    ball.x = x;
    ball.y = y;
    ball.ix = (int)round(ball.x);
    ball.iy = (int)round(ball.y);
}


void autoMoveBall (){    //Изменяет координаты X и Y мячика в зависимости от угла и скорости
    if(ball.alfa < 0) ball.alfa += M_PI*2;
    if(ball.alfa > M_PI*2) ball.alfa -= M_PI*2;     //Приводим угол альфа к виду от 0 до 2Пи
    
    TBall bl = ball;        //Перед перемещением сохраняем значение мячика

    moveBall(ball.x+cos(ball.alfa)*ball.speed
            ,ball.y+sin(ball.alfa)*ball.speed);     //Выполняем перемещение мячика

    if ((mas[ball.iy][ball.ix] == '#') || (mas[ball.iy][ball.ix] == '@')){   //Проверка на столкновение шарика либо со стеной, либо с ракеткой
        if(mas[ball.iy][ball.ix] == '@')    //Если мячик отразился от ракетки
            hitCnt++;                       //увеличиваем значение пеемнной 
        if ((ball.ix != bl.ix) && (ball.iy != bl.iy)){      //Сравниваем новое положение мячика со старым
            
            if(mas[bl.iy][ball.ix] == mas[ball.iy][bl.ix])  //Проверка на столкновение с углом. (Если старый Y и новый X == новый Y и старый X)
                bl.alfa = bl.alfa + M_PI;       //Инвертирование направления движения мячика
            else {                              //Проверка на столкновение со стеной либо потоком
                if (mas[bl.iy][ball.ix] == '#') //Старый У и новый Х это стена, то это вертикальная поверхность и отражаем по вертикали
                    bl.alfa = (2*M_PI - bl.alfa) + M_PI;
                else
                    bl.alfa = (2*M_PI - bl.alfa);   //Отражение по горизонтали
            }
        }

        else if (ball.iy == bl.iy)      //Проверка изменения координаты Y
            bl.alfa = (2* M_PI - bl.alfa) + M_PI;   //Отражение мячика по вертикали
        else                            //В противном случае Х не изменился
            bl.alfa = (2* M_PI - bl.alfa);          //Отражение мячика по горизонтали
        
        ball = bl;      //Возвращаем координаты
        autoMoveBall(); //Заново запускаем пересчёт координат мячика
    }
}

void initRacket(){  //Создание ракетки
    racket.w = 7;
    racket.x = (width - racket.w)/2;
    racket.y = height - 1;
}

void putRacket(){   //Помещение ракетки в игровое поле
    for (int i = racket.x; i < racket.x + racket.w; i++)
        mas[racket.y][i] = '@';
}

void init(){
    
    for (int i= 0; i < width; i++){ //Заполнили нулевую строку '#'
        mas[0][i] = '#';
    }
    mas[0][width] = '\0';           //Добавление символа конца строки

    strncpy(mas[1], mas[0], width+1); //Копирование нулевой строки в первую
    for (int i=1; i<width-1; i++){      //Заполнение поля символами ' ', кроме первого и последнего символа
        mas[1][i] = ' ';
    }

    for (int i = 2; i < height; i++){   //Копируем предыдущую строку во все остальные строки
        strncpy(mas[i], mas[1], width+1);
    }
}

void show(){                            //Отображение игрового поля и резултатов
    for (int i = 0; i < height; i++) {  //построчное отображение строк
        printf("%s", mas[i]);
        if(i == 3)
            printf("       hit %i ", hitCnt);   //отображение на третьей строке текущегоо результата
        if(i == 4)
            printf("       max %i ", maxHitCnt);    //Отображение на четвертой строке максимального результата
        if(i == 13)
            printf("  Press 'W' to move Ball  ");
        if(i == 14)
            printf("  'A' for left,'D' for right ");
        if(i == 24)
            printf("  Press 'esc' to exit  ");
        if(i < height - 1)  //Помещаем символ перевода строки на всех строках, кроме последней
            printf("\n");
    }  
}

void moveRacket (int x) {   //функция перемещения ракетки внутри поля
    racket.x = x;
    if (racket.x < 1)                       //Если ракетка выходит за пределы поля,
        racket.x = 1;                       //то возвращаем её обратно
    if (racket.x + racket.w >= width)
        racket.x = width-1 - racket.w;
}

void setcur(int x, int y) {     //Функция, переносящая курсор в заданные координаты, в данном случае, в левый верхний угол консоли
    COORD coord;                //В данном случае используем для утображения строк поверх старых
    coord.X = x;                //для уменьшения мигания. (COORD - тип, являющийся структурой)
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);   //STD_OUTPUT_HANDLE - указатель на наше окно
}

int main() {

    BOOL run = FALSE;   //проверка запуска мячика (False = мячик привязан к ракетке. True = мячик двигается автоматически)
    initRacket();
    initBall();
    
    do {
        setcur(0,0);

        if (run)
            autoMoveBall();
        if (ball.iy > height-2) {   //проверка выхода мячика за пределы нижней границы поля
            run = FALSE;
            if (hitCnt > maxHitCnt) //запись текущего резултата в максимальный, в случае его превышения
                maxHitCnt = hitCnt;
            hitCnt = 0;
        }

        init();
        putRacket();
        putBall();
        show();
        if (GetKeyState('A') < 0) moveRacket(racket.x - 1);     //
        if (GetKeyState('D') < 0) moveRacket(racket.x + 1);     //Проверка нажатия клавиши
        if (GetKeyState('W') < 0) run = TRUE;                   //
        if (!run)
            moveBall(racket.x + racket.w/2, racket.y -1);   //Помещяем мячик в центре ракетки, на одну клеточку вверх
        Sleep(10);
    } while (GetKeyState(VK_ESCAPE) >= 0);  //выход из цикла и из программы по нажатию ESC

    return 0;
}