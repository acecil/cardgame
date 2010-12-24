#include "StdAfx.h"

#include <algorithm>

#include "Deck.h"

#include "Card.h"

Deck::Deck(void)
{
	for(Suit s = FirstSuit; s != LastSuit; s = (Suit)(s + 1))
	{
		for(int n = 0; n < 13; n++)
		{
			m_cards.push_back(new Card(s, n + 1));
		}
	}
}


Deck::~Deck(void)
{
	std::vector<Card*>::iterator c;
	for(c = m_cards.begin(); c != m_cards.end(); ++c)
	{
		delete *c;
	}
}

void Deck::Shuffle(void)
{
	random_shuffle(m_cards.begin(), m_cards.end());
}