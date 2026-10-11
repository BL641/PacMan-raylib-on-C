
#include "PacMan.h"
#include "map.h"

int main() {
    InitWindow(675, 900, "PacMan");

    int isMapNull = 0;
    int result;

    PacMan pac;
    PacInit(&pac);

    MapCopy();

    while (!WindowShouldClose()) {
        result = CheckGameSustain(&pac, &isMapNull);
        if (pac.round_delay > 0 && pac.start == 0) {
            pac.SustChoice = WALK_LEFT;
            pac.status = 2;
            
            
            if (pac.round_delay < 2.9f && pac.level > 0) {
                if (isMapNull == 0) {
                    MapRestore();
                    
                }
            }


            if (!isMapNull) {
                pac.px = 320;
                pac.py = 736;
                if (pac.start == 0) {
                    pac.round_delay -= GetFrameTime();
                }
            }


        }

        else {
            if (pac.round_delay < 0.0f) {
                pac.status = 0;
                pac.wantDirY = 0; pac.wantDirX = -1;
                pac.start = 1;
                pac.round_delay = 3.0f;
            }

            PacMove(&pac);
            PacUpdate(&pac);
            PacEat(&pac);
            PacPortals(&pac);
        }


        

        BeginDrawing();
        ClearBackground(BLACK);
        MapDraw(&pac);
        PacDraw(&pac);
        //if (pac.round_delay > 0 && pac.start == 0) {
        //    DrawText("READY!", 280, 480, 32, YELLOW);
        //    if (isMapNull == 1) {
        //        DrawText("READY!", 280, 480, 32, YELLOW);
        //    }
        //    else {
        //        // #TODO сделать логику после первого уровня
        //        // #TODO сделать реализацию функции по занулению всей карты и ее последующей новой отрисовки

        //       

        //    }
        //}

        EndDrawing();
    }
    // #TODO сделать отдельную функцию по освобождению данных
    for (int i = 0; i < 6; i++) {
        UnloadTexture(pac.texMassive[i]);
    }
    CloseWindow();
    return 0;
}