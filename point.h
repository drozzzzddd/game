//это координаты по х и у, символ который в них находится, и указатель на консоль, в которую точка адресовывается

#pragma once
#include "figur.h"
#include "console.h"
class point:public figur
{
protected:
	console* my_console;
	int x, y;
	char el;
public:
	~point();
	point();
	point(int x_, int y_, char el_, console* console_);
	int get_x();
	int get_y();
	void set_position(int x_, int y_);
	void next_position(int dx, int dy);
	void set_el(char el_);
	void draw();
};

