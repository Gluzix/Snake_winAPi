#pragma once
class snake
{
	int  rozmiar, x, y, boost, kierunek, last_kierunek, counter, static_x,
		static_y, counter_2, predkosc, last_x, last_y, counter_3, number_of_lives;
	bool only_once, if_the_wall;
public:
	snake(int pp1, int pp2, int rzm, int predk, int krnk, int cntr, int lvs) :x(pp1), y(pp2), rozmiar(rzm),
		predkosc(predk), kierunek(krnk), counter(cntr), counter_2(0), counter_3(0), static_x(300), static_y(300), only_once(false), if_the_wall(false),
		number_of_lives(lvs)
	{
		last_kierunek = kierunek;
	};
	~snake();
	int return_x();
	int return_y();
	int return_kierunek();
	int return_last_kierunek();
	int return_rozmiar();
	int return_static_x() { return static_x; }
	int return_static_y() { return static_y; }
	int return_cnt(){ return counter; }
	int return_cnt_2() { return counter_2; }
	int return_cnt_3() { return counter_3; }
	int return_nmb_of_lvs() { return number_of_lives; }
	bool return_if_the_wall() { return if_the_wall; }
	bool return_only_once() { return only_once; }
	void dec_nmb_of_lvs() { number_of_lives--; }
	void ustaw_if_the_wall(bool iftw) { if_the_wall = iftw; }
	void inc_cnt_3() { counter_3++; }
	void zero_cnt_3() { counter_3 = 0; }
	void ustaw_kierunek(int);
	void ustaw_x(int);
	void ustaw_y(int);
	void add_to_cntr() 
	{ 
		this->counter++; 
		only_once = true; 
	};
	void check_kierunek();
	void insert_last_kierunek();
	void insert_static_x_y()
	{
		static_x = this->x;
		static_y = this->y;
	}
	void increment_counter() { counter_2++; }
	void zero_counter() { counter_2 = 0; }
	void increment_x() { x += predkosc; }
	void increment_y() { y += predkosc; }
	void decrement_x() { x -= predkosc; }
	void decrement_y() { y -= predkosc; }
	void insert_kierunek(int krnk) { kierunek = krnk; }
	void insert_last_x() { last_x = this->x; }
	void insert_last_y() { last_y = this->y; }
};



//0-góra
//1-dó³
//2-prawo
//3-lewo