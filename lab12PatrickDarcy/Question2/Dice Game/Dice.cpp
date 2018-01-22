// Dice class 

#include "Dice.h"   // include Dice header file


// Definition of member functions of the Dice class

	Dice::Dice()  // Default constructor
	{
		diceNum = rand() % 6 + 1;
	}

	void Dice::rollDice()
	// Randomly generates a number between 1-6 for the dice
	{
		diceNum = rand() % 6 + 1;
	}

	int Dice::getDiceNum() 
    // Should return the dice number only
	{
		return diceNum;
	}
		

