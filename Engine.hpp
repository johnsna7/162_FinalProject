/**************************************************
 * File Name: Engine.hpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Derived class from Space
 * ************************************************/

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Space.hpp"
#include "Item.hpp"
#include "Player.hpp"

/********************************************
 * Class Name: Engine
 * What it does: Interaction with chance to
 * win the game if user has laser
 * ******************************************/
class Engine : public Space
{
	public:
		// Default Constructor
		Engine();

		// Destructor, frees item created
		virtual ~Engine();

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
