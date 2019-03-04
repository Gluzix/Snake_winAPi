#include <Windows.h>
#include <vector>
#include "snake.h"
#include "points.h"
#include "ConstantsGlob.h"
#include "VariablesGlob.h"

using namespace std;

snake snk1(beg_x, beg_y, rozmiar, predkosc, kierunek, counter_first, nmbr_of_lvs);
points pnt1(1,10);
vector <snake> tab;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

void counting_to_chng_color_back()
{
	if (start_counting == true)
	{
		counter_to_chng_clr++;
		if (counter_to_chng_clr == 50)
		{
			snk_color = RGB(255, 255, 255);
			snk_clr_brsh = RGB(255, 255, 255);
			start_counting = false;
			only_one_colision = false;
			counter_to_chng_clr = 0;
		}
	}
}

void collision_with_point()
{
	
}

void collision_with_own_body()
{
	for (int i = 0; i < how_long; i++)
	{
		switch (snk1.return_kierunek())
		{
		case 0:
			//Góra
				if ( (snk1.return_x() >= tab[i].return_x()) && (snk1.return_x() <= tab[i].return_x()+tab[i].return_rozmiar()) 
					&&(snk1.return_y() <= tab[i].return_y() + tab[i].return_rozmiar()) 
					&&(snk1.return_y() >= tab[i].return_y())&&(only_one_colision==false) )
				{
					snk_color = RGB(255, 0, 0);
					snk_clr_brsh = RGB(255, 0, 0);
					start_counting = true;
					only_one_colision = true;
					snk1.dec_nmb_of_lvs();
				}
			break;
		case 1:
			if ((snk1.return_x() >= tab[i].return_x()) && (snk1.return_x() <= tab[i].return_x() + tab[i].return_rozmiar())
				&& (snk1.return_y() + tab[i].return_rozmiar() >= tab[i].return_y() )
				&& (snk1.return_y() + tab[i].return_rozmiar() <= tab[i].return_y() + tab[i].return_rozmiar()) && (only_one_colision == false))
			{
				snk_color = RGB(255, 0, 0);
				snk_clr_brsh = RGB(255, 0, 0);
				start_counting = true;
				only_one_colision = true;
				snk1.dec_nmb_of_lvs();
			}
			//Dó³
			break;
		case 2:
			if ((snk1.return_y() >= tab[i].return_y()) && (snk1.return_y() <= tab[i].return_y() + tab[i].return_rozmiar())
				&& (snk1.return_x() + snk1.return_rozmiar() >= tab[i].return_x())
				&& (snk1.return_x() + snk1.return_rozmiar() <= tab[i].return_x() + tab[i].return_rozmiar()) && (only_one_colision == false))
			{
				snk_color = RGB(255, 0, 0);
				snk_clr_brsh = RGB(255, 0, 0);
				start_counting = true;
				only_one_colision = true;
				snk1.dec_nmb_of_lvs();
			}
			//Prawo
			break;
		case 3:
			//Lewo
			if ((snk1.return_y() >= tab[i].return_y()) && (snk1.return_y() <= tab[i].return_y() + tab[i].return_rozmiar())
				&& (snk1.return_x() <= tab[i].return_x() + tab[i].return_rozmiar() )
				&& (snk1.return_x() >= tab[i].return_x()) && (only_one_colision == false))
			{
				snk_color = RGB(255, 0, 0);
				snk_clr_brsh = RGB(255, 0, 0);
				start_counting = true;
				only_one_colision = true;
				snk1.dec_nmb_of_lvs();
			}
			break;
		}
	}
}

void draw_lives_of_snakes(HDC mdc)
{
	sprintf_s(buforek, "nr. 1 lives: %2d points: %d", snk1.return_nmb_of_lvs(), 0);
	TextOutA(mdc, 0, 0, buforek, 36);
}

void add_to_vector()
{
	snake snkb(-20, -20, rozmiar, predkosc, kierunek, counter_first, 0);
	tab.push_back(snkb);
}

void draw_face(HDC mdc, snake &snk1)
{
	Pen[1] = CreatePen(PS_SOLID, 2, eyes_color);
	PenBox[1] = (HPEN)SelectObject(mdc, Pen[1]);

	switch (snk1.return_kierunek())
	{
	case 0:	
		Rectangle(mdc, snk1.return_x() + 4, snk1.return_y() + 2, snk1.return_x() + 6, snk1.return_y() + 4);
		Rectangle(mdc, snk1.return_x() + snk1.return_rozmiar() - 6, snk1.return_y() + 2, snk1.return_x() + snk1.return_rozmiar() - 4, snk1.return_y() + 4);
		break;
	case 1:
		Rectangle(mdc, snk1.return_x() + 4, snk1.return_y() + snk1.return_rozmiar() - 2, snk1.return_x() + 6, snk1.return_y() + snk1.return_rozmiar() - 4);
		Rectangle(mdc, snk1.return_x() + snk1.return_rozmiar() - 6, snk1.return_y() + snk1.return_rozmiar() - 2, snk1.return_x() + snk1.return_rozmiar() - 4, snk1.return_y() + snk1.return_rozmiar() - 4);
		break;
	case 2:
		Rectangle(mdc, snk1.return_x() + snk1.return_rozmiar() - 2, snk1.return_y() + 4, snk1.return_x() + snk1.return_rozmiar() - 4, snk1.return_y() + 6);
		Rectangle(mdc, snk1.return_x() + snk1.return_rozmiar() - 2, snk1.return_y() + snk1.return_rozmiar() - 6, snk1.return_x() + snk1.return_rozmiar() - 4, snk1.return_y() + snk1.return_rozmiar() - 4);
		break;
	case 3:
		Rectangle(mdc, snk1.return_x() + 2, snk1.return_y() + 4, snk1.return_x() + 4, snk1.return_y() + 6);
		Rectangle(mdc, snk1.return_x() + 2, snk1.return_y() + snk1.return_rozmiar()-6, snk1.return_x() + 4, snk1.return_y() + snk1.return_rozmiar() - 4);
		break;
	}
	SelectObject(mdc, PenBox[1]);
	DeleteObject(Pen[1]);
	DeleteObject(PenBox[1]);
}
//0-góra
//1-dó³
//2-prawo
//3-lewo

void draw(HDC mdc, snake &snk1)
{
	snk1.check_kierunek();
	if ((snk1.return_y() + snk1.return_rozmiar() < rect.top) && (if_in_the_wall == FALSE))
	{		
		snk1.ustaw_y(rect.bottom);
		if_in_the_wall = TRUE;
	}
	else if ((snk1.return_y() > rect.bottom) && (if_in_the_wall == FALSE))
	{
		snk1.ustaw_y(rect.top - snk1.return_rozmiar());
		if_in_the_wall = TRUE;
	}
	else if ((snk1.return_x() + snk1.return_rozmiar() < rect.left) && (if_in_the_wall == FALSE))
	{
		snk1.ustaw_x(rect.right);
		if_in_the_wall = TRUE;
	}
	else if ((snk1.return_x() > rect.right) && (if_in_the_wall == FALSE))
	{
		snk1.ustaw_x(rect.left - snk1.return_rozmiar());
		if_in_the_wall = TRUE;
	}
	if ((snk1.return_x() + snk1.return_rozmiar() < rect.right - 2) &&
		(snk1.return_x() > rect.left + 2) &&
		(snk1.return_y() + snk1.return_rozmiar() < rect.bottom - 2) &&
		(snk1.return_y() > rect.top + 2))if_in_the_wall = FALSE;
	Rectangle(mdc, snk1.return_x(), snk1.return_y(), snk1.return_x() + snk1.return_rozmiar(), snk1.return_y() + snk1.return_rozmiar());
}

void draw_more(HDC mdc, snake & snk1, snake & snkb1)
{
	if (snk1.return_kierunek() != snk1.return_last_kierunek())
	{
		switch (snk1.return_last_kierunek())
		{
		case 0:
			Rectangle(mdc, snk1.return_static_x(), snk1.return_static_y(), snk1.return_static_x() + 20, snk1.return_static_y() + 20);
			snkb1.decrement_y();
			Rectangle(mdc, snkb1.return_x(), snkb1.return_y(), snkb1.return_x() + snkb1.return_rozmiar(), snkb1.return_y() + snkb1.return_rozmiar());
			break;
		case 1:
			Rectangle(mdc, snk1.return_static_x(), snk1.return_static_y() , snk1.return_static_x() + 20, snk1.return_static_y() + 20);
			snkb1.increment_y();
			Rectangle(mdc, snkb1.return_x(), snkb1.return_y(), snkb1.return_x() + snkb1.return_rozmiar(), snkb1.return_y() + snkb1.return_rozmiar());
			break;
		case 2:
			Rectangle(mdc, snk1.return_static_x(), snk1.return_static_y() , snk1.return_static_x() + 20, snk1.return_static_y() + 20);
			snkb1.increment_x();
			Rectangle(mdc, snkb1.return_x(), snkb1.return_y(), snkb1.return_x() + snkb1.return_rozmiar(), snkb1.return_y() + snkb1.return_rozmiar());
			break;
		case 3:
			Rectangle(mdc, snk1.return_static_x(), snk1.return_static_y() , snk1.return_static_x() + 20, snk1.return_static_y() + 20);
			snkb1.decrement_x();
			Rectangle(mdc, snkb1.return_x(), snkb1.return_y(), snkb1.return_x() + snkb1.return_rozmiar(), snkb1.return_y() + snkb1.return_rozmiar());
			break;
		}
		snkb1.increment_counter();
		if (snkb1.return_cnt_2() > snk1.return_cnt())
		{
			snk1.insert_last_kierunek();
			snkb1.insert_last_kierunek();
			snkb1.zero_counter();
		}
	}
	else
	{
		snkb1.ustaw_kierunek(snk1.return_kierunek());
		snk1.insert_static_x_y();
			switch (snk1.return_kierunek())
			{
			case 0:
				if (snk1.return_y() < rect.top-18)
				{
					snkb1.ustaw_if_the_wall(true);
				}
				if (snkb1.return_if_the_wall()==true)
				{
					if (snkb1.return_cnt_3() > 10)
					{
						snkb1.zero_cnt_3();
						snkb1.ustaw_if_the_wall(false);
					}
					else
					{
						snkb1.decrement_y();
						snkb1.inc_cnt_3();
					}
				}
				else
				{
					snkb1.ustaw_y(snk1.return_y() + snk1.return_rozmiar());
					snkb1.ustaw_x(snk1.return_x());
				}
				break;
			case 1:
				if (snk1.return_y() > rect.bottom-2)
				{
					snkb1.ustaw_if_the_wall(true);
				}
				if (snkb1.return_if_the_wall() == true)
				{
					if (snkb1.return_cnt_3() > 10)
					{
						snkb1.zero_cnt_3();
						snkb1.ustaw_if_the_wall(false);
					}
					else
					{
						snkb1.increment_y();
						snkb1.inc_cnt_3();
					}
				}
				else
				{
					snkb1.ustaw_y(snk1.return_y() - snk1.return_rozmiar());
					snkb1.ustaw_x(snk1.return_x());
				}
				break;
			case 2:
				if (snk1.return_x() > rect.right - 2)
				{
					snkb1.ustaw_if_the_wall(true);
				}
				if (snkb1.return_if_the_wall() == true)
				{
					if (snkb1.return_cnt_3() > 10)
					{
						snkb1.zero_cnt_3();
						snkb1.ustaw_if_the_wall(false);
					}
					else
					{
						snkb1.increment_x();
						snkb1.inc_cnt_3();
					}
				}
				else
				{
					snkb1.ustaw_x(snk1.return_x() - snk1.return_rozmiar());
					snkb1.ustaw_y(snk1.return_y());
				}
				break;
			case 3:
				if (snk1.return_x() < rect.left - 18)
				{
					snkb1.ustaw_if_the_wall(true);
				}
				if (snkb1.return_if_the_wall() == true)
				{
					if (snkb1.return_cnt_3() > 10)
					{
						snkb1.zero_cnt_3();
						snkb1.ustaw_if_the_wall(false);
					}
					else
					{
						snkb1.decrement_x();
						snkb1.inc_cnt_3();
					}
				}
				else
				{
					snkb1.ustaw_x(snk1.return_x() + snk1.return_rozmiar());
					snkb1.ustaw_y(snk1.return_y());
				}
				break;
			}
	}
	Rectangle(mdc, snkb1.return_x(), snkb1.return_y(), snkb1.return_x() + snkb1.return_rozmiar(), snkb1.return_y() + snkb1.return_rozmiar());
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR ilCmdLine, int nCmdShow)
{
	WNDCLASSEX window;
	window.cbClsExtra = NULL;
	window.cbSize = sizeof(WNDCLASSEX);
	window.cbWndExtra = NULL;
	window.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	window.hCursor = LoadCursor(NULL, IDC_ARROW);
	window.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	window.hIconSm = NULL;
	window.hInstance = hInstance;
	window.lpfnWndProc = WndProc;
	window.lpszClassName = Class_Name;
	window.lpszMenuName = 0;
	window.style = CS_VREDRAW | CS_HREDRAW;

	RegisterClassEx(&window);

	hwnd = ((CreateWindowEx(WS_EX_WINDOWEDGE, Class_Name, Title,
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU , CW_USEDEFAULT, CW_USEDEFAULT,
		800, 700, NULL, NULL, hInstance, NULL)));

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	UnregisterClass(Class_Name, hInstance);
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		SetTimer(hwnd, ID_TIMER, 1, NULL);
		HDC hdc, mdc;
		HBITMAP hbm, hbmOld;
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		mdc = CreateCompatibleDC(hdc);
		hbm = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
		hbmOld = (HBITMAP)SelectObject(mdc, hbm);
		FillRect(mdc, &rect, (HBRUSH)CreateSolidBrush(map_color));
		//Powy¿sze funkcje potrzebne s¹ do wykorzystania podwójnego buforowania
		//Poni¿ej znajduj¹ siê funkcje odpowiedzialne za rysowanie wê¿a oraz punktów

		if (ifpoint_eaten == false)
		{
			pnt1.create_new_point(rect.right, rect.bottom);
			ifpoint_eaten = true;
		}
			Pen[2] = CreatePen(PS_SOLID, 2, point_color);
			PenBrush[2] = CreateSolidBrush(point_color);
			PenBox[2] = (HPEN)SelectObject(mdc, Pen[2]);
			BrushBox[2] = (HBRUSH)SelectObject(mdc, PenBrush[2]);
			Rectangle(mdc, pnt1.ret_point_x(), pnt1.ret_point_y(), pnt1.ret_point_x() + pnt1.ret_size(), pnt1.ret_point_y() + pnt1.ret_size());
			SelectObject(mdc, PenBox[2]);
			DeleteObject(Pen[2]);
			DeleteObject(PenBox[2]);
			SelectObject(mdc, BrushBox[2]);
			DeleteObject(PenBrush[2]);
			DeleteObject(BrushBox[2]);

		if (!only_onc)
		{
			for (int i = 0; i < how_long; i++)
			{
				add_to_vector();
			}
			only_onc = true;
		}
		Pen[0] = CreatePen(PS_SOLID, 0, snk_color);
		PenBox[0] = (HPEN)SelectObject(mdc, Pen[0]);

		PenBrush[0] = CreateSolidBrush(snk_clr_brsh);
		BrushBox[0] = (HBRUSH)SelectObject(mdc, PenBrush[0]);

		if (snk1.return_kierunek() == snk1.return_last_kierunek())
		{
			if_turning = FALSE;
		}
		draw(mdc, snk1); //Rysuje G³owê snake

		collision_with_own_body(); //Sprawdza czy siê nie zderzy³ z w³asnym cia³em
		counting_to_chng_color_back();

		for (int i = 0; i < how_long; i++)
		{
			if(i==0) draw_more(mdc, snk1, tab[i]);//Funckja rysuje cia³o snake(resztê obiektów)
			else draw_more(mdc, tab[i-1], tab[i]);
		}
		draw_face(mdc, snk1); //Rysuje oczy snake
		draw_lives_of_snakes(mdc);//Rysuje kordy snake

		SelectObject(mdc, PenBox[0]);
		DeleteObject(Pen[0]);
		DeleteObject(PenBox[0]);
		SelectObject(mdc, BrushBox[0]);
		DeleteObject(PenBrush[0]);
		DeleteObject(BrushBox[0]);

		BitBlt(hdc, 0, 0, rect.right, rect.bottom, mdc, 0, 0, SRCCOPY);
		EndPaint(hwnd, &ps);
		SelectObject(mdc, hbmOld);
		DeleteObject(hbm);
		DeleteDC(mdc);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_TIMER:
		InvalidateRect(hwnd, NULL, FALSE);
		break;
	case WM_KEYDOWN:
		switch (int(wParam))
		{
		case 0x25: //LEFT
			if ((if_in_the_wall != TRUE) && (if_turning == FALSE)&&(snk1.return_last_kierunek()!=2))
			{
				snk1.ustaw_kierunek(3);
				if_turning = TRUE;
			}
			break;
		case 0x26: //UP
			if ((if_in_the_wall != TRUE) && (if_turning==FALSE) && (snk1.return_last_kierunek() != 1))
			{
				snk1.ustaw_kierunek(0);
				if_turning = TRUE;
			}
			break;
		case 0x27: //RIGHT
			if ((if_in_the_wall != TRUE) && (if_turning == FALSE) && (snk1.return_last_kierunek() != 3))
			{
				snk1.ustaw_kierunek(2);
				if_turning = TRUE;
			}
			break;
		case 0x28: //DOWN
			if ((if_in_the_wall != TRUE) && (if_turning == FALSE) && (snk1.return_last_kierunek() != 0))
			{
				snk1.ustaw_kierunek(1);
				if_turning = TRUE;
			}
			break;
		}
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}