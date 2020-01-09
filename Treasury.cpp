/**************************************************
 * File Name: Treasury.cpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Base class for Treasurys for Final Project
 * ************************************************/

#include "Treasury.hpp"
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
 * Class Name: Treasury
 * What it does: Allows user to collect
 * sapphire
 * ******************************************/

// Default Constructor
Treasury::Treasury() : Space::Space()
{
	name = "Treasury";
	roomItem = new Item("Sapphire",4);
}

// Destructor, frees item created
Treasury::~Treasury()
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
void Treasury::interact( Player* playerIn )
{
	// User has collected sapphire already
	// Standard room behavior
	if ( visited ) 
	{
		string modeChoice[3];
		modeChoice[0] = "Treasury - Already have Sapphire! Which mode?";
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

	// First time in room
	else
	{
		// Create string array for menu
		string modeChoice[3];
		modeChoice[0] = "You see the sapphire sitting on a shelf.";
		modeChoice[1] = "Sneak it: -20% battery";
		modeChoice[2] = "Knock down the shelf: -2 inventory slots";

		// Show menu and return users choice
		int choice = menu(modeChoice, 3);

		// Sneak sapphire
		if ( choice == 1 )
		{
			cout << "\nIt's best to play it safe. You wait a while";
			cout << " until no one is paying attention,\n";
			cout << "then swipe the sapphire and leave.\n";
			playerIn->drainBattery(20);
		}

		// Knock down shelf
		if ( choice == 2 )
		{
			cout << "\nYou bump into the shelf and knock it over,\n";
			cout << "exclaiming \"Oh no!\" You quickly clean up ";
			cout << "the debris,\nincluding the sapphire.\n";
			playerIn->drainInventory(2);
		}

		// Add item
		if ( playerIn->slots() )
		{
			playerIn->addItem(roomItem);
		}

		// No item slots remaining
		else
		{
			lost = true;
		}

		visited = true;
	}
}
