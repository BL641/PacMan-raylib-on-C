
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


    // методы
    // =================
    void (*update)(struct PacMan* self);
    void (*move)(struct PacMan* self);
    void (*draw)(struct PacMan* self);
    void (*eat)(struct PacMan* self);
    void (*portal)(struct PacMan* self);
    // =================
} PacMan;


// Функция инициализации текстур 
static void PacTextureInit(PacMan* self) {
    for (int i = 0; i < 6; i++) {
        switch (i) {
        case SLEEP: {
            *(self->texMassive + i);
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
static void PacDraw(PacMan* self) {
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
static void PacMove(PacMan* self) {
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
    self->round_delay = 3.0f;
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

    //float round_delay = 3.0f;

    PacMan pac;
    PacInit(&pac);


    while (!WindowShouldClose()) {
        if (pac.round_delay > 0 && pac.start == 0) {
            pac.status = 2;

            pac.round_delay -= GetFrameTime();
        }
        else {
            if (pac.round_delay < 0.0f) {
                pac.status = 0;
                pac.start = 1;
                pac.round_delay = 3.0f;
            }
            pac.move(&pac);
            pac.update(&pac);
            pac.eat(&pac);
            pac.portal(&pac);
        }
        
        BeginDrawing();
        ClearBackground(BLACK);
        MapDraw(&pac);
        pac.draw(&pac);
        if (pac.round_delay > 0 && pac.start == 0) {
            DrawText("READY!", 280, 480, 32, YELLOW);
        }
        EndDrawing();
        CheckGameSustain(&pac);
    }
    for (int i = 0; i < 6; i++) {
        UnloadTexture(pac.texMassive[i]);
    }

    CloseWindow();
    return 0;
}