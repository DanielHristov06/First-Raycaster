#include <raylib.h>
#include <settings.cpp>

int main(){
    InitWindow(windowWidth, windowHeight, "Raycaster");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }
}