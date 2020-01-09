/**********************************************
 * File Name: Item.cpp
 * Author: Nathan Johnson
 * Date: 06.08.2019
 * Description: Container with name and
 * item code variables, stored as stack in
 * Player class
 * ********************************************/

#include "Item.hpp"
#include <string>

/**********************************************
 * Constructor
 * Called By: Space, Player
 * Calls: Nothing
 * Passed: Item name & code
 * Description: Initializes var with parameter
 * ********************************************/
Item::Item( std::string nameIn, int valIn )
{
	name = nameIn;
	val = valIn;
	next = nullptr;
}

// Setter/Getters

// called by: Player
// returns: name
std::string Item::getName()
{
	return name;
}

// called by: Player
// returns: val
int Item::getVal()
{
	return val;
}

// called by: Player
// returns: next
Item* Item::getNext()
{
	return next;
}

// called by: Player
// passes: next
void Item::setNext( Item* itemIn )
{
	next = itemIn;
}
