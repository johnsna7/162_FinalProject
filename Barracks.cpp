/**************************************************
 * File Name: Barracks.cpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Base class for Barrackss for Final Project
 * ************************************************/

#include "Barracks.hpp"
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
 * Class Name: Barracks
 * What it does: Allows user to collect
 * metal tube
 * ******************************************/

// Default Constructor
Barracks::Barracks() : Space::Space()
{
	name = "Barracks";
	roomItem = new Item("Metal Tube",2);
}

// Destructor, frees item created
Barracks::~Barracks()
{
	delete roomItem;
}

/**************************************************
 * Function name: interact(Player*)
 * Called By: Game
 * Calls: Nothing
 * Returns: Nothing
 * Description: Controls iteraction for the space
 * ************************************************/
void Barracks::interact( Player* playerIn )
{
	// Metal tube already collected, standard room behavior
	if ( visited ) 
	{
		string modeChoice[3];
		modeChoice[0] = "Barracks - Already have Metal Tube! Which mode?";
		modeChoice[1] = "Standard mode: -5% battery, 20% detection chance";
		modeChoice[2] = "Stealth mode: -10% battery, 5% detection chance";

		int choice = menu(modeChoice, 3);

		int detection = die(1,100);

		if ( choice == 1 )
		{
			playerIn->drainBattery(5);

			if ( detection <= 20 )
			{
				cout << "\nYou have been detected!";
				cout << " -20% battery to escape\n";
				playerIn->drainBattery(20);
			}

			else
			{
				cout << "You have escaped detection!\n";
			}
		}

		if ( choice == 2 )
		{
			playerIn->drainBattery(10);

			if ( detection <= 5 )
			{
				cout << "\nYou have been detected!";
				cout << " -20% battery to escape\n";
				playerIn->drainBattery(20);
			}

			else
			{
				cout << "You have escaped detection!\n";
			}
		}
	}

	// Metal tube not yet collected
	else
	{
		// Create string array for menu
		string modeChoice[3];
		modeChoice[0] = "You accidentily run into bob, spilling his lunch.";
		modeChoice[1] = "Clean it up: -10% battery, -1 inventory slot";
		modeChoice[2] = "Ignore it & move on: 20% chance to get caught";

		// Display menu and collect user's choice
		int choice = menu(modeChoice, 3);

		// Create random number
		int detection = die(1,100);

		// Clean
		if ( choice == 1 )
		{
			cout << "\nIt's best to play it safe. You hurriedly store";
			cout << " the mess in your compartment.\n";
			playerIn->drainBattery(10);
			playerIn->drainInventory(1);
		}

		// Ignore
		if ( choice == 2 )
		{
			// Detected
			if ( detection <= 20 )
			{
				cout << "\nBob yells \"You 'aint even gonna clean ";
				cout << "it up?!\nWhat use are you!!\"\n...";
				cout << "\n...\nYou have been caught!\n";

				lost = true;
			}

			// Not detected
			else
			{
				cout << "\nBob shouts angrily \"Stupid robots!\"\n";
				cout << "You got lucky this time!\n";
			}
		}

		// Add item
		if ( !lost && playerIn->slots() )
		{
			cout << "\nMetal Tube found!\n";
			playerIn->addItem(roomItem);
		}

		// No inventory slots remaining
		else
		{
			lost = true;
		}

		visited = true;
	}
}
