/**************************************************
 * File Name: Treasury.hpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Derived class from Space
 * ************************************************/

#ifndef TREASURY_HPP
#define TREASURY_HPP

#include "Space.hpp"
#include "Item.hpp"
#include "Player.hpp"

/********************************************
 * Class Name: Treasury
 * What it does: Allows player to collect
 * sapphire
 * ******************************************/
class Treasury : public Space
{
	public:
		// Default Constructor
		Treasury();

		// Destructor, frees item created
		virtual ~Treasury();

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
