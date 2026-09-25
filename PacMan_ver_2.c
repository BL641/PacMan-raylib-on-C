
#include "raylib.h"

int map[28][28] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,3,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3,3,1,0},
    {0,1,3,1,1,3,1,1,1,3,1,3,1,1,1,3,1,1,3,1,0},
    {0,1,3,1,1,3,1,1,1,3,1,3,1,1,1,3,1,1,3,1,0},
    {0,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,0},
    {0,1,3,1,1,3,1,3,1,1,1,1,1,3,1,3,1,1,3,1,0},
    {0,1,3,3,3,3,1,3,3,3,1,3,3,3,1,3,3,3,3,1,0},
    {0,1,1,1,1,3,1,1,1,3,1,3,1,1,1,3,1,1,1,1,0},
    {0,3,3,3,1,3,1,3,3,3,3,3,3,3,1,3,1,3,3,3,0},
    {0,1,1,1,1,3,1,3,1,1,3,1,1,3,1,3,1,1,1,1,0},
    {5,3,3,3,3,3,3,3,1,3,3,3,1,3,3,3,3,3,3,3,6},
    {0,1,1,1,1,3,1,3,1,1,1,1,1,3,1,3,1,1,1,1,0},
    {0,3,3,3,1,3,1,3,3,3,3,3,3,3,1,3,1,3,3,3,0},
    {0,1,1,1,1,3,1,3,1,1,1,1,1,3,1,3,1,1,1,1,0},
    {0,1,3,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3,3,1,0},
    {0,1,3,1,1,3,1,1,1,3,1,3,1,1,1,3,1,1,3,1,0},
    {0,1,3,3,1,3,3,3,3,3,3,3,3,3,3,3,1,3,3,1,0},
    {0,0,1,3,1,3,1,3,1,1,1,1,1,3,1,3,1,3,1,3,0},
    {0,1,3,3,3,3,1,3,3,3,1,3,3,3,1,3,3,3,3,1,0},
    {0,1,3,1,1,1,1,1,1,3,1,3,1,1,1,1,1,1,3,1,0},
    {0,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};


int itemsMap[28][28] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                         {0,1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,0},
                         {0,1,3,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,3,1,0},
                         {0,1,2,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,2,1,0},
                         {0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0},
                         {0,1,2,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,2,1,0},
                         {0,1,2,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,1,0},
                         {0,1,1,1,1,2,1,1,1,3,1,3,1,1,1,2,1,1,1,1,0},
                         {0,3,3,3,1,2,1,3,3,3,3,3,3,3,1,2,1,3,3,3,0},
                         {0,1,1,1,1,2,1,3,1,1,3,1,1,3,1,2,1,1,1,1,0},
                         {5,3,3,3,3,2,3,3,1,3,3,3,1,3,3,2,3,3,5,3,0},
                         {5,1,1,1,1,2,1,3,1,1,1,1,1,3,1,2,1,1,1,1,0},
                         {0,3,3,3,1,2,1,3,3,3,3,3,3,3,1,2,1,3,3,3,0},
                         {0,1,1,1,1,2,1,3,1,1,1,1,1,3,1,2,1,1,1,1,0},
                         {0,1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,0},
                         {0,1,2,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,2,1,0},
                         {0,1,2,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,2,1,0},
                         {0,0,1,2,1,2,1,2,1,1,1,1,1,2,1,2,1,2,1,3,0},
                         {0,1,2,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,1,0},
                         {0,1,3,1,1,1,1,1,1,2,1,2,1,1,1,1,1,1,3,1,0},
                         {0,1,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,1,0},
                         {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

// Структура PacMan
typedef struct PacMan {
     
    // вспомогательные поля
    // =================
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


    // методы
    // =================
    void (*update)(struct PacMan* self);
    void (*move)(struct PacMan* self);
    void (*draw)(struct PacMan* self);
    void (*eat)(struct PacMan* self);
    void (*portal)(struct PacMan* self);
    // =================
} PacMan;

// Функция отрисовки карты
static void MapDraw(PacMan* self) {
    DrawText(TextFormat("Score: %d", self->score), 10, 10, 30, WHITE);
    DrawText(TextFormat("Lv: %d", self->level), 10, 40, 30, WHITE);
    for (int y = 0; y < 28; y++) {
        for (int x = 0; x < 23; x++) {
            if (map[y][x] == 1) {
                DrawRectangle(x * 32, y * 32, 32, 32, DARKBLUE);
            }
            if (itemsMap[y][x] == 2) {
                DrawCircle(x * 32 + 16, y * 32 + 16, 3, RAYWHITE);
            }
        }
    }
}

// Функция поедания 
static void PacEat(PacMan* self) {
    if (itemsMap[(self->py + 16) / 32][(self->px + 16) / 32] == 2) {
        itemsMap[(self->py + 16) / 32][(self->px + 16)/ 32] = 0;
        self->score += 10;
    }
}

// Функция реализации порталов
static void Portals(PacMan* self) {
    if (map[(self->py)/ 32][(self->px + 64)/ 32] == 5) {
        for (int x = 0; x < 23; x++) {
            if (map[self->py / 32][x] == 6) {
                self->px = (x * 32) + 32;
            }
        }
    }
    else if (map[(self->py) / 32][(self->px - 64) / 32] == 6) {
        for (int x = 0; x < 21; x++) {
            if (map[self->py / 32][x] == 5) {
                self->px = (x * 32) - 32;
            }
        }
    }
}

// Вспомогательная функция для перемещения
static int CanWalk(PacMan* self) {
    if (self->px % 32 == 0 && self->py % 32 == 0) {
        return 1;
    }
    else return 0;
}

// Функция обновления отрисовки и движения
static void PacUpdate(PacMan* self) {
        if (CanWalk(self)) {
            int nextY = self->py / 32 + self->wantDirY;
            int nextX = self->px / 32 + self->wantDirX;

            if (map[nextY][nextX] != 1 && map[nextY][nextX] != 0) {
                self->dirY = self->wantDirY;
                self->dirX = self->wantDirX;
            }
            
            int frontY = self->py / 32 + self->dirY;
            int frontX = self->px / 32 + self->dirX;

            if (map[frontY][frontX] == 1) {
                self->dirY = 0;
                self->dirX = 0;
            }

        }
        self->timer += GetFrameTime();
        if (self->timer >= 0.008f) {
            self->timer -= 0.008f;
            self->py += self->speed * self->dirY;
            self->px += self->speed * self->dirX;
        }
}

// Функция отрисовки ПакМана
static void PacDraw(PacMan* self) {
    DrawRectangle(self->px, self->py, 32, 32, YELLOW);
}

// Функция движения ПакМана 
static void PacMove(PacMan* self) {

    if (IsKeyDown(KEY_W)) {
        self->wantDirX = 0; self->wantDirY = -1;
    }
    else if (IsKeyDown(KEY_S)) {
        self->wantDirX = 0; self->wantDirY = 1;
    }
    else if (IsKeyDown(KEY_A)) {
        self->wantDirX = -1; self->wantDirY = 0;
    }
    else if (IsKeyDown(KEY_D)) {
        self->wantDirX = 1; self->wantDirY = 0;
    }

}

// Функция проверки состояния игры
static void CheckGameSustain(PacMan* self) {
    int points_score = 0;
    for (int y = 0; y < 21; y++) {
        for (int x = 0; x < 28; x++) {
            if (itemsMap[y][x] == 2) {
                points_score++;
            }
        }
    }
    if (points_score == 0 && !self->levelComplete) {
        self->levelComplete = 1;
        self->level++;
    }
}

// Функция инициализации
static void PacInit(PacMan* self) {
    // вспомогательные поля
    // =====================
    self->timer = 0;
    self->level = 0;
    self->levelComplete = 0;
    self->score = 0;
    // =====================


    //Движение пакмана
    // =====================
    self->dirX = 0; self->dirY = 0;
    self->wantDirX = -1; self->wantDirY = 0;
    self->speed = 1;
    self->px = 320; self->x = self->px / 32;
    self->py = 736; self->y = self->py / 32;
    // =====================

    // методы
    // =====================
    self->update = PacUpdate;
    self->move = PacMove;
    self->draw = PacDraw;
    self->eat = PacEat;
    self->portal = Portals;
    // =====================
}

int main() {
    InitWindow(675, 900, "PacMan");

    PacMan pac;
    PacInit(&pac);

    while (!WindowShouldClose()) {
        pac.move(&pac);
        pac.update(&pac);
        pac.eat(&pac);
        pac.portal(&pac);

        BeginDrawing();
        ClearBackground(BLACK);
        MapDraw(&pac);
        pac.draw(&pac);
        EndDrawing();
        CheckGameSustain(&pac);
    }

    CloseWindow();
    return 0;
}