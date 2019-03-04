#include "points.h"
#include <time.h>
#include <cstdlib>

void points::create_new_point(int x, int y)
{
	srand(time(NULL));
	this->x = rand() % + x;
	this->y = rand() % + y;
}