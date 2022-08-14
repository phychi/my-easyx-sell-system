#include "function.h"
void emptyStructure(information* pt)
{
	strcpy_s(pt->start_station, 20, "");
	strcpy_s(pt->end_station, 20, "");
	for (int i = 0; i < 3; i++)
	{
		pt->start_state[i] = -1;
		pt->end_state[i] = -1;
	}
	pt->the_start_state = false;
	pt->the_end_state = false;
	pt->ticket_state = false;
	pt->distance = 0;
	pt->ticket = 0;
	pt->money = 0;
}
bool is_on(int x1, int y1, int x2, int y2)
{
	if (m_msg.x > x1 && m_msg.x < x2 && m_msg.y > y1 && m_msg.y < y2)
		return true;
	else
		return false;
}

bool is_click(int x1, int y1, int x2, int y2)
{
	if (is_on(x1, y1, x2, y2))
	{
		if (m_msg.message == WM_LBUTTONDOWN)
			return true;
		else
			return false;
	}
	else
		return false;
}

void button(int x1, int y1, int x2, int y2, const char TextStyle[10], int TextHeight, const char word[20], int r)
{
	setfillcolor(RGB(124, 228, 255));
	fillroundrect(x1, y1, x2, y2, r, r);
	settextcolor(BLACK);
	settextstyle(TextHeight, 0, TextStyle);
	int position_x = (x2 + x1 - textwidth(word)) / 2;
	int position_y = (y1 + y2 - textheight(word)) / 2;
	outtextxy(position_x, position_y, word);
}