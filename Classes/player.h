#pragma once
#define _USE_MATH_DEFINES
#include <settings.h>
#include <cmath>

class Player{
    public:
        int x = windowWidth / 2;
        int y = windowHeight / 2;
        int r = 10;
        int turnDirection = 0;
        int walkDirection = 0;
        float angle = 0;
        float walkSpeed = 2.5;
        float rotationSpeed = 2 * (M_PI / 180);

        void Update(){
            turnDirection = 0;
            walkDirection = 0;

            if (IsKeyDown(KEY_D)) turnDirection = 1;
            if (IsKeyDown(KEY_A)) turnDirection = -1;

            if (IsKeyDown(KEY_W)) walkDirection = 1;
            if (IsKeyDown(KEY_S)) walkDirection = -1;

            float moveStep = walkDirection * walkSpeed;

            angle += turnDirection * rotationSpeed;
            x += cos(angle) * moveStep * dt;
            y += sin(angle) * moveStep * dt;
        }

        void Draw(){
            DrawCircle(x, y, r, BLUE);
        }
};