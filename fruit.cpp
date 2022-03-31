#include "fruit.h"
fruit::fruit(int x_,int y_,console* my_console_)
{
	x = x_;
	y = y_;
	my_console = my_console_;
	el = char(rand()%3+1);
	cost = rand() % 5 + 1;
}
int fruit::get_cost()
{
	return cost;
}