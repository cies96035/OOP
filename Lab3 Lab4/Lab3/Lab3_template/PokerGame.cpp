#include "PokerGame.h"

void PokerGame::Distribute(bool usedCards[52])
{	
	//TO_DO: Random generate five cards to player
	//Hint: Use usedCards to record which card have been distributed
}

void PokerGame::set(vector<int> cards)
{
	//TO_DO: Set the cards to player
}

void PokerGame::printCards()
{
	
	cout << "Player cards:";
	
	for (int i = 0; i < 5; i++)
	{
		//TO_DO: Print the player's cards.
		// For example: "C1" "S2" "H3" ...
	}
	cout << endl;
	
}

void PokerGame::sortCards()
{
	//TO_DO: Sort the cards accroding to thier number

}

void PokerGame::evaluate()
{
	sortCards();
	if (this->isStraight() && this->isFlush())
	{
		Type = StraightFlush;
	}
	else if (this->isFourOfaKind())
	{
		Type = FourOfaKind;
	}
	else if (this->isFullHouse())
	{
		Type = FullHouse;
	}
	else if (this->isFlush())
	{
		Type = Flush;
	}
	else if (this->isStraight())
	{
		Type = Straight;
	}
	else if (this->isThreeOfaKind())
	{
		Type = ThreeOfaKind;
	}
	else if (this->isTwoPairs())
	{
		Type = TwoPairs;
	}
	else if (this->isOnePair())
	{
		Type = OnePair;
	}
	else
	{
		Type = Highcard;
	}
}

int PokerGame::getType()
{
	return Type;
}

void PokerGame::compare(int type)
{
	//TO_DO: Compare the type and output who is winner
	
}

bool PokerGame::isStraight()
{
	//TO_DO: Check whether the hand of cards is Straight or not
	return false;
}

bool PokerGame::isFlush()
{
	//TO_DO: Check whether the hand of cards is Flush or not
	return false;
}

bool PokerGame::isFourOfaKind()
{
	//TO_DO: Check whether the hand of cards is FourOfaKind or not
	return false;
}

bool PokerGame::isFullHouse()
{
	//TO_DO: Check whether the hand of cards is FullHouse or not
	return false;
}

bool PokerGame::isThreeOfaKind()
{
	//TO_DO: Check whether the hand of cards is ThreeOfaKind or not
	return false;
}

bool PokerGame::isTwoPairs()
{
	//TO_DO: Check whether the hand of cards is TwoPairs or not
	return false;
}

bool PokerGame::isOnePair()
{
	//TO_DO: Check whether the hand of cards is OnePair or not
	return false;
}



