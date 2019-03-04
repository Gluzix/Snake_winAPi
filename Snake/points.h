#pragma once
class points
{
	int x, y, size;
	int *tab;
public:
	points(int hw_mn_snks, int siz) : size(siz), x(0), y(0)
	{
		tab = new int[hw_mn_snks];
	}
	~points() { delete(tab); }
	void create_new_point(int, int);
	int ret_point_x() { return x; }
	int ret_point_y() { return y; }
	int ret_size() { return size; }
	int ret_nmb_of_points(int o) { return tab[o]; }
};

