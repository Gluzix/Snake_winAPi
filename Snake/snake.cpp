#include "snake.h"

snake::~snake()
{
}

void snake::check_kierunek()
{
	if (kierunek == 0)
	{
		y-=predkosc;
	}
	else if (kierunek == 1)
	{
		y+=predkosc;
	}
	else if (kierunek == 2)
	{
		x+=predkosc;
	}
	else if (kierunek == 3)
	{
		x-=predkosc;
	}
}

int snake::return_kierunek()
{
	return kierunek;
}

int snake::return_x()
{
	return x;
}

int snake::return_y()
{
	return y;
}

int snake::return_rozmiar()
{
	return rozmiar;
}

void snake::ustaw_x(int x)
{
	this->x = x;
}

void snake::ustaw_y(int y)
{
	this->y = y;
}

void snake::ustaw_kierunek(int kierunek)
{
	this->kierunek = kierunek;
}

void snake::insert_last_kierunek()
{
	last_kierunek = kierunek;
}

int snake::return_last_kierunek()
{
	return last_kierunek;
}
