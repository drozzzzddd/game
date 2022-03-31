#include "exit_.h"
#include "Windows.h"
void exit_::game_over() {
	system("cls");

	std::cout << "GAME OVER!!!\n";
	system("pause");
	exit(0);
}