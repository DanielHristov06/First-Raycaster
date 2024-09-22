#pragma once
#include <settings.h>
#include <Classes/ray.h>
#include <cmath>
#include <vector>

class Raycaster{
    private:
        double normalizeAngle(float angle){
            angle = fmod(angle, 2 * M_PI);
            if (angle <= 0) angle += (2 * M_PI);
            return angle;
        }

    public:
        std::vector<MyRay> rays = {};
        Player& casterPlayer;
        Map casterMap;

        Raycaster(Player& player, Map map) : casterPlayer(player), casterMap(map){}

        ~Raycaster(){}

        void castAllRays(){
            rays.clear();
            double rayAngle = normalizeAngle(casterPlayer.angle - FOV / 2);

            for (int i = 0; i < RAYS; i++){
                MyRay ray = MyRay(casterPlayer, normalizeAngle(rayAngle), casterMap);
                ray.Cast();
                rays.push_back(ray);
                rayAngle = normalizeAngle(rayAngle + FOV / RAYS);
            }
        }

        void Draw(){
            int count = 0;

            for (int i = 0; i < rays.size(); i++){
                //rays[i].Draw();

                float lineHeight = (32 / rays[i].dist) * 415;
                float drawBegin = (windowHeight / 2) - (lineHeight / 2);
                float drawEnd = lineHeight;

                DrawRectangle(count * RES, drawBegin, RES, drawEnd, rays[i].color);

                count++;
            }
        }
};