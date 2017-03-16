#ifndef include_h
#define include_h

#include <SFML/Graphics.hpp>

static const int WINDOW_SIZE_X = 2873;
static const int WINDOW_SIZE_Y = 1575;

static const double MAX_VELOCITY    = 10;
static const double BULLET_VELOCITY = 7;

static const int BULLET_RADIUS = 10;

/*
fixit: нужно измерить время между кадрами, а не харкодить явно его
*/
static const double DIFF_TIME = 0.2;

#endif /* include_h */
