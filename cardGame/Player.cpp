#include "StdAfx.h"

#include <iostream>
#include <cassert>

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

Card* Player::PlayCard(Trick* trick)
{
	std::cout << ToString() << std::endl;
	std::cout << "Your cards: " << m_hand->ToString() << std::endl;
	std::cout << "Trick: " << trick->ToString() << std::endl;

	Card* card;

	while(true)
	{
		unsigned int num;
		char suitChar;
		std::cin >> num >> suitChar;
		Suit::Suit suit = Suit::FromChar(suitChar);

		card = new Card((Suit::Suit)suit, num);

		if(m_hand->Find(card))
		{
			m_hand->Remove(card);
			return card;
		}

		std::cout << "Invalid choice" << std::endl;
	}

	std::cout << std::endl;

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
