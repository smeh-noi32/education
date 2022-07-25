#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define mapWidth 80         //указание размеров карты Ширина
#define mapHeight 25        //Высота

typedef struct {        //Структура хранящая параметры персонажа
    float x, y;         //Координаты
    float width, height;//Размер
    float vertSpeed;    //Скорость по вертикали
    BOOL isFly;         //Нахождение в полете(Движение с вертикальной скоростью)
    char cType;         //Тип объектов
    float horizSpeed;    //Скорость по горизонтали
} TObject;

char map[mapHeight][mapWidth+1];    //Массив содержащий игровое поле
TObject mario;                      //Создание переменной для персонажа
TObject *brick = NULL;                   //Создание переменной для препятствий 

int brickLenght;                    //Переменная хранящая размер массива brick

TObject *moving = NULL;
int movingLenght;

int level = 1;

void clearMap(){                //Процедура заполненря карты значениями
    for (int i = 0; i < mapWidth; i++) {    //Заполнение первой строки игрового поля
        map[0][i] = ' ';
    }
    map[0][mapWidth] = '\0';            //Присваивание последнему символу первой строки символа "конца строки"

    for (int j = 0; j < mapHeight; j++) {   //построчный вывод на экран первой строки
        sprintf(map[j], map[0]);
    }    
}

void showMap(){                 //Процедура отображени карты(вывод на экран карты)
    map[mapHeight-1][mapWidth-1] = '\0';        //Присваивание последнему символу последней строки символа "конец строки"
    for (int j = 0; j < mapHeight; j++) {       //Построчный вывод на экран ранее заполненых строк
        printf("%s\n", map[j]);
    }
    
}

void SetObjectPos (TObject *obj, float xPos, float yPos){   //Процедура задающая позицию персонажа в координатах
    (*obj).x = xPos;
    (*obj).y = yPos;
}

void initObject (TObject *obj, float xPos, float yPos, float oWidth, float oHeight, char inType){        //Процедура инициализирующая объект целиком (с шириной и высотой, а не только координаты)
    SetObjectPos(obj, xPos, yPos);
    (*obj).width = oWidth;
    (*obj).height = oHeight;
    (*obj).vertSpeed = 0;
    (*obj).cType = inType;
    (*obj).horizSpeed = 0.2;
}

BOOL isCollision(TObject o1, TObject o2);
void createLevel(int lvl);

void vertMoveObject(TObject *obj){      //Процедура пересчитывающая скорость и изменяющая её
    (*obj).isFly = TRUE;
    (*obj).vertSpeed += 0.05;           //Наше ускорение
    SetObjectPos(obj, (*obj).x, (*obj).y + (*obj).vertSpeed);   //Новая позиция для объекта с измененной Y координатой

    for (int i = 0; i < brickLenght; i++) {
        if (isCollision( *obj, brick[i])){      //Проерка на столкновение двух объектов
            (*obj).y -= (*obj).vertSpeed;       //Возврат назад
            (*obj).vertSpeed = 0;               //Прекращение движения
            (*obj).isFly = FALSE;               //Если марио куда-то приземлился, он теряет вертикальную скорость
            if (brick[i].cType == '+') {
                level++;
                if (level > 2) {
                    level = 1;
                }
                
                createLevel(level);
                Sleep(1000);
            }
            
            break;
        }
    }
}

void deleteMoving(int i){       //Процедура удаления движущегося объекта
    movingLenght--;
    moving[i] = moving[movingLenght];   //Помещение последнего элемента массива на место удаляемого
    moving = realloc(moving, sizeof(*moving) * movingLenght);   //После чего усекаем массив на одну ячейку
}

void MarioCollision(){      //Процедура проверяет Марио на столкновение с движущимися объектами
    for (int i = 0; i < movingLenght; i++) {
        if (isCollision( mario, moving[i])){        //Если Марио столкнулся с движущимся объектом, то уровень запускается заного
            if( (mario.isFly == TRUE)       //Если марио летит
                && (mario.vertSpeed > 0)    //И летит вниз
                && (mario.y + mario.height < moving[i].y + moving[i].height * 0.5)  //И ноги марио должны находится выше половины роста врага
               ) {
                    deleteMoving(i);    //Удаляем объект
                    i--;
                    continue;   //Начинаем новую итерацию цикла
            }
            else           //Иначе враг уничтожает Марио и уровень начинается заного
                createLevel(level);
        }
    }
}

void horizonMoveObject(TObject *obj){       //Процедура горизонтального перемещения объектов
    
    obj[0].x += obj[0].horizSpeed;

    for (int i = 0; i < brickLenght; i++) {     //Проверка на столкновение со стенами, в случае столкновения разворот в обратную сторону
        if (isCollision(obj[0], brick[i])){
            obj[0].x -= obj[0].horizSpeed;
            obj[0].horizSpeed = -obj[0].horizSpeed;
            return;
        }
    }
    
    TObject tmp = *obj;         //Создание копии объекта
    vertMoveObject(&tmp);       //Применение к копии силы тяжести
    if (tmp.isFly == TRUE){     //Если объект в полете
        obj[0].x -= obj[0].horizSpeed;      //Отменяем текущщее перемещение
        obj[0].horizSpeed = -obj[0].horizSpeed;     //и идем в обратную сторону
    }
}

BOOL isPosInMap( int x, int y){         //Процедура проверяющая не вышел ли объект за пределы игрового поля
    return ( (x >=0) && (x < mapWidth) && (y >= 0) && (y < mapHeight));
}

void PutObjectOnMap (TObject obj) {         //Процедура отображающая на карте персонажа
    int ix = (int)round(obj.x);     //для round нужен <math.h>
    int iy = (int)round(obj.y);
    int iWidth = (int)round(obj.width);
    int iHeight = (int)round(obj.height);

    for (int i = ix; i < (ix + iWidth); i++){       //отображение ширины персонажа
        for (int j = iy; j < (iy + iHeight); j++)   //отображение высоты персонажа
            if (isPosInMap(i,j))                    //Проверка нахождения объекта внутри игрового поля
                map[j][i] = obj.cType;
    }
}

void setCur(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition ( GetStdHandle(STD_OUTPUT_HANDLE), coord);     //GetStdHandle возвращает адрес, определяемый входным параметром
}

void horizonMoveMap(float dx){      //Функция перемещения карты по горизонтали
    mario.x -= dx;          //Двигаем марио в противоположном направлении

    for (int i = 0; i < brickLenght; i++) {     //Проверяем на столкновение со всеми блоками
        if (isCollision(mario, brick[i])){
            mario.x += dx;      //Если столкнулся, то возвращаем его в начальную 
            return;             //позицию и выходим
        }
    }
    
    mario.x += dx;      //Иначе просто возвращаем в начальную позицию
    
    for (int i = 0; i < brickLenght; i++) {
        brick[i].x += dx;
    }

    for (int i = 0; i < movingLenght; i++) {
        moving[i].x += dx;
    }
}

BOOL isCollision(TObject o1, TObject o2){               //Функция проверки на столкновения двух объектов
    return ((o1.x + o1.width) > o2.x) && (o1.x < (o2.x + o2.width)) &&
            ((o1.y + o1.height) > o2.y) && (o1.y <(o2.y + o2.height));
}

void createLevel(int lvl){             //Процедура создания уровней
    initObject(&mario, 39, 10, 3 ,3, '@');

    if (lvl == 1){
        brickLenght = 6;
        brick = realloc(brick, sizeof(*brick) * brickLenght);
        initObject(brick+0, 20, 20, 40, 5, '#');
        initObject(brick+1, 60, 15, 10, 10, '#');
        initObject(brick+2, 80, 20, 20, 5, '#');
        initObject(brick+3, 120, 15, 10, 10, '#');
        initObject(brick+4, 150, 20, 40, 5, '#');
        initObject(brick+5, 210, 15, 10, 10, '+');
        movingLenght = 1;
        moving = realloc(moving, sizeof(*moving) * movingLenght);
        initObject(moving+0, 25, 10, 3, 2, 'o');
    }

    if (lvl == 2){
        brickLenght = 4;
        brick = realloc(brick, sizeof(*brick) * brickLenght);
        initObject(brick+0, 20, 20, 40, 5, '#');
        initObject(brick+1, 80, 20, 15, 5, '#');
        initObject(brick+2, 120, 15, 15, 10, '#');
        initObject(brick+3, 160, 10, 15, 15, '+');
    }
}

int main(){

    createLevel(level);
    
    do {
        clearMap();

        if ((mario.isFly == FALSE) && (GetKeyState(VK_SPACE) < 0)) mario.vertSpeed = -1;      //Если марио стоит на поверхности и нажат пробел. По нажатию кнопки пробела Марио приобретает отрицательную вертикальную скорость(Подпрыгивает)
        if (GetKeyState('A') < 0) horizonMoveMap(1);        //При нажатии клавиши 'A' или 'D' Карта перемещается
        if (GetKeyState('D') < 0) horizonMoveMap(-1);       // влево или вправо относительно марио

        if (mario.y > mapHeight) createLevel(level);     //Проверка нахождения марио внутри игрового поля, иначе уровень начинается заного 

        vertMoveObject(&mario);
        MarioCollision();

        for (int i =0; i< brickLenght; i++){
            PutObjectOnMap(brick[i]);
        }
        for (int i =0; i< movingLenght; i++){
            vertMoveObject(moving + i);
            horizonMoveObject(moving + i);
            /*if (moving[i].y > mapHeight) {
                deleteMoving(i);    //Удаляем объект
                i--;
                continue;   //Начинаем новую итерацию цикла
            }*/
            PutObjectOnMap(moving[i]);
        }
        PutObjectOnMap(mario);

        setCur(0,0);
        showMap();

        Sleep(10);
    } while (GetKeyState(VK_ESCAPE) >= 0);      // Для GetKeyState и VK_ESCAPE нужен <window.h>
    
    //system("pause");
    return 0;
}