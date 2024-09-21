#define _USE_MATH_DEFINES
#include <math.h>

const int TILESIZE = 32;
const int ROWS = 20;
const int COLS = 25;
const int windowWidth = COLS * TILESIZE;
const int windowHeight = ROWS * TILESIZE;
const int FOV = 60 * (M_PI / 180);
const int RES = 4;
const int RAYS = windowWidth / RES;