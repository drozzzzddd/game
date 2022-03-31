#pragma once
#include "point.h"
class fruit:public point
{
private :
	int cost;
public:
	fruit(int x,int y,console* my_concole_);
	int get_cost();
};

