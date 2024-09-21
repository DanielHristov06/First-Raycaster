#pragma once
#include <settings.h>
#include <Classes/ray.h>
#include <cmath>
#include <vector>

class Raycaster{
    public:
        std::vector<MyRay> rays = {};
        Player& casterPlayer;

        Raycaster(Player& player) : casterPlayer(player){}

        ~Raycaster(){}

        double shit;

        void castAllRays(){
            rays.clear();
            double rayAngle = casterPlayer.angle - FOV / 2;

            for (int i = 0; i < RAYS; i++){
                MyRay ray = MyRay(casterPlayer, rayAngle);
                ray.Cast();
                rays.push_back(ray);
                rayAngle += FOV / RAYS;
                shit = rayAngle;
            }
        }

        void Draw(){
            for (int i = 0; i < rays.size(); i++){
                DrawText(TextFormat("%i", shit), 64, 64, 64, GREEN);
                rays[i].Draw();
            }
        }
};