#pragma once
#define _USE_MATH_DEFINES
#include <settings.h>
#include <Classes/player.h>
#include <cmath>

class MyRay{
    private:
        double normalizeAngle(float angle){
            angle = fmod(angle, 2 * M_PI);
            if (angle < 0) angle = (2 * M_PI) + angle;
            return angle;
        }
        
    public:
        Player& rayPlayer;
        double rayAngle;

        MyRay(Player& player, double angle) : rayPlayer(player), rayAngle(normalizeAngle(angle)){}

        ~MyRay(){}

        void Cast(){

        }

        void Draw(){
            DrawLine(rayPlayer.x, rayPlayer.y, rayPlayer.x + cos(rayAngle) * 50, rayPlayer.y + sin(rayAngle) * 50, RED);
        }
};