/**************************************************
 * File Name: Space.hpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Base class for rooms for Final Project
 * ************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Item.hpp"
#include "Player.hpp"

class Space
{
	protected:
		Space* north;   // Pointer to the space to the north
		Space* east;    // Pointer to the space to the east
		Space* south;   // Pointer to the space to the south
		Space* west;   // Pointer to the space to the west
		bool visited;   // T if player has been to room before
		Item* roomItem;   // Pointer to item in the room (if any)
		std::string name;   // Name of the space;
		bool lost;  // True if player loses game
		bool won;   // True if player wins the game

		// Generates random number in a range
		int die( int minValue, int maxValue );
		
	public:
		// Default Constructor
		Space();

		// Destructor, frees item created
		virtual ~Space();

		/**************************************************
		 * Function name: setDoor(int,SPace*)
		 * Called By: Game
		 * Calls: Nothing
		 * Returns: Nothing
		 * Description: links the space with another
		 * space at one of the directional pointers
		 * ************************************************/
		void setDoor( int direction, Space* spaceIn );

		/**************************************************
		 * Function name: win()
		 * Called By: Game
		 * Calls: Nothing
		 * Returns: true if player wins (during interaction)
		 * Description: returns true if player wins the game
		 * ************************************************/
		bool win();

		/**************************************************
		 * Function name: lose()
		 * Called By: Game
		 * Calls: Nothing
		 * Returns: true if player loses (during interaction)
		 * Description: returns true if player loses the game
		 * ************************************************/
		bool lose();

		/**************************************************
		 * Function name: interact(Player*)
		 * Called By: Game
		 * Calls: Nothing
		 * Returns: Nothing
		 * Description: Controls iteraction for the space
		 * ************************************************/
		virtual void interact( Player* playerIn ) = 0;

		/**************************************************
		 * Function name: print()
		 * Called By: Game
		 * Calls: Nothing
		 * Returns: Nothing
		 * Description: Displays surround rooms
		 * ************************************************/
		int print();

		/**************************************************
		 * Function name: getVisited()
		 * Called By: Game
		 * Calls: Nothing
		 * Returns: visited
		 * ************************************************/
		bool getVisited();

		/**************************************************
		 * Function name: getNorth()
		 * Called By: Game
		 * Calls: Nothing
		 * Returns: north
		 * ************************************************/
		Space* getNorth();

		/**************************************************
		 * Function name: getEast()
		 * Called By: Game
		 * Calls: Nothing
		 * Returns: east
		 * ************************************************/
		Space* getEast();

		/**************************************************
		 * Function name: getSouth()
		 * Called By: Game
		 * Calls: Nothing
		 * Returns: south
		 * ************************************************/
		Space* getSouth();

		/**************************************************
		 * Function name: getWest()
		 * Called By: Game
		 * Calls: Nothing
		 * Returns: west
		 * ************************************************/
		Space* getWest();

		/**************************************************
		 * Function name: getName()
		 * Called By: Game
		 * Calls: Nothing
		 * Returns: name
		 * ************************************************/
		std::string getName();
};

#endif
