// CardDeck class

#include "CardDeck.h"   // include CardDeck header file


// Definition of member functions of the CardDeck class

CardDeck::CardDeck()  // Default constructor
{
	dealCard(); // generates the first card
}

void CardDeck::dealCard()
// Randomly generates a new card.
// It should randomly generate a number between 1-4 for the card suit.
// If a 1 is generated the cardSuit should be "Hearts" and so on. 
// It should randomly generate a number between 1-13 for the card face.
// If a 1 is generated the cardFace should be "Ace", if a 2 is generated the
// cardFace should be "2" ... if 11 is generated the cardFace should be "Queen" 
// and so on. It should not return anything.
{
	cardNum = rand() % 13 + 1;
	cardSymbol = rand() % 4 + 1;

	if (cardNum == ACE)
	{
		cardFace = "Ace";
	}
	if (cardNum == JACK)
	{
		cardFace = "Jack";
	}
	if (cardNum == QUEEN)
	{
		cardFace = "Queen";
	}
	if (cardNum == KING)
	{
		cardFace = "King";
	}	
	if (cardSymbol == 1)
	{
		cardSuit = "Diamond";
	}
	if (cardSymbol == 2)
	{
		cardSuit = "Hearts";
	}
	if (cardSymbol == 3)
	{
		cardSuit = "Club";
	}
	if (cardSymbol == 4)
	{
		cardSuit = "Spade";
	}
}


std::string CardDeck::getCardSuit()
// This function should only return the cardSuit. It should not generate a new card suit.
{
	return cardSuit;
}

std::string CardDeck::getCardFace()
// This function should only return the cardFace. It should not generate a new card face.
{
	return cardFace;
}
