/********************************************
 * Function Name: menu.hpp
 * Author: Nathan Johnson
 * Date: 05.31.2019
 * Description: Displays a menu that executes
 * functions, and returns user's validated choice
 * ******************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>

// Runs the main game menu to either
// play or exit the game
int menu();

// Overloaded function, turns a string array
// into a menu and returns the user's selection
int menu( std::string* pOptions, int numOptions );

#endif
