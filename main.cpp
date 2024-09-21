#include <Classes/map.cpp>
#include <Classes/raycaster.h>

Map map;
Player player;
Raycaster raycaster = Raycaster(player);

int main(){
    InitWindow(windowWidth, windowHeight, "Raycaster");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        // Key Checks
        if (IsKeyPressed(KEY_ESCAPE)) WindowShouldClose();

        //Updating
        player.Update();
        raycaster.castAllRays();

        BeginDrawing();
        ClearBackground(BLACK);

        // Drawing
        map.Draw();
        player.Draw();
        raycaster.Draw();

        EndDrawing();
    }
    CloseWindow();
}