#include <Classes/map.cpp>
#include <Classes/player.cpp>

Map map;
Player player;

int main(){
    InitWindow(windowWidth, windowHeight, "Raycaster");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        // Key Checks
        if (IsKeyPressed(KEY_ESCAPE)) WindowShouldClose();

        //Updating
        player.Update();

        // Drawing
        BeginDrawing();
        ClearBackground(BLACK);

        map.Draw();
        player.Draw();

        EndDrawing();
    }
    CloseWindow();
}