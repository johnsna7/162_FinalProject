/**************************************************
 * File Name: Barracks.hpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Derived class from Space
 * ************************************************/

#ifndef BARRACKS_HPP
#define BARRACKS_HPP

#include "Space.hpp"
#include "Item.hpp"
#include "Player.hpp"

/********************************************
 * Class Name: Barracks
 * What it does: Allows user to collect
 * metal tube
 * ******************************************/
class Barracks : public Space
{
	public:
		// Default Constructor
		Barracks();

		// Destructor, frees item created
		virtual ~Barracks();

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
