
#include "raylib.h"

int map[28][28] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,3,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3,3,1},
    {0,1,3,1,1,3,1,1,1,3,1,3,1,1,1,3,1,1,3,1},
    {0,1,3,1,1,3,1,1,1,3,1,3,1,1,1,3,1,1,3,1},
    {0,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1},
    {0,1,3,1,1,3,1,3,1,1,1,1,1,3,1,3,1,1,3,1},
    {0,1,3,3,3,3,1,3,3,3,1,3,3,3,1,3,3,3,3,1},
    {0,1,1,1,1,3,1,1,1,3,1,3,1,1,1,3,1,1,1,1},
    {0,3,3,3,1,3,1,3,3,3,3,3,3,3,1,3,1,3,3,3},
    {0,1,1,1,1,3,1,3,1,1,3,1,1,3,1,3,1,1,1,1},
    {0,5,3,3,3,3,3,3,1,3,3,3,1,3,3,3,3,3,3,6},
    {0,1,1,1,1,3,1,3,1,1,1,1,1,3,1,3,1,1,1,1},
    {0,3,3,3,1,3,1,3,3,3,3,3,3,3,1,3,1,3,3,3},
    {0,1,1,1,1,3,1,3,1,1,1,1,1,3,1,3,1,1,1,1},
    {0,1,3,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3,3,1},
    {0,1,3,1,1,3,1,1,1,3,1,3,1,1,1,3,1,1,3,1},
    {0,1,3,3,1,3,3,3,3,3,3,3,3,3,3,3,1,3,3,1},
    {0,0,1,3,1,3,1,3,1,1,1,1,1,3,1,3,1,3,1,3},
    {0,1,3,3,3,3,1,3,3,3,1,3,3,3,1,3,3,3,3,1},
    {0,1,3,1,1,1,1,1,1,3,1,3,1,1,1,1,1,1,3,1},
    {0,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};


int itemsMap[28][28] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                         {0,1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1},
                         {0,1,3,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,3,1},
                         {0,1,2,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,2,1},
                         {0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
                         {0,1,2,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,2,1},
                         {0,1,2,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,1},
                         {0,1,1,1,1,2,1,1,1,3,1,3,1,1,1,2,1,1,1,1},
                         {0,3,3,3,1,2,1,3,3,3,3,3,3,3,1,2,1,3,3,3},
                         {0,1,1,1,1,2,1,3,1,1,3,1,1,3,1,2,1,1,1,1},
                         {0,5,3,3,3,2,3,3,1,3,3,3,1,3,3,2,3,3,5,3},
                         {5,1,1,1,1,2,1,3,1,1,1,1,1,3,1,2,1,1,1,1},
                         {0,3,3,3,1,2,1,3,3,3,3,3,3,3,1,2,1,3,3,3},
                         {0,1,1,1,1,2,1,3,1,1,1,1,1,3,1,2,1,1,1,1},
                         {0,1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1},
                         {0,1,2,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,2,1},
                         {0,1,2,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,2,1},
                         {0,0,1,2,1,2,1,2,1,1,1,1,1,2,1,2,1,2,1,3},
                         {0,1,2,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,1},
                         {0,1,3,1,1,1,1,1,1,2,1,2,1,1,1,1,1,1,3,1},
                         {0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
                         {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

typedef struct PacMan {
    double moveTimer;
    int score, fscore;
    int level;
    int levelComplete;

    int x, y;
    int dirX, dirY, wantDirX, wantDirY;
    float speed;
    float x_coo, y_coo;
    int endX, endY;
    void (*update)(struct PacMan* self);
    void (*move)(struct PacMan* self);
    void (*draw)(struct PacMan* self);
    void (*eat)(struct PacMan* self);
    void (*portal)(struct PacMan* self);
} PacMan;

void MapDraw(PacMan* self) {
    DrawText(TextFormat("Score: %d", self->score), 10, 10, 30, WHITE);
    DrawText(TextFormat("Lv: %d", self->level), 10, 40, 30, WHITE);
    for (int y = 0; y < 28; y++) {
        for (int x = 0; x < 21; x++) {
            if (map[y][x] == 1) {
                DrawRectangle(x * 32, y * 32, 32, 32, DARKBLUE);
            }
            if (itemsMap[y][x] == 2) {
                DrawCircle(x * 32 + 16, y * 32 + 16, 3, RAYWHITE);
            }
        }
    }
}


void PacEat(PacMan* self) {
    if (itemsMap[self->y][self->x] == 2) {
        itemsMap[self->y][self->x] = 0;
        self->score += 10;
    }
}

void Portals(PacMan* self) {
    if (map[self->y][self->x] == 5) {
        for (int x = 0; x < 21; x++) {
            if (map[self->y][x] == 6) {
                self->x = x - 1;
                // self->wantDirX = -1;
                // self->wantDirY = 0;
            }
        }
    }
    else if (map[self->y][self->x] == 6) {
        for (int x = 0; x < 21; x++) {
            if (map[self->y][x] == 5) {
                self->x = x + 1;
                // self->wantDirX = 1;
                // self->wantDirY = 0;
            }
        }
    }
}


void PacUpdate(PacMan* self) {
    self->moveTimer += GetFrameTime();
    if (self->moveTimer >= 0.15f) {
            self->moveTimer = 0;
            if (map[self->y + self->wantDirY][self->x + self->wantDirX] != 1) {
                self->dirY = self->wantDirY;
                self->dirX = self->wantDirX;


                self->y += self->dirY; self->x += self->dirX;
                self->y_coo = self->y * 32; self->x_coo = self->x * 32;
            }
    }
   
}

void PacDraw(PacMan* self) {
    DrawRectangle((int)self->x_coo, (int)self->y_coo, 32, 32, YELLOW);
}

void PacMove(PacMan* self) {

        if (IsKeyDown(KEY_W) && map[self->y - 1][self->x] != 1) {
            self->wantDirX = 0; self->wantDirY = -1;
        }
        else if (IsKeyDown(KEY_S) && map[self->y + 1][self->x] != 1) {
            self->wantDirX = 0; self->wantDirY = 1;
        }
        else if (IsKeyDown(KEY_A) && map[self->y][self->x - 1] != 1) {
            self->wantDirX = -1; self->wantDirY = 0;
        }
        else if (IsKeyDown(KEY_D) && map[self->y][self->x + 1] != 1) {
            self->wantDirX = 1; self->wantDirY = 0;
        }

}

void CheckGameSustain(PacMan* self) {
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

void PacInit(PacMan* self) {
    self->level = 0;
    self->levelComplete = 0; 

    self->score = 0;
    self->dirX = 0; self->dirY = 0;
    self->wantDirX = -1; self->wantDirY = 0;
    self->x = 10;
    self->y = 23;
    self->moveTimer = 0;

    self->endX = self->x;
    self->endY = self->y;

    self->speed = 0.2f; 
    self->y_coo = self->y * 32.0f;
    self->x_coo = self->x * 32.0f;

    self->update = PacUpdate;
    self->move = PacMove;
    self->draw = PacDraw;
    self->eat = PacEat;
    self->portal = Portals;
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
