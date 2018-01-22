#pragma once

#include "SFML/Graphics.hpp" 

// Dice class declaration

class Dice
{
	// the data members are private by default
	int diceNum;

public:	  // declaration of member functions	
	Dice();  // default constructor
	void rollDice();  // generates a new number randomly for the dice
	int getDiceNum();  // returns the dice number only
};










