// Player class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include "Globals.h"   // include Global header file


class Player
{
	// the data members are private by default
	sf::RectangleShape body;   // the body of the player is a rectangle

	int speed;   // the speed that the player moves
	int lives;    // the number of lives
	int direction; // is the player moving east or west


public:	  // declaration of member functions	

	Player(); // default constructor
	sf::RectangleShape getBody();
	void setBody();
	void setColour();  
	void setPosition();
	void setPosition(int xPos, int yPos);


};
