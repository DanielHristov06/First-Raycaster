#include <raylib.h>

const int windowWidth = 1280;
const int windowHeight = 720;

int main(){
    InitWindow(windowWidth, windowHeight, "Raycaster");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        EndDrawing();
    }
}