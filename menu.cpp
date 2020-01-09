/********************************************
 * Function Name: menu.cpp
 * Author: Nathan Johnson
 * Date: 05.31.2019
 * Description: Displays a menu that executes
 * functions, and returns user's validated choice
 * ******************************************/


#include "Game.hpp"
#include "getInt.hpp"
#include <iostream>
#include <string>

// Runs the main game menu to either
// play or exit the game
int menu()
{
	// CUSTOMIZE OPTIONS HERE
	int numOptions = 2;   // Number of menu options
	// Title
	std::string title = "Final Project: SpyBot Game";

	// Store menu items in array
	std::string menuOptions[numOptions];
	menuOptions[0] = "Play SpyBot";
	menuOptions[1] = "Exit the game";

	// Display title
	std::cout << "\n\n|==============================================";
	std::cout << "=======================\n";
	std::cout << "|\tWelcome to " << title;
	std::cout << "\n|\tEnter a number to make a selection.";
	std::cout << "\n|______________________________________________";
	std::cout << "_______________________\n|\n";
	
	// Loop to display menu options
	for ( int i = 0; i < numOptions; i++ )
	{
		std::cout << "|\t" << i+1 << ". " << menuOptions[i] << "\n";
	}

	std::cout << "|\n|==============================================";
	std::cout << "=======================\n\n";

	// Get menu choice
	int choice = 0;
	choice = getInt(1, numOptions);

	// Perform functions for that choice (unless exit is called)
	if ( choice == 1 )   // Play the game
	{
		Game g1;
		g1.play();

	}

	return choice;   // Return the user's menu selection
}

// Overloaded function, turns a string array
// into a menu and returns the user's selection
int menu( std::string* pOptions, int numOptions )
{
	// Display title
	std::cout << "\n\n|==============================================";
	std::cout << "=======================\n";
	std::cout << "|\t" << pOptions[0];
	std::cout << "\n|\tEnter a number to make a selection.";
	std::cout << "\n|______________________________________________";
	std::cout << "_______________________\n|\n";
	
	// Loop to display menu options
	for ( int i = 1; i < numOptions; i++ )
	{
		std::cout << "|\t" << i << ". " << pOptions[i] << "\n";
	}

	std::cout << "|\n|==============================================";
	std::cout << "=======================\n\n";

	return getInt(1, numOptions-1);
}
