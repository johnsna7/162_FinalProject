/**************************************************
 * File Name: Armory.hpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Derived class from Space
 * ************************************************/

#ifndef ARMORY_HPP
#define ARMORY_HPP

#include "Space.hpp"
#include "Item.hpp"
#include "Player.hpp"

/********************************************
 * Class Name: Armory
 * What it does: Allows user to collect
 * arc lamp
 * ******************************************/
class Armory : public Space
{
	public:
		// Default Constructor
		Armory();

		// Destructor, frees item created
		virtual ~Armory();

		/**************************************************
		 * Function name: interact(Player*)
		 * Called By: Game
		 * Calls: Nothing
		 * Returns: Nothing
		 * Description: Controls iteraction for the space
		 * ************************************************/
		virtual void interact( Player* playerIn );

};

#endif
