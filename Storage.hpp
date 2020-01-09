/**************************************************
 * File Name: Storage.hpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Derived class from Space
 * ************************************************/

#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "Space.hpp"
#include "Item.hpp"
#include "Player.hpp"

/********************************************
 * Class Name: Storage
 * What it does: Allows player to collect
 * mirror or recharge battery
 * ******************************************/
class Storage : public Space
{
	public:
		// Default Constructor
		Storage();

		// Destructor, frees item created
		virtual ~Storage();

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
