#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <raylib.h>

#define dt GetFrameTime() * 60

const int TILESIZE = 32;
const int ROWS = 20;
const int COLS = 25;
const int windowWidth = COLS * TILESIZE;
const int windowHeight = ROWS * TILESIZE;
const float FOV = 60 * (M_PI / 180);
const int RES = 4;
const float RAYS = std::floor(windowWidth / RES);