/**************************************************
 * File Name: Game.hpp
 * Author: Nathan Johnson
 * Date: 06.09.2019
 * Description: Creates and plays the game
 * ************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Room.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/**************************************************
 * Class Name: Game
 * What it does: Creates 16 spaces of various
 * types as the game board, along with a player.
 * Then loops turns where the player moves to
 * and interacts with different rooms until
 * they either lose or blow up the ship with
 * the laser.
 * Description: Creates and plays the game
 * ************************************************/
class Game
{
	private:
		// Spaces for the board
		Space* r1;
		Space* r2;
		Space* r3;
		Space* r4;
		Space* r5;
		Space* r6;
		Space* r7;
		Space* r8;
		Space* r9;
		Space* r10;
		Space* r11;
		Space* r12;
		Space* r13;
		Space* r14;
		Space* r15;
		Space* r16;

		Space* current;   // Pointer to space player is in
		Player* robot;   // Pointer to player's character
		bool lost;   // true when player loses game

		// Initializes Spaces in the game
		void makeMap();

	public:
		// Default constructor
		Game();

		// Destructor to delete pointers
		~Game();

		/************************************
		 * Function Name: play()
		 * Called By: menu
		 * Calls: Player functions, turn, win & lose
		 * Passed: Nothing
		 * Returns: Nothing
		 * Description: Plays the game until
		 * the player wins or loses
		 * **********************************/
		void play();

		/************************************
		 * Function Name: win()
		 * Called By: play
		 * Calls: Nothing
		 * Passed: Nothing
		 * Returns: Nothing
		 * Description: Displays winning
		 * message
		 * **********************************/
		void win();

		/************************************
		 * Function Name: lose()
		 * Called By: play
		 * Calls: Player function
		 * Passed: Nothing
		 * Returns: Nothing
		 * Description: Displays losing
		 * message
		 * **********************************/
		void lose();

		/************************************
		 * Function Name: turn()
		 * Called By: play
		 * Calls: move, Player & Space functions
		 * Passed: Nothing
		 * Returns: Nothing
		 * Description: Moves the player to
		 * a new space and interacts with it
		 * **********************************/
		void turn();

		/************************************
		 * Function Name: move()
		 * Called By: turn
		 * Calls: Space functions
		 * Passed: Nothing
		 * Returns: Nothing
		 * Description: Moves player to the
		 * next Space of their choosing.
		 * **********************************/
		void move();
};

#endif
