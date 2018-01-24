// author Patrick Darcy

#include "Player.h"
#include <iostream>

Player::Player()
{
	xPos = 400;
	yPos = 300;

	speedX = 5.0f;
	speedY = 5.0f;

	body.setSize(sf::Vector2f{ PLAYER_SIZE,PLAYER_SIZE });
	body.setFillColor(sf::Color::Blue);
	body.setPosition(sf::Vector2f{ xPos,yPos});

}

sf::RectangleShape Player::getBody()
{
	return sf::RectangleShape(body);
}


void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		yPos -= speedY;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		yPos += speedY;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		xPos -= speedX;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		xPos += speedX;
	}

	body.setPosition(sf::Vector2f{ xPos,yPos });
}

void Player::boarders()
{
	if (body.getPosition().x >= SCREEN_WIDTH)
	{
		xPos = -(PLAYER_SIZE);
	}
	if (body.getPosition().x + PLAYER_SIZE <= 0)
	{
		xPos = SCREEN_WIDTH;
	}
	if (body.getPosition().y + PLAYER_SIZE < 0)
	{
		yPos = SCREEN_HEIGHT;
	}
	if (body.getPosition().y > SCREEN_HEIGHT)
	{
		yPos = -(PLAYER_SIZE);
	}

	body.setPosition(sf::Vector2f{ xPos,yPos });
}
