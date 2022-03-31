//для того, чтобы что-то рисовать. класс, в котором есть длина, ширина, строка. строка представляет собой матрицу, те она вообще одномерный массив
//но мы представляем как двумерный



#include "console.h"
#include <iostream>
console::console() : width(120),
height(29),
wall(char(219)),
field(' ') {
	view_port.clear();
	view_port.resize(width * height, field);
	for (size_t i = 0; i < width - 1; ++i)
		view_port[i] = view_port[i + width * (height - 1)] = wall;
	for (size_t j = 0; j < height; ++j)
		view_port[j * width] = view_port[j * width + width - 2] = wall;
	for (size_t j = 0; j < height; ++j)
		view_port[j * width + width - 1] = '\n';
}

console::console(int width_, int height_, char wall_, char field_) : width(width_ + 1),
height(height_), wall(wall_),
field(field_) {
	view_port.clear();
	view_port.resize(width * height);
	for (size_t i = 0; i < width - 1; ++i)
		view_port[i] = view_port[i + width * (height - 1)] = wall;
	for (size_t j = 0; j < height; ++j)
		view_port[j * width] = view_port[j * width + width - 2] = wall;
	for (size_t j = 0; j < height; ++j)
		view_port[j * width + width - 1] = '\n';
}
void console::print() {
	std::cout << view_port;
}
void console::draw(int x, int y, char el) {
	if(y*width+x<view_port.length())
		if(x<width-2 && x>=1)
			if (y >= 1 && y < height - 1) {
				view_port[y * width + x] = el;
				return;
			}
	game_over();
}
char console::get_field()
{
	return field;
}
int console::get_heigth()
{
	return height;
}
int console::get_width()
{
	return width;
}
char console::get_el(int x,int y)
{
	if (y * width + x < view_port.length())
		if (x < width - 2 && x >= 1)
			if (y >= 1 && y < height - 1) {
				return view_port[y * width + x];
			}
	game_over();
}