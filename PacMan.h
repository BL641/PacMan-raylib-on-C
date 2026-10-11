
#ifndef __PACMAN__H
#define __PACMAN__H

#include "raylib.h"

// Состояния ПакМана
enum PacSustain {
    SLEEP = 0,
    WALK_UP = 1,
    WALK_DOWN = 2,
    WALK_RIGHT = 3,
    WALK_LEFT = 4,
    DEATH = 5
};

// Структура PacMan
typedef struct PacMan {

    // вспомогательные поля
    // =================
    int start;
    float round_delay;
    int status;
    float timer;
    int score, fscore;
    int level;
    int levelComplete;
    // =================

    // движение пакмана
    // =================
    int x, y;
    int px, py;
    int dirX, dirY, wantDirX, wantDirY;
    int speed;
    // =================

    // Фреймы
    // =================
    enum PacSustain SustChoice;
    Texture2D texMassive[6];
    // =================

} PacMan;

// Функция обновления отрисовки и движения
void PacUpdate(PacMan* self);

// Функция отрисовки ПакМана
void PacDraw(PacMan* self);

// Функция поедания 
void PacEat(PacMan* self);

// Функция реализации порталов
void PacPortals(PacMan* self);

// Функция движения ПакМана 
void PacMove(PacMan* self);

// Функция проверки состояния игры
int CheckGameSustain(PacMan* self, int* isMapNull);

// Функция инициализации
void PacInit(PacMan* self);



#endif // __PACMAN__H

