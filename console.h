#pragma once

#include <string>
#include "figur.h"
#include "exit_.h"
class console:public exit_{
private:
	const int width; 
	const int height;
	std::string view_port;
	const char wall, field;
public:
	console();
	console(int width_, int height_, char wall_ = char(219), char field_ = ' ');
	void print();
	void draw(int x, int y, char el);
	char get_field();
	int get_width();
	int get_heigth();
	char get_el(int x, int y);

};


