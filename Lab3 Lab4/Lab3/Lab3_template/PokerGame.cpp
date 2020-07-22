#include "PokerGame.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

void PokerGame::Distribute(bool usedCards[52])
{	
	//TO_DO: Random generate five cards to player
	//Hint: Use usedCards to record which card have been distributed
	srand(time(NULL));
	for(int i=0;i<5;)
	{
		int Randnum=rand()%52;
		//cout<<Randnum<<endl;
		if(usedCards[Randnum]==0)
		{
			usedCards[Randnum]=1;
			playerCards.emplace_back(Randnum);
			i++;
		}
		//cout<<i<<endl;
		//system("PAUSE");

	}
}

void PokerGame::set(vector<int> cards)
{
	//TO_DO: Set the cards to player
	for(int i=0;i<cards.size();i++)
		playerCards.emplace_back(cards[i]);
	cards.clear();
}

void PokerGame::printCards()
{
	
	cout << "Player cards:"<<endl;
	
	string Cardname[52];
	string Card_type="CDHS";
	string Card_num="A23456789_JQK";

	//Card_type
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
		{
			Cardname[i*13+j]+=Card_type[i];
			if(j!=9)
				Cardname[i*13+j]+=Card_num[j];
			else
				Cardname[i*13+j]+="10";
		}


	//Card_num
	for(int i = 0; i < 5; i++)
	{
		//TO_DO: Print the player's cards.
		// For example: "C1" "S2" "H3" ...
		cout<<Cardname[playerCards[i]]<<' ';
	}
	cout << endl;
	
}

void PokerGame::sortCards()
{
	//TO_DO: Sort the cards accroding to thier number
	sort(playerCards.begin(),playerCards.end());
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
	int result=this->getType()-type;
	if(result>0)
		cout<<"Player1 win"<<endl;
	else if(result<0)
		cout<<"Player2 win"<<endl;
	else
		cout<<"Draw"<<endl;
	
}

int get_Card_number(int card_id)
{
	return card_id%13;
}

bool PokerGame::isStraight()
{
	//TO_DO: Check whether the hand of cards is Straight or not
	int nums[5];//only need Cards nums
	for(int i=0;i<5;i++)
		nums[i]=get_Card_number(playerCards[i]);

	sort(nums,nums+5);//sort by number

	for(int i=0;i<4;i++)//check is continuous
		if(nums[i]+1!=nums[i+1])
			return false;
	return true;
}

bool PokerGame::isFlush()
{
	for(int i=0;i<4;i++)
		if(playerCards[i]/13!=playerCards[i+1]/13)
			return false;
	return true;
}

bool PokerGame::isFourOfaKind()
{
	//TO_DO: Check whether the hand of cards is FourOfaKind or not

	int nums[13]={0};
	for(int i=0;i<5;i++)
	{
		nums[get_Card_number(playerCards[i])]++;
		if(nums[get_Card_number(playerCards[i])]==4)//four same number
			return true;
	}
	return false;
}

bool PokerGame::isFullHouse()
{
	//TO_DO: Check whether the hand of cards is FullHouse or not

	
	int nums[13]={0},amount[5]={0};
	for(int i=0;i<5;i++)
	{
		int tmp=nums[get_Card_number(playerCards[i])]++;
		amount[ tmp ]--;
		amount[ tmp+1 ]++;
	}

	if(amount[3]==1&&amount[2]==1)
		return true;
		
	return false;
}

bool PokerGame::isThreeOfaKind()
{
	//TO_DO: Check whether the hand of cards is ThreeOfaKind or not

	
	int nums[13]={0},amount[5]={0};
	for(int i=0;i<5;i++)
	{
		int tmp=nums[get_Card_number(playerCards[i])]++;
		amount[ tmp ]--;
		amount[ tmp+1 ]++;
	}

	if(amount[3]==1&&amount[1]==2)
		return true;
		
	return false;
}

bool PokerGame::isTwoPairs()
{
	//TO_DO: Check whether the hand of cards is TwoPairs or not

	int nums[13]={0},amount[5]={0};
	for(int i=0;i<5;i++)
	{
		int tmp=nums[get_Card_number(playerCards[i])]++;
		amount[ tmp ]--;
		amount[ tmp+1 ]++;
	}

	if(amount[2]==2)
		return true;

	return false;
}

bool PokerGame::isOnePair()
{
	//TO_DO: Check whether the hand of cards is OnePair or not
	
	int nums[13]={0},amount[5]={0};
	for(int i=0;i<5;i++)
	{
		int tmp=nums[get_Card_number(playerCards[i])]++;
		amount[ tmp ]--;
		amount[ tmp+1 ]++;
	}

	if(amount[2]==1)
		return true;
		
	return false;
}



