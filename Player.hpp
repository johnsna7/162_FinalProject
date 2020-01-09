/***********************************************
 * File Name: Player.hpp
 * Author: Nathan Johnson
 * Date: 06.08.2019
 * Description: Holds player inventory of Items,
 * as well as battery life
 * *********************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Item.hpp"

/*****************************************
 * Class: Player
 * What it does: Stores and manipulates
 * Items, which contain a name and code
 * number. Player wants to obtain laser
 * components. 
 * Item Codes:
 * 1 - Arc Lamp
 * 2 - Sapphire
 * 3 - Metal Tube
 * 4 - Mirror (need 2)
 * The class also contains the player's
 * battery life and functions to manipulate
 * ****************************************/
class Player
{
	private:
		Item* head;   // Pointer to the first item
		int itemSlots;   // Empty item slots remaining
		int battery;   // Current battery life
		int batteryMax;   // Max battery life

	public:
		// Default Constructor
		Player();

		// Destructor, frees dynamic memory
		~Player();

		/************************************************
 		 * Function Name: addItem(Item*)
 		 * Called By: Space
 		 * Calls: Item
 		 * Passed: Item to be added
 		 * Returns: Nothing
 		 * Description: Adds an item to the player
 		 * inventory
 		 * **********************************************/
		void addItem( Item* itemIn );

		/************************************************
 		 * Function Name: print()
 		 * Called By: Game
 		 * Calls: Item functions
 		 * Passed: Nothing
 		 * Returns: Nothing
 		 * Description: Displays items in player
 		 * inventory
 		 * **********************************************/
		void printItems();

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
		bool hasLaser();

		/************************************************
 		 * Function Name: chargeBattery()
 		 * Called By: Game
 		 * Calls: Nothing
 		 * Passed: Nothing
 		 * Returns: Nothing
 		 * Description: Sets battery to maximum
 		 * **********************************************/
		void chargeBattery();

		/************************************************
 		 * Function Name: drainBattery(int)
 		 * Called By: Game
 		 * Calls: Nothing
 		 * Passed: Nothing
 		 * Returns: Nothing
 		 * Description: Reduce battery
 		 * **********************************************/
		void drainBattery( int drainIn );

		/************************************************
 		 * Function Name: itemSlots()
 		 * Called By: Game
 		 * Calls: Nothing
 		 * Passed: Nothing
 		 * Returns: True if inventory slots remaining
 		 * Description: checks if player has empty
 		 * inventory slots
 		 * **********************************************/
		bool slots();

		/************************************************
 		 * Function Name: drainInventory(int)
 		 * Called By: Game
 		 * Calls: Nothing
 		 * Passed: Amount of inventory space lost
 		 * Returns: Nothing
 		 * Description: Reduces max inventory space
 		 * **********************************************/
		void drainInventory( int drainIn );

		/************************************************
 		 * Function Name: getBattery()
 		 * Called By: Game
 		 * Calls: Nothing
 		 * Passed: Nothing
 		 * Returns: Battery Remaining
 		 * Description: Returns player's current battery
 		 * **********************************************/
		int getBattery();

		/************************************************
 		 * Function Name: batteryEmpty()
 		 * Called By: Game
 		 * Calls: Nothing
 		 * Passed: Nothing
 		 * Returns: true if battery is <= 0
 		 * Description: Checkis if battery is remaining
 		 * **********************************************/
		bool batteryEmpty();
};

#endif
