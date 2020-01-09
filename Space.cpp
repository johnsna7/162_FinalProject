/**************************************************
 * File Name: Space.cpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Base class for rooms for Final Project
 * ************************************************/

#include "Space.hpp"
#include "Item.hpp"
#include "Player.hpp"
#include "menu.hpp"
#include <iostream>
#include <cstdlib>

// Default Constructor
Space::Space()
{
	north = nullptr;
	east = nullptr;
	south = nullptr;
	west = nullptr;
	visited = false;
	roomItem = nullptr;
	lost = false;
	won = false;
}

// Destructor, frees item created
Space::~Space()
{
}

/**************************************************
 * Function name: setDoor(int,SPace*)
 * Called By: Game
 * Calls: Nothing
 * Returns: Nothing
 * Description: links the space with another
 * space at one of the directional pointers
 * ************************************************/
void Space::setDoor( int direction, Space* spaceIn )
{
	// 1 = N, 2 = E, 3 = S, 4 = W
	if ( direction == 1 )
	{
		north = spaceIn;
	}

	if ( direction == 2 )
	{
		east = spaceIn;
	}

	if ( direction == 3 )
	{
		south = spaceIn;
	}

	if ( direction == 4 )
	{
		west = spaceIn;
	}
}

/**************************************************
 * Function name: win()
 * Called By: Game
 * Calls: Nothing
 * Returns: true if player wins (during interaction)
 * Description: returns true if player wins the game
 * ************************************************/
bool Space::win()
{
	return won;
}

/**************************************************
 * Function name: lose()
 * Called By: Game
 * Calls: Nothing
 * Returns: true if player loses (during interaction)
 * Description: returns true if player loses the game
 * ************************************************/
bool Space::lose()
{
	return lost;
}

/**************************************************
 * Function name: print()
 * Called By: Game
 * Calls: Nothing
 * Returns: Nothing
 * Description: Displays surrounding rooms
 * ************************************************/
int Space::print()
{
	std::string northChoice;
	std::string eastChoice;
	std::string southChoice;
	std::string westChoice;

	int numOptions = 1;

	// Show available rooms
	if ( north )
	{
		numOptions++;
		northChoice =  "To the north: "; 
		northChoice += north->getName();
	}

	if ( east )
	{
		numOptions++;
		eastChoice = "To the east: ";
		eastChoice += east->getName();
	}

	if ( south )
	{
		numOptions++;
		southChoice = "To the south: ";
		southChoice += south->getName();
	}

	if ( west )
	{
		numOptions++;
		westChoice = "To the west: ";
		westChoice += west->getName();
	}

	// Create string array of menu options
	std::string pChoice[numOptions];
	pChoice[0] = "Choose your next room to visit";

	for ( int i = 1; i < numOptions; i++ )
	{
		if ( north )
		{
			pChoice[i] = northChoice;
			i++;
		}

		if ( east )
		{
			pChoice[i] = eastChoice;
			i++;
		}

		if ( south )
		{
			pChoice[i] = southChoice;
			i++;
		}

		if ( west )
		{
			pChoice[i] = westChoice;
			i++;
		}
	}

	// Display menu and return users choice
	return menu(pChoice, numOptions);
}

/**************************************************
 * Function name: getVisited()
 * Called By: Game
 * Calls: Nothing
 * Returns: visited
 * ************************************************/
bool Space::getVisited()
{
	return visited;
}

/**************************************************
 * Function name: getNorth()
 * Called By: Game
 * Calls: Nothing
 * Returns: north
 * ************************************************/
Space* Space::getNorth()
{
	return north;
}

/**************************************************
 * Function name: getEast()
 * Called By: Game
 * Calls: Nothing
 * Returns: east
 * ************************************************/
Space* Space::getEast()
{
	return east;
}

/**************************************************
 * Function name: getSouth()
 * Called By: Game
 * Calls: Nothing
 * Returns: south
 * ************************************************/
Space* Space::getSouth()
{
	return south;
}

/**************************************************
 * Function name: getWest()
 * Called By: Game
 * Calls: Nothing
 * Returns: west
 * ************************************************/
Space* Space::getWest()
{
	return west;
}

/**************************************************
 * Function name: getName()
 * Called By: Game
 * Calls: Nothing
 * Returns: name
 * ************************************************/
std::string Space::getName()
{
	return name;
}

// Generates random number in a range
int Space::die( int minValue, int maxValue )
{
	return ( (rand() % (maxValue-minValue+1)) + minValue );
}
