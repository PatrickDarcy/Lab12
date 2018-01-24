// author Patrick Darcy
#pragma once

#include <SFML\Graphics.hpp>

class Player
{	
	
	float speedX;
	float speedY;
	float xPos;
	float yPos;
	float const PLAYER_SIZE = 80;
	float const SCREEN_HEIGHT = 600;
	float const SCREEN_WIDTH = 800;
	sf::RectangleShape body;

public:
	Player();
	sf::RectangleShape getBody();
	void move();
	void boarders();
};
