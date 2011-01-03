/*
 * (c) Copyright 2010, 2011, Andrew Gascoyne-Cecil, Winni Lam.
 *
 * This file is part of CardGame.
 *
 * CardGame is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CardGame is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CardGame.  If not, see <http://www.gnu.org/licenses/>.
 */

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

Card* Player::PlayCard(Trick* trick)
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
			if(trick->IsValidCardToPlay(m_hand, card))
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
