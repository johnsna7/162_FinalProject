/*******************************************
 * Function name: getInt.hpp
 * Author: Nathan Johnson
 * Date: 04.07.2019
 * Description: Returns validated int input
 * *****************************************/

#ifndef GET_INT_HPP
#define GET_INT_HPP

// Function: getInt()
// What it does: Prompts for user input until it receives an int
// then returns that integer.
// Arguments: none (overloaded below)
// Returns: Validated integer
int getInt();

// Function: getInt(int, int)
// What it does: Prompts for user input until it receives an int
// within a certain range then returns that integer.
// Arguments: Two ints, min & max values respectively,
// for the acceptable range allowed
// Returns: Validated integer between (including) the range
// passed in the parameter.
int getInt(int minVal, int maxVal);

#endif
