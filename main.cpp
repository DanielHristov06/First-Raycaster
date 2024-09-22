#include <Classes/raycaster.h>

Map map;
Player player;
Raycaster raycaster = Raycaster(player, map);

int main(){
    InitWindow(windowWidth, windowHeight, "Raycaster");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        // Key Checks
        if (IsKeyPressed(KEY_ESCAPE)) WindowShouldClose();

        //Updating
        player.Update(map);
        raycaster.castAllRays();

        BeginDrawing();
        ClearBackground(BLACK);

        // Drawing
        //map.Draw();
        //player.Draw();

        DrawRectangle(0, 0, windowWidth, windowHeight / 2, BLUE);
        DrawRectangle(0, windowHeight / 2, windowWidth, windowHeight / 2, DARKGREEN);
        raycaster.Draw();

        DrawText(TextFormat("%i", GetFPS()), 32, 32, 32, GREEN);

        EndDrawing();
    }
    CloseWindow();
}