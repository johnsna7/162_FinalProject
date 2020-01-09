/**************************************************
 * File Name: Game.hpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Creates and plays the game
 * ************************************************/

#include "Game.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include "Armory.hpp"
#include "Barracks.hpp"
#include "Engine.hpp"
#include "Storage.hpp"
#include "Treasury.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Default constructor
Game::Game()
{
	// Create game board
	this->makeMap();

	// Create player
	robot = new Player();

	lost = false;
}

// Destructor to delete pointers
Game::~Game()
{
	delete r1;
	delete r2;
	delete r3;
	delete r4;
	delete r5;
	delete r6;
	delete r7;
	delete r8;
	delete r9;
	delete r10;
	delete r11;
	delete r12;
	delete r13;
	delete r14;
	delete r15;
	delete r16;
	delete robot;
}

// Initializes spaces in the map
void Game::makeMap()
{
	// Create spaces
	r1 = new Room();
	r2 = new Room();
	r3 = new Room();
	r4 = new Storage();
	r5 = new Room();
	r6 = new Barracks();
	r7 = new Room();
	r8 = new Room();
	r9 = new Room();
	r10 = new Room();
	r11 = new Armory();
	r12 = new Room();
	r13 = new Treasury();
	r14 = new Room();
	r15 = new Storage();
	r16 = new Engine();
	
	// Create doors
	r1->setDoor(1,r5);
	r1->setDoor(2,r2);

	r2->setDoor(2,r3);
	r2->setDoor(4,r1);

	r3->setDoor(1,r7);
	r3->setDoor(2,r4);
	r3->setDoor(4,r2);

	r4->setDoor(1,r8);
	r4->setDoor(4,r3);

	r5->setDoor(2,r6);
	r5->setDoor(3,r1);

	r6->setDoor(1,r10);
	r6->setDoor(4,r5);

	r7->setDoor(1,r11);
	r7->setDoor(3,r3);

	r8->setDoor(1,r12);
	r8->setDoor(3,r4);

	r9->setDoor(1,r13);
	r9->setDoor(2,r10);

	r10->setDoor(1,r14);
	r10->setDoor(3,r6);
	r10->setDoor(4,r9);

	r11->setDoor(3,r7);

	r12->setDoor(1,r16);
	r12->setDoor(3,r8);

	r13->setDoor(3,r9);

	r14->setDoor(2,r15);
	r14->setDoor(3,r10);

	r15->setDoor(2,r16);
	r15->setDoor(4,r14);

	r16->setDoor(3,r12);
	r16->setDoor(4,r15);

	current = r1;
}

/************************************
 * Function Name: play()
 * Called By: menu
 * Calls: Space functions
 * Passed: Nothing
 * Returns: Nothing
 * Description: Plays the game until
 * the player wins or loses
 * **********************************/
void Game::play()
{
	// Show intro text
	cout << "\n** Welcome to Spybot! **\n\nYou work in the intelligence";
	cout << " division of the federation army.\nAt the moment you are";
	cout << " at war with a neighboring faction, \nand it's not";
	cout << " looking good!\n\nAs a last desperate tactic, you have ";
	cout << "been assigned a secret mission.\n\nA spy aboard the ";
	cout << "enemy capital ship has secretly hacked into a cleaning ";
	cout << "robot!\nYou have been given remote control over the ";
	cout << "robot, and since it has\naccess to every area of the";
	cout << " ship, you can gather the\nmaterials needed to build ";
	cout << "a laser capable of destroying the enemy ship!\n";
	cout << "Be careful not not alert the crew by behaving erratically";
	cout << " and don't\nrun out of battery, as then the robot would";
	cout << "\ngo back to it's standard programming.\n\nGood luck on";
	cout << " your mission, your fleet is counting on you!\n";
	
	// Loops until player loses or is out
	// of battery
	while ( !robot->batteryEmpty() && !lost )
	{
		this->turn();

		if ( current->win() )
		{
			this->win();
			return;
		}
	}

	this->lose();
}

/************************************
 * Function Name: win()
 * Called By: play
 * Calls: Space functions
 * Passed: Nothing
 * Returns: Nothing
 * Description: Displays winning
 * message
 * **********************************/
void Game::win()
{
	cout << "\nCONGRATS!! You have won the game!\n";
}

/************************************
 * Function Name: lose()
 * Called By: play
 * Calls: Space functions
 * Passed: Nothing
 * Returns: Nothing
 * Description: Displays losing
 * message
 * **********************************/
void Game::lose()
{
	// Player is out of inventory spaces
	if ( !robot->slots() )
	{
		cout << "\nYou have no more inventory left & cannot build";
		cout << " the laser!\n";
	}

	// Losing message
	cout << "\nSORRY!! You have lost the game!\n";
}

/************************************
 * Function Name: turn()
 * Called By: play
 * Calls: Space functions
 * Passed: Nothing
 * Returns: Nothing
 * Description: Moves the player to
 * a new space and interacts with it
 * **********************************/
void Game::turn()
{
	// Move to next space
	this->move();

	// Interact with that space
	current->interact(robot);

	// Player lost during interaction
	if ( current->lose() )
	{
		lost = true;
		return;
	}

	// Player won during interaction
	else if ( current->win() )
	{
		return;
	}

	// Disply items
	robot->printItems();

	// Display battery remaining
	cout << "\nBattery remaining: " << robot->getBattery() << '\n';
}

/************************************
 * Function Name: move()
 * Called By: turn
 * Calls: Space functions
 * Passed: Nothing
 * Returns: Nothing
 * Description: Moves player to the
 * next Space of their choosing.
 * **********************************/
void Game::move()
{

	// Display available rooms & get player's choice
	int moveChoice = current->print();

	// Direction to find next room
	int moveDirection = 0;

	// Find next room
	for ( int i = 1; i <= moveChoice; i++ )
	{
		if ( current->getNorth() )
		{
			if ( i == moveChoice )
			{
				moveDirection = 1;
			}
			i++;
		}

		if ( current->getEast() )
		{
			if ( i == moveChoice )
			{
				moveDirection = 2;
			}
			i++;
		}

		if ( current->getSouth() )
		{
			if ( i == moveChoice )
			{
				moveDirection = 3;
			}
			i++;
		}

		if ( current->getWest() )
		{
			if ( i == moveChoice )
			{
				moveDirection = 4;
			}
			i++;
		}
	}

	// Move to directed room
	if ( moveDirection == 1 )
	{
		current = current->getNorth();
	}

	if ( moveDirection == 2 )
	{
		current = current->getEast();
	}

	if ( moveDirection == 3 )
	{
		current = current->getSouth();
	}

	if ( moveDirection == 4 )
	{
		current = current->getWest();
	}
}
