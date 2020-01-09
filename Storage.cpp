/**************************************************
 * File Name: Storage.cpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Base class for Storages for Final Project
 * ************************************************/

#include "Storage.hpp"
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
 * Class Name: Storage
 * What it does: Let's player collect mirror
 * or recharge battery
 * ******************************************/

// Default Constructor
Storage::Storage() : Space::Space()
{
	name = "Storage";
	roomItem = new Item("Mirror",3);
}

// Destructor, frees item created
Storage::~Storage()
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
void Storage::interact( Player* playerIn )
{
	// Create string array for menu
	string modeChoice[3];
	modeChoice[0] = "Storage Room - What do you do?";
	modeChoice[1] = "Collect Mirror";
	modeChoice[2] = "Recharge Battery";

	// Display menu and store users choice
	int choice = menu(modeChoice, 3);

	// Collect mirror
	if ( choice == 1 )
	{
		// Mirror already collected
		if ( visited )
		{
			cout << "\nYou already collected the mirror here!\n";
			cout << "Time to move on.\n";
		}

		// Mirror not yet collected
		else
		{
			if ( !lost && playerIn->slots() )
			{
				playerIn->addItem(roomItem);
				cout << "\nMirror collected!\n";
			}
			
			else
			{
				lost = true;
			}
			

			visited = true;
		}
	}

	// Recharge battery
	if ( choice == 2 )
	{
		cout << "\nBattery replenished, you feel much better!\n";
		playerIn->chargeBattery();
	}

}