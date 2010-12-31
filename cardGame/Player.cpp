

#include <iostream>
#include <cassert>
#include <limits>

#include "Player.h"

#include "Hand.h"
#include "Trick.h"
#include "Card.h"


Player::Player(void)
{
}

Player::Player(std::string name)
{
	m_name = name;
}

Player::~Player(void)
{
}

void Player::Deal(Hand* hand)
{ 
	m_hand = hand;
}

Card* Player::PlayCard(Trick* trick, bool followSuit)
{
	std::cout << ToString() << std::endl;
	std::cout << "Your cards: " << m_hand->ToString() << std::endl;
	std::cout << "Trick: " << trick->ToString() << std::endl;

	Card* card;

	while(true)
	{
		std::string str;

		while(!(std::cin >> str))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input" << std::endl;
		}
		
		card = Card::FromString(str);
		if(!card)
		{
			std::cout << "Invalid input" << std::endl;
			continue;
		}

		Suit suit = card->GetSuit();

		if(m_hand->Find(card))
		{
			if(!followSuit || (trick->GetNumCards() == 0)
				|| (trick->GetFirstSuit() == suit)
				|| (m_hand->CountOfSuit(trick->GetFirstSuit()) == 0))
			{
				m_hand->Remove(card);
				return card;
			}
		}

		std::cout << "Invalid choice" << std::endl;
	}

	assert(true);

	return card;
}

int Player::GetScore(void) const
{
	return m_score;
}

void Player::AddScore(int score)
{
	m_score += score;
}

unsigned int Player::GetNumCards(void) const
{ 
	return m_hand->GetNumCards();
}
