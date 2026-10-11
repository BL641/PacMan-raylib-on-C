
#include "PacMan.h"
#include "map.h"

// Функция инициализации текстур 
void PacTextureInit(PacMan* self) {
    for (int i = 0; i < 6; i++) {
        switch (i) {
        case SLEEP: {
            *(self->texMassive + i) = LoadTexture("frames/sleep");
            break;
        }
        case WALK_UP: {
            *(self->texMassive + i) = LoadTexture("frames/PacMan_WalkUp.png");
            break;
        }
        case WALK_DOWN: {
            *(self->texMassive + i) = LoadTexture("frames/PacMan_WalkDown.png");
            break;
        }
        case WALK_RIGHT: {
            *(self->texMassive + i) = LoadTexture("frames/PacMan_WalkRight.png");
            break;
        }
        case WALK_LEFT: {
            *(self->texMassive + i) = LoadTexture("frames/PacMan_WalkLeft.png");
            break;
        }
        case DEATH: {
            break;
        }
        }
    }
}

// Функция поедания 
void PacEat(PacMan* self) {
    if (itemsMap[(self->py + 16) / 32][(self->px + 16) / 32] == 2) {
        itemsMap[(self->py + 16) / 32][(self->px + 16) / 32] = 0;
        self->score += 10;
    }

}

// Функция реализации порталов
void PacPortals(PacMan* self) {
    if (map[(self->py) / 32][(self->px + 64) / 32] == 5) {
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
inline int CanWalk(PacMan* self) {
    if (self->px % 32 == 0 && self->py % 32 == 0) {
        return 1;
    }
    else return 0;
}

// Функция обновления отрисовки и движения
void PacUpdate(PacMan* self) {
    if (CanWalk(self)) {
        int nextY = self->py / 32 + self->wantDirY;
        int nextX = self->px / 32 + self->wantDirX;

        if (map[nextY][nextX] != 1 && map[nextY][nextX] != 0) {
            self->dirY = self->wantDirY;
            self->dirX = self->wantDirX;

            if (self->dirY == -1 && self->dirX == 0) {
                self->SustChoice = WALK_UP;
            }
            else if (self->dirY == 1 && self->dirX == 0) {
                self->SustChoice = WALK_DOWN;
            }
            else if (self->dirY == 0 && self->dirX == -1) {
                self->SustChoice = WALK_LEFT;
            }
            else if (self->dirY == 0 && self->dirX == 1) {
                self->SustChoice = WALK_RIGHT;
            }
            self->status = 0;

        }

        int frontY = self->py / 32 + self->dirY;
        int frontX = self->px / 32 + self->dirX;

        if (map[frontY][frontX] == 1) {
            self->dirY = 0;
            self->dirX = 0;

            self->status = 1;
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
void PacDraw(PacMan* self) {
    Texture2D tex = self->texMassive[self->SustChoice];

    int frameCount = 4;
    int frameW = tex.width / frameCount;
    int frameH = tex.height;
    int frame = (int)(GetTime() / 0.08f) % frameCount;

    Rectangle src = { frame * frameW, 0, frameW, frameH };
    Vector2 pos = { self->px, self->py };

    if (!self->status) {
        DrawTextureRec(tex, src, pos, WHITE);
    }
    else {
        if (self->status == 2) {
            frameCount = 2;
            frame = frameCount;
            src.x = frame * frameW;

            DrawTextureRec(tex, src, pos, WHITE);
        }

        frameCount = 1;
        frame = frameCount;
        src.x = frame * frameW;

        DrawTextureRec(tex, src, pos, WHITE);

    }
}

// Функция движения ПакМана 
void PacMove(PacMan* self) {
    if (self->start) {
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
            self->wantDirX = 0; self->wantDirY = -1;
        }
        else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
            self->wantDirX = 0; self->wantDirY = 1;
        }
        else if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
            self->wantDirX = -1; self->wantDirY = 0;
        }
        else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
            self->wantDirX = 1; self->wantDirY = 0;
        }
    }
}

// Функция проверки состояния игры
int CheckGameSustain(PacMan* self, int* isMapNull) {
    int points_score = 0;
    for (int y = 0; y < MAP_LENGHT; y++) {
        for (int x = 0; x < MAP_HEIGHT; x++) {
            if (itemsMap[y][x] == 2) {
                points_score++;
            }
        }
    }
    if (points_score == 0 && self->start == 1) {
        self->levelComplete = 1;
        self->level++;
        self->start = 0;
        self->SustChoice = SLEEP; //#TODO Пак ман не исчезает
        self->round_delay = 6.0f;
        *isMapNull = MapNull();
        return 0;
    }
    else {
        return 1;
    }
}

// Функция инициализации
void PacInit(PacMan* self) {
    // вспомогательные поля
    // =====================
    self->round_delay = 6.0f;
    self->start = 0;
    self->status = 0;
    self->timer = 0;
    self->level = 0;
    self->levelComplete = 0;
    self->score = 0;
    // =====================


    //Движение пакмана
    // =====================
    self->dirX = -1; self->dirY = 0;
    self->wantDirX = 0; self->wantDirY = 0;
    self->speed = 1;
    self->px = 320; self->x = self->px / 32;
    self->py = 736; self->y = self->py / 32;
    // =====================

     // Фреймы
    // =================
    PacTextureInit(self);
    self->SustChoice = WALK_LEFT;
    // =================
}
