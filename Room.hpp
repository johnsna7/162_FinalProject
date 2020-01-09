/**************************************************
 * File Name: Room.hpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Base class for rooms for Final Project
 * ************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include "Space.hpp"
#include "Item.hpp"
#include "Player.hpp"

/********************************************
 * Class Name: Room
 * What it does: Standard hallway, no items
 * ******************************************/
class Room : public Space
{
	public:
		// Default Constructor
		Room();

		// Destructor, frees item created
		virtual ~Room();

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
