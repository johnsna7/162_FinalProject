/**********************************************
 * File Name: Item.hpp
 * Author: Nathan Johnson
 * Date: 06.08.2019
 * Description: Container with name and
 * item code variables, stored as stack in
 * Player class
 * ********************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{
	private:
		Item* next;   // Pointer to next item in inventory
		std::string name;   // Name of the item
		int val;   // Item code

	public:
		/**********************************************
		 * Constructor
		 * Called By: Space, Player
		 * Calls: Nothing
		 * Passed: Item name & code
		 * Description: Initializes var with parameter
		 * ********************************************/
		Item( std::string nameIn, int valIn);

		// Setter/Getters

		// called by: Player
		// returns: name
		std::string getName();

		// called by: Player
		// returns: val
		int getVal();

		// called by: Player
		// returns: next
		Item* getNext();

		// called by: Player
		// passes: next
		void setNext( Item* itemIn );
};

#endif
