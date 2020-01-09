/**************************************************
 * File Name: Room.cpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Base class for rooms for Final Project
 * ************************************************/

#include "Room.hpp"
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
 * Class Name: Room
 * What it does: Standard hallway, no items
 * Contains pointers to spaces in every
 * direction, name and bool if player
 * has visited before
 * ******************************************/

// Default Constructor
Room::Room() : Space::Space()
{
	name = "Standard Room";
}

// Destructor, frees item created
Room::~Room()
{
}

/**************************************************
 * Function name: interact(Player*)
 * Called By: Game
 * Calls: Nothing
 * Returns: Nothing
 * Description: Controls iteraction for the space
 * ************************************************/
void Room::interact( Player* playerIn )
{
	// Create string array for menu
	string modeChoice[3];
	modeChoice[0] = "Would you like to run in standard or stealth mode?";
	modeChoice[1] = "Standard mode: -5% battery, 20% detection chance";
	modeChoice[2] = "Stealth mode: -10% battery, 5% detection chance";

	// Show menu and get users choice
	int choice = menu(modeChoice, 3);

	// Create rand #
	int detection = die(1,100);

	// Standard mode
	if ( choice == 1 )
	{
		playerIn->drainBattery(5);

		// Detected
		if ( detection <= 20 )
		{
			cout << "\nYou have been detected!";
			cout << " -20% battery to escape\n";
			playerIn->drainBattery(20);
		}

		// Not detected
		else
		{
			cout << "You have escaped detection!\n";
		}
	}

	// Stealth Mode
	if ( choice == 2 )
	{
		playerIn->drainBattery(10);

		// Detected
		if ( detection <= 5 )
		{
			cout << "\nYou have been detected!";
			cout << " -20% battery to escape\n";
			playerIn->drainBattery(20);
		}

		// Not detected
		else
		{
			cout << "You have escaped detection!\n";
		}
	}
}
