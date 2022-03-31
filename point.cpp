#include "point.h"
point::~point()
{
	my_console->draw(x, y, my_console->get_field());
}
point::point()
{
	x = 0;
	y = 0;
	el = ' ';
}
point::point(int x_, int y_, char el_, console* console_) {
	x = x_;
	y = y_;
	el = el_;
	my_console = console_;
}
int point::get_x()
{
	return x;
}
int point::get_y()
{
	return y;
}
void point::set_position(int x_, int y_)
{
	x = x_;
	y = y_;
}
void point::next_position(int dx, int dy)
{
	x += dx;
	y += dy;
}
void point::set_el(char el_)
{
	el = el_;
}
void point::draw() {
	my_console->draw(x, y, el);
}