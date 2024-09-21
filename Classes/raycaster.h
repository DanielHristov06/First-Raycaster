#pragma once
#include <settings.h>
#include <Classes/ray.h>
#include <cmath>
#include <vector>

class Raycaster{
    public:
        std::vector<MyRay> rays = {};
        Player& casterPlayer;
        Map casterMap;

        Raycaster(Player& player, Map map) : casterPlayer(player), casterMap(map){}

        ~Raycaster(){}

        void castAllRays(){
            rays.clear();
            double rayAngle = casterPlayer.angle - FOV / 2;

            for (int i = 0; i < RAYS; i++){
                MyRay ray = MyRay(casterPlayer, rayAngle, casterMap);
                ray.Cast();
                rays.push_back(ray);
                rayAngle += FOV / RAYS;
            }
        }

        void Draw(){
            for (int i = 0; i < rays.size(); i++){
                rays[i].Draw();
            }
        }
};