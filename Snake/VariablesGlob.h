HWND hwnd = NULL;
MSG msg;

RECT rect;
HPEN Pen[3], PenBox[3];
HBRUSH PenBrush[3], BrushBox[3];
COLORREF snk_color = RGB(255, 255, 255), snk_clr_brsh = RGB(255, 255, 255), eyes_color = RGB(0, 0, 0), map_color = RGB(0, 127, 0), point_color = RGB(255, 255, 0);
PAINTSTRUCT ps;
bool if_in_the_wall = FALSE;
bool if_turning = FALSE, only_onc = false, start_counting = false, only_one_colision = false, ifpoint_eaten = false;
char buforek[100];
int how_long = 12, counter_to_chng_clr=0;