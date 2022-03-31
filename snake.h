//���� ����� - ����� �� ������� �����, �� �������� �� ���� �������, �� ����, � ������� �������� ����, �� ��� �� ������������ ��� �������� �����
//������ � ������. � ���� ������ � � ������ � - ��� �����������, � ������� �� ������ ������ ( �� ������ ����) �������� ����. 


#pragma once
#include "figur.h"
#include "point.h"
#include "fruit.h"
#include <vector>
class snake :public figur
{
private:
	std::vector<point> arr_of_s_el;
	console* my_console;
	char head_el, body_el, tail_el;
	int dx, dy;
public:
	snake();
	snake(int x, int y,char body_el_,console* my_console_);
	void draw();
	void set_dir(char dir);
	void step(std::vector<fruit>&my_fruits);
	void inc_s_len();
};

