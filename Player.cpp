/***********************************************
 * File Name: Player.cpp
 * Author: Nathan Johnson
 * Date: 06.08.2019
 * Description: Holds player inventory of Items,
 * as well as battery life
 * *********************************************/

#include "Item.hpp"
#include "Player.hpp"
#include <iostream>

/*****************************************
 * Class: Player
 * What it does: Stores and manipulates
 * Items, which contain a name and code
 * number. Player wants to obtain laser
 * components. 
 * Item Codes:
 * 1 - Arc Lamp
 * 2 - Sapphire
 * 3 - Mirror (need 2)
 * 4 - Metal Tube
 * The class also contains the player's
 * battery life and functions to manipulate
 * ****************************************/

// Default Constructor
Player::Player()
{
	head = nullptr;
	itemSlots = 7;
	battery = 100;
	batteryMax = 100;
}

// Destructor, frees dynamic memory
Player::~Player()
{
}

/************************************************
 * Function Name: addItem(Item*)
 * Called By: Space
 * Calls: Item
 * Passed: Item to be added
 * Returns: Nothing
 * Description: Adds an item to the player
 * inventory
 * **********************************************/
void Player::addItem( Item* itemIn )
{
	// Create first item if empty inventory
	if (!head)
	{
		head = itemIn;
	}

	// Already item in inventory
	else
	{
		itemIn->setNext(head);
		head = itemIn;
	}

	// Remove 1 inventory space
	this->drainInventory(1);
}

/************************************************
 * Function Name: print()
 * Called By: Game
 * Calls: Item functions
 * Passed: Nothing
 * Returns: Nothing
 * Description: Displays items in player
 * inventory
 * **********************************************/
void Player::printItems()
{
	Item* pItem;   // Temp ptr to reassign

	// No items in inventory
	if ( !head )
	{
		std::cout << "\nThere are no items in your inventory\n";
		return;
	}

	// At least one item in inventory
	else
	{
		pItem = head;

		// Display title
		std::cout << "\n** INVENTORY - ";
		std::cout << itemSlots << " slots remaining  **\n";

		// Display inventory
		while ( pItem )
		{
			std::cout << " - " << pItem->getName() << '\n';
			pItem = pItem->getNext();
		}

		std::cout << std::endl;
	}
}

/************************************************
 * Function Name: hasLaser()
 * Called By: Game
 * Calls: Item functions
 * Passed: Nothing
 * Returns: True if player has the items
 * necessary to build laser, flase otherwise
 * Description: Checks if player has all
 * the component items for the laser
 * **********************************************/
bool Player::hasLaser()
{
	bool arcLamp = false;
	bool sapphire = false;
	bool metalTube = false;
	int mirrorCount = 0;

	Item* pItem = head;

	// Check for laser components
	while ( pItem )
	{
		if ( pItem->getVal() == 1 )
		{
			arcLamp = true;
		}

		if ( pItem->getVal() == 2 )
		{
			sapphire = true;
		}

		if ( pItem->getVal() == 4 )
		{
			metalTube = true;
		}

		if ( pItem->getVal() == 3 )
		{
			mirrorCount++;
		}

		pItem = pItem->getNext();
	}

	// If all components present
	if ( arcLamp && sapphire && metalTube && mirrorCount >= 2 )
	{
		return true;
	}

	return false;
}

/************************************************
 * Function Name: chargeBattery()
 * Called By: Game
 * Calls: Nothing
 * Passed: Nothing
 * Returns: Nothing
 * Description: Sets battery to maximum
 * **********************************************/
void Player::chargeBattery()
{
	battery = batteryMax;
}

/************************************************
 * Function Name: drainBattery(int)
 * Called By: Game
 * Calls: Nothing
 * Passed: Nothing
 * Returns: Nothing
 * Description: Reduce battery
 * **********************************************/
void Player::drainBattery( int drainIn )
{
	battery -= drainIn;
}

/************************************************
 * Function Name: itemMax()
 * Called By: Game
 * Calls: Nothing
 * Passed: Nothing
 * Returns: True if inventory slots remaining
 * Description: checks if player has empty
 * inventory slots
 * **********************************************/
bool Player::slots()
{
	if ( itemSlots >= 1 )
	{
		return true;
	}

	return false;
}

/************************************************
 * Function Name: drainInventory(int)
 * Called By: Game
 * Calls: Nothing
 * Passed: Amount of inventory space lost
 * Returns: Nothing
 * Description: Reduces max inventory space
 * **********************************************/
void Player::drainInventory( int drainIn )
{
	itemSlots -= drainIn;
}

/************************************************
 * Function Name: getBattery()
 * Called By: Game
 * Calls: Nothing
 * Passed: Nothing
 * Returns: Battery Remaining
 * Description: Returns player's current battery
 * **********************************************/
int Player::getBattery()
{
	return battery;
}

/************************************************
 * Function Name: batteryEmpty()
 * Called By: Game
 * Calls: Nothing
 * Passed: Nothing
 * Returns: true if battery is <= 0
 * Description: Checkis if battery is remaining
 * **********************************************/
bool Player::batteryEmpty()
{
	if ( battery > 0 )
	{
		return false;
	}

	return true;
}
