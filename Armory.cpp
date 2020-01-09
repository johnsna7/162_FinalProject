/**************************************************
 * File Name: Armory.cpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Base class for Armorys for Final Project
 * ************************************************/

#include "Armory.hpp"
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
 * Class Name: Armory
 * What it does: Allows player to collect
 * arc lamp
 * ******************************************/

// Default Constructor
Armory::Armory() : Space::Space()
{
	name = "Armory";
	roomItem = new Item("Arc Lamp",1);
}

// Destructor, frees item created
Armory::~Armory()
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
void Armory::interact( Player* playerIn )
{
	// Arc lamp already collected, standard room behavior
	if ( visited ) 
	{
		string modeChoice[3];
		modeChoice[0] = "Armory - Already have Arc Lamp! Which mode?";
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

	// Arc lamp not yet collected
	else
	{
		// Create string array for menu
		string modeChoice[4];
		modeChoice[0] = "A guard notices you're ahead of schedule.";
		modeChoice[1] = "Wait 4 hours: -15% battery";
		modeChoice[2] = "Make an excuse: 30% chance to get caught";
		modeChoice[3] = "Bribe the guard: -1 inventory slot";

		// Display menu and store users choice
		int choice = menu(modeChoice, 4);

		// Generate random number
		int detection = die(1,100);

		// Wait
		if ( choice == 1 )
		{
			cout << "\nIt's best to play it safe. Your battery runs";
			cout << " down as you wait.\n";
			playerIn->drainBattery(15);
		}

		// Make excuse
		if ( choice == 2 )
		{
			// Caught
			if ( detection <= 30 )
			{
				cout << "\nThe guard looks at you suspiciously\n...";
				cout << "\n...\nYou have been caught!\n";

				lost = true;
			}

			// Not caught
			else
			{
				cout << "\nThe guard simply rolls his eyes.\n";
				cout << "You got lucky this time!\n";
			}
		}

		// Bribe guard
		if ( choice == 3 )
		{
			cout << "\nYou take a jewel powering your storage system ";
			cout << "and hand it to the guard.\nHe nodds and puts it";
			cout << " in his pocket. Hopefully you won't need it!\n";

			playerIn->drainInventory(1);
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
