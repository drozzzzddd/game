#include "snake.h"
#include <vector>
#include "fruit.h"
snake::snake() : head_el(char(16)), body_el(char(219)), tail_el(char(17))
{
	arr_of_s_el.push_back(point(100, 15, head_el, my_console));
}
snake::snake(int x, int y, char body_el_, console* my_console_):
	body_el(body_el_),
	my_console(my_console_),
	dx(1),
	dy(0),
	head_el(char(16)),
	tail_el(char(17))
{
	arr_of_s_el.push_back(point(x,y,head_el,my_console));
}
void snake::draw()
{
	for (size_t i = 0; i < arr_of_s_el.size(); ++i)
		arr_of_s_el[i].draw();
}
void snake::set_dir(char dir)
{
	if (dir == 'n')
	{
		dx = 0;
		dy = -1;
		head_el = char(30);
	}
	if (dir == 's')
	{
		dx = 0;
		dy = 1;
		head_el = char(31);
	}
	if (dir == 'w')
	{
		dx = -1;
		dy = 0;
		head_el = char(17);
	}
	if (dir == 'e')
	{
		dx = 1;
		dy = 0;
		head_el = char(16);
	}
}
void snake::step(std::vector<fruit> &my_fruits)
{
	for (int i = arr_of_s_el.size() - 1; i >= 0; i--)
	{
		if (i == arr_of_s_el.size() - 1) {
			arr_of_s_el[i].set_el(my_console->get_field());
			arr_of_s_el[i].draw();
		}
		if (i == 0) {
			arr_of_s_el[i].next_position(dx, dy);
			if (my_console->get_el(arr_of_s_el[i].get_x(), arr_of_s_el[i].get_y()) != my_console->get_field())
			{
				for(size_t j=0;j<my_fruits.size();j++)
					if (my_fruits[j].get_x() == arr_of_s_el[i].get_x() && my_fruits[j].get_y() == arr_of_s_el[i].get_y())
					{
						for (int l = 0; l < my_fruits[j].get_cost(); ++l)
							inc_s_len();
						my_fruits.erase(my_fruits.begin() + j);
						j--;
					}
			}
			arr_of_s_el[i].set_el(head_el);
		}
		else {
			if (i == arr_of_s_el.size() - 1)
			{
				int dx_, dy_;
				dx_ = arr_of_s_el[i-1].get_x() - arr_of_s_el[i ].get_x();
				dy_ = arr_of_s_el[i-1].get_y() - arr_of_s_el[i ].get_y();
				if (dy_ == -1)
					tail_el = char(31);
				if (dy_ == 1)
					tail_el = char(30);
				if (dx_ == -1)
					tail_el = char(16);
				if (dx_ == 1)
					tail_el = char(17);
				arr_of_s_el[i].set_el(tail_el);
				arr_of_s_el[i].set_position(arr_of_s_el[i - 1].get_x(), arr_of_s_el[i - 1].get_y());
			}
			else
			{
				arr_of_s_el[i].set_position(arr_of_s_el[i - 1].get_x(), arr_of_s_el[i - 1].get_y());
				arr_of_s_el[i].set_el(body_el);
			}
			if (arr_of_s_el[0].get_x() + dx == arr_of_s_el[i].get_x() && arr_of_s_el[0].get_y() + dy == arr_of_s_el[i].get_y()) {
				game_over();
			}
			}
	}
	draw();
}
void snake::inc_s_len()
{
	arr_of_s_el.push_back(arr_of_s_el.back());
}
