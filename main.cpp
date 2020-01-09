/******************************************
 * File Name: main.cpp
 * Author: Nathan Johnson
 * Date: 06.07.2019
 * Description: Game for the player
 * to collect parts for a laser to blow
 * up a ship.
 * ****************************************/

#include "menu.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	// Seed random generator
	unsigned seed = time(0);
	srand(seed);

	int menuChoice = 0;

	// Loop the menu until user selects exit
	while ( menuChoice != 2 )
	{
		menuChoice = menu();
	}

	return 0;
}
