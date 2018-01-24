// Name: Patrick Darcy
// Login: C00226157
// Date: 15/01/2018
// Approx hours of work : 3hrs
//---------------------------------------------------------------------------
// TEMPLATE
//	1.	The player should have the following movement : It should move from left to right across the screen.
//  When it reaches the boundary of the screen on the right hand side it should move from right to left.
//  When it reaches the boundary on the left hand side it should move from left to right and so on.
//	2. When the user presses the �i� key on the keyboard, the player�s size should increase.
//	3. When the user presses the �c� key on the keyboard, the player�s colour should change.
//	4. When the user presses the �d� key on the keyboard, the player should move in the opposite direction.

// ---------------------------------------------------------------------------
// Known Bugs:none
// ?

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "Game.h"   // include Game header file


int main()
{
	Game myGame;
	myGame.loadContent(); // load the font file
	myGame.run();

	return 0;
}


Game::Game() :window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Display player object within screen boundary", sf::Style::Default)
//  default constructor function
{
}

void Game::loadContent()
// load the font file & set the message string
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen
}


void Game::run()
//This function is the most important function in the project. 
// This function contains the main game loop which controls the game. 
{
	
	srand(static_cast<unsigned>(time(nullptr))); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();			

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

} // end main

void Game::update()
// handles input in the game
{
	// checks what  keys have been pressed  

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))// increases the players size
	{
		myPlayer.changeSize();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))// changes the players colour
	{
		myPlayer.changeColour();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))// changes the players direction
	{
		myPlayer.changeDirection();
	}

	myPlayer.move();
	// calls the player object to move itself in the appropriate direction
}

void Game::draw()
// draws/renders the game world
{
	window.clear(); // clear the screen 

	m_message.setString("Press the 'i' key on the keyboard to increase the size of the player. \nPress the 'c' key on the keyboard to change the colour of the player. \nPress the 'd' key on the keyboard to change the direction of the player.");
	window.draw(m_message);  // write the message on the screen

	window.draw(myPlayer.getBody());  // draw the player object

	window.display();
}

