#include <raylib.h>
#include <Classes/map.cpp>

Map map;

int main(){
    InitWindow(windowWidth, windowHeight, "Raycaster");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        // Key Checks
        if (IsKeyPressed(KEY_ESCAPE)) WindowShouldClose();

        // Drawing
        BeginDrawing();
        ClearBackground(BLACK);

        map.Draw();

        EndDrawing();
    }
    CloseWindow();
}