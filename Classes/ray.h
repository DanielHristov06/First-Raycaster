#pragma once
#define _USE_MATH_DEFINES
#include <settings.h>
#include <Classes/player.h>
#include <Classes/map.h>
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
        Map rayMap;

        bool isFacingDown = rayAngle > 0 && rayAngle < M_PI;
        bool isFacingUp = !isFacingDown;
        bool isFacingRight = rayAngle < 0.5 * M_PI || rayAngle > 1.5 * M_PI;
        bool isFacingLeft = !isFacingRight;

        int wallHitX = 0;
        int wallHitY = 0;

        MyRay(Player& player, double angle, Map map) : rayPlayer(player), rayAngle(normalizeAngle(angle)), rayMap(map){}

        ~MyRay(){}

        void Cast(){
            bool foundHorizontalWall = false;
            int horHitX = 0;
            int horHitY = 0;

            double firstIntersectX = NAN;
            double firstIntersectY = NAN;

            if (isFacingUp) firstIntersectY = std::floor(rayPlayer.y / TILESIZE) * TILESIZE - 1;
            else if (isFacingDown) firstIntersectY = std::floor(rayPlayer.y / TILESIZE) * TILESIZE + TILESIZE;

            firstIntersectX = ((firstIntersectY - rayPlayer.y) / tan(rayAngle)) + rayPlayer.x;

            double nextHorX = firstIntersectX;
            double nextHorY = firstIntersectY;

            int xa = 0;
            int ya = 0;

            if (isFacingUp) ya = -TILESIZE;
            if (isFacingDown) ya = TILESIZE;

            xa = ya / tan(rayAngle);

            while (nextHorX <= windowWidth && nextHorX >= 0 && nextHorY <= windowHeight && nextHorY <= 0){
                if (rayMap.hasWallAt(nextHorX, nextHorY)){
                    foundHorizontalWall = true;
                    horHitX = nextHorX;
                    horHitY = nextHorY;
                    break;
                }
                else{
                    nextHorX += xa;
                    nextHorY += ya;
                }
            }

            wallHitX = horHitX;
            wallHitY = horHitY;
        }

        void Draw(){
            DrawLine(rayPlayer.x, rayPlayer.y, wallHitX, wallHitY, RED);
        }
};