// Player class

#include "Player.h"   // include Player header file


// Definition of member functions of the Player class


Player::Player() // default constructor
{
	int xPos = SCREEN_WIDTH/2;        // place the player object in the centre of the screen
	int yPos = SCREEN_HEIGHT/2;
	setPosition(xPos, yPos);  // set the position of the rectangle

	setColour();  // set the colour of the rectangle
	setBody();  // set the size of the rectangle

	speed = 10; // the average speed
	direction = (rand() % 2) + 1;        // Generates a random number between 1 and 2
	lives = 3;
}

void Player::setBody()  // set the size of the players rectangle body
{
	sf::Vector2f sizeVec(PLAYER_SIZE, PLAYER_SIZE);
	body.setSize(sizeVec);
}

sf::RectangleShape Player::getBody() // get the players rectangle body
{
	return body;
}

void Player::setColour()  // set the colour of the player
{
	body.setFillColor(sf::Color::Magenta);
}

void Player::setPostion()
{
	body.setPosition(200, 40);
}

void Player::setPosition(int xPos, int yPos)  // set the position of the player on the screen
{
	body.setPosition(xPos, yPos);
}


void Player::move()
{


	if (direction == EAST)
	{
		speed = 5;
		if (body.getPosition().x + PLAYER_SIZE > SCREEN_WIDTH)
		{
			direction = WEST;
		}
	}
	else if (direction == WEST)
	{
		speed = -5;

		if (body.getPosition().x < 0)
		{
			direction = EAST;
		}
	}

	body.setPosition(body.getPosition().x + speed, body.getPosition().y);
}

void Player::changeDirection()
{
	if (direction == WEST)
	{
		direction = EAST;
	}
	else if (direction == EAST)
	{
		direction = WEST;
	}
}

void Player::changeColour()
{
	colourB = rand() % 255;
	colourR = rand() % 255;
	colourG = rand() % 255;
	body.setFillColor(sf::Color(colourR, colourG, colourB, 255));
}

