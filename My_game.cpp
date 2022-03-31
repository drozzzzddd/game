#include "My_game.h"
#include <iostream>
#include "console.h"
#include "snake.h"
#include "fruit.h"
#include <conio.h>
#include <Windows.h>
void My_game::game()
{
	start_menu();
	system("pause");
	system("cls");
	start_game();

}
void My_game::start_menu()
{
	std::cout << "HI EVERYBODY.\nI'm A SNAKE AND I LOVE FRUITS.\n LETS EAT SOME OF THEM.!!!\nYOU CAN USE ARROWS TO CONTROL ME.\n";
}
void My_game::start_game() {
	srand(time(0));
	console my_console;
	std::vector<fruit> arr_of_fruits;
	snake my_snake(10, 15, char(254), &my_console);
	int i = 0;

	while (true) {

		if (_kbhit())
		{
			int dir = _getch();
			if (dir == 72)
				my_snake.set_dir('n');
			if (dir == 80)
				my_snake.set_dir('s');
			if (dir == 75)
				my_snake.set_dir('w');
			if (dir == 77)
				my_snake.set_dir('e');
		}
		my_snake.draw();
		if (i % 5 == 0 && arr_of_fruits.size() < 15)
		{
			int x, y;
			x = (rand() % (my_console.get_width() - 3)) + 1;
			y = (rand() % (my_console.get_heigth() - 2)) + 1;
			fruit new_fruit(x, y, &my_console);
			arr_of_fruits.push_back(new_fruit);
		}
		for (size_t j = 0; j < arr_of_fruits.size(); ++j)
			arr_of_fruits[j].draw();
		my_snake.step(arr_of_fruits);
		my_console.print();
		++i;
		Sleep(100);
	}

}