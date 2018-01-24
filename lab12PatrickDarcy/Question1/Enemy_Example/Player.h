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
	int size = 80; // the players initial size
	int colourB; // used to change the squares colour
	int colourR;
	int colourG;

public:	  // declaration of member functions	

	Player(); // default constructor
	sf::RectangleShape getBody(); // creates a rectangle
	void setBody(); // sets the body size
	void setColour(); // sets the players initial colour
	void setPostion(); // sets the players initial position
	void setPosition(int xPos, int yPos);
	void move();// moves the player left and right 
	void changeDirection();// changes the players direction
	void changeColour(); // changes the players colour
	void changeSize();// changes the players size
	
};
