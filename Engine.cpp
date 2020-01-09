/**************************************************
 * File Name: Engine.cpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Derived from Space class
 * ************************************************/

#include "Engine.hpp"
#include "Space.hpp"
#include "Item.hpp"
#include "Player.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::end;
using std::string;

/********************************************
 * Class Name: Engine
 * What it does: Interaction to have a chance
 * to win the game if the user has built a laser
 * ******************************************/

// Default Constructor
Engine::Engine() : Space::Space()
{
	name = "Engine Room";
}

// Destructor, frees item created
Engine::~Engine()
{
}

/**************************************************
 * Function name: interact(Player*)
 * Called By: Game
 * Calls: Nothing
 * Returns: Nothing
 * Description: Controls iteraction for the space
 * ************************************************/
void Engine::interact( Player* playerIn )
{
	// If player has components for laser
	if ( playerIn->hasLaser() )
	{
		// Create menu array
		string modeChoice[3];
		modeChoice[0] = "You have 1 shot! Where do you aim?";
		modeChoice[1] = "Fire the laser at the reactor";
		modeChoice[2] = "Fire the laser at the engine core";

		// Show interaction menu, user selects option
		int choice = menu(modeChoice, 3);

		// Fire at reactor
		if ( choice == 1 )
		{
			cout << "\nThe reactor instantly explodes!!\n";
			cout << "Goodbye poor robot, you have served well\n";
			won = true;
		}

		// Fire at engine core
		if ( choice == 2 )
		{
			cout << "\nThe engine has been crippled!\n";
			cout << "Alarm bells go off and you are captured.\n";
			cout << "Unfortunately, the ship remains intact!\n";
			lost = true;
		}

	}

	// Player doesn't have laser components
	else
	{
		// create menu array
		string modeChoice[3];
		modeChoice[0] = "You arrive at your destination with no laser!";
		modeChoice[1] = "Leave the room";
		modeChoice[2] = "Suicide into the reactor";

		// Show interaction menu
		int choice = menu(modeChoice, 3);

		// create rand # b/t 1-100
		int detection = die(1,100);

		// Leave the room
		if ( choice == 1 )
		{
			cout << "\nYou look around before heading elsewhere.\n";
			playerIn->drainBattery(10);
		}

		// Suicide into the reactor
		if ( choice == 2 )
		{
			// Unsuccesful
			if ( detection <= 90 )
			{
				cout << "\nYou speed at the reactor as fast ";
				cout << "as you can\n...\nPlink!\n";
				cout << "Your mind returns as the robot ";
				cout << "crumbles,\nbut you realize";
				cout << " no damage was done.\n";
				lost = true;
			}

			// Success
			else
			{
				cout << "\nYou self destruct as you speed ";
				cout << "toward the reactor, and somehow\n";
				cout << "set off a chain reaction!\nBOOM!!\n";
				won = true;
			}
		}
	}

	visited = true;
}
