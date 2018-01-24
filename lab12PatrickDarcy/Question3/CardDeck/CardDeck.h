// CardDeck class declaration
#pragma once

#include "SFML/Graphics.hpp"  // Headers for SFML projects

class CardDeck
{
	// the data members are private by default
	std::string cardSuit; // the suit of the card eg Hearts, Spades etc
	std::string cardFace; // the number of the card eg Ace, 3, Queen etc
	int cardNum; // random number for the face
	int cardSymbol; // random number for the suit
	// Different card constants
	const int ACE = 1;
	const int JACK = 11;
	const int QUEEN = 12;
	const int KING = 13;

public:	  // declaration of member functions	
	CardDeck();  // default constructor
	void dealCard();  // Randomly generate a new card
	
	// Get functions
	std::string getCardSuit(); // this function should only return the cardSuit
	std::string getCardFace(); // this function should only return the cardFace
};









