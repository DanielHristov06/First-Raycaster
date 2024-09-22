#pragma once
#define _USE_MATH_DEFINES
#include <raymath.h>
#include <settings.h>
#include <Classes/player.h>
#include <Classes/map.h>
#include <cmath>

class MyRay{
    private:
        double normalizeAngle(float angle){
            angle = fmod(angle, 2 * M_PI);
            if (angle <= 0) angle += (2 * M_PI);
            return angle;
        }

        float distanceBetween(float x1, float y1, float x2, float y2){
            return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        }
        
    public:
        Player& rayPlayer;
        double rayAngle;
        Map rayMap;

        bool isFacingDown = normalizeAngle(rayAngle) > 0 && normalizeAngle(rayAngle) < M_PI;
        bool isFacingUp = !isFacingDown;
        bool isFacingRight = normalizeAngle(rayAngle) < 0.5 * M_PI || normalizeAngle(rayAngle) > 1.5 * M_PI;
        bool isFacingLeft = !isFacingRight;

        float wallHitX = 0;
        float wallHitY = 0;

        float dist = 0;

        unsigned char col = 0;
        Color color = {col, col, col};

        MyRay(Player& player, double angle, Map map) : rayPlayer(player), rayAngle(normalizeAngle(angle)), rayMap(map){}

        ~MyRay(){}

        void Cast(){
            isFacingDown = rayAngle > 0 && rayAngle < M_PI;
            isFacingUp = !isFacingDown;
            isFacingRight = rayAngle < 0.5 * M_PI || rayAngle > 1.5 * M_PI;
            isFacingLeft = !isFacingRight;

            rayAngle = normalizeAngle(rayAngle);

            // Horizontal checking
            bool foundHorizontalWall = false;
            float horHitX = 0;
            float horHitY = 0;

            double firstIntersectX = NAN;
            double firstIntersectY = NAN;

            if (isFacingUp) firstIntersectY = std::floor(rayPlayer.y / TILESIZE) * TILESIZE - 0.001;
            else if (isFacingDown) firstIntersectY = std::floor(rayPlayer.y / TILESIZE) * TILESIZE + TILESIZE;

            firstIntersectX = ((firstIntersectY - rayPlayer.y) / tan(rayAngle)) + rayPlayer.x;

            double nextHorX = firstIntersectX;
            double nextHorY = firstIntersectY;

            double xa = 0;
            double ya = 0;

            if (isFacingUp) ya = -TILESIZE;
            if (isFacingDown) ya = TILESIZE;

            xa = ya / tan(rayAngle);

            while (nextHorX <= windowWidth && nextHorX >= 0 && nextHorY <= windowHeight && nextHorY >= 0){
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

            // Verical checking
            bool foundVerticalWall = false;
            float verHitX = 0;
            float verHitY = 0;

            if (isFacingRight) firstIntersectX = std::floor(rayPlayer.x / TILESIZE) * TILESIZE + TILESIZE;
            else if (isFacingLeft) firstIntersectX = std::floor(rayPlayer.x / TILESIZE) * TILESIZE - 0.001;

            firstIntersectY = ((firstIntersectX - rayPlayer.x) * tan(rayAngle)) + rayPlayer.y;

            double nextVerX = firstIntersectX;
            double nextVerY = firstIntersectY;

            if (isFacingRight) xa = TILESIZE;
            if (isFacingLeft) xa = -TILESIZE;

            ya = xa * tan(rayAngle);

            while (nextVerX <= windowWidth && nextVerX >= 0 && nextVerY <= windowHeight && nextVerY >= 0){
                if (rayMap.hasWallAt(nextVerX, nextVerY)){
                    foundVerticalWall= true;
                    verHitX= nextVerX;
                    verHitY = nextVerY;
                    break;
                }
                else{
                    nextVerX += xa;
                    nextVerY += ya;
                }
            }

            // Distance Calculation
            float horDist = 0;
            float verDist = 0;

            if (foundHorizontalWall) horDist = distanceBetween(rayPlayer.x, rayPlayer.y, horHitX, horHitY);
            else horDist = 9999;

            if (foundVerticalWall) verDist = distanceBetween(rayPlayer.x, rayPlayer.y, verHitX, verHitY);
            else verDist = 9999;

            if (horDist < verDist){
                wallHitX = horHitX;
                wallHitY = horHitY;
                dist = horDist;
                color = GRAY;
            }
            else{
                wallHitX = verHitX;
                wallHitY = verHitY;
                dist = verDist;
                color = DARKGRAY;
            }

            dist *= cos(rayPlayer.angle - rayAngle);
            col *= (60 / dist);
            col = Clamp(col, 0, 255);
        }

        void Draw(){
            DrawLine(rayPlayer.x, rayPlayer.y, wallHitX, wallHitY, RED);
        }
};