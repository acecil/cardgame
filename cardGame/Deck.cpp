#include "StdAfx.h"

#include <algorithm>

#include "Deck.h"

#include "Card.h"

Deck::Deck(void)
{
	for(Suit::Suit s = Suit::Begin(); s != Suit::End(); s = Suit::Next(s))
	{
		for(int n = 0; n < 13; n++)
		{
			m_cards.push_back(new Card(s, n + 1));
		}
	}
}


Deck::~Deck(void)
{
	while(!m_cards.empty())
	{
		delete m_cards.front();
		m_cards.pop_front();
	}
}

void Deck::Shuffle(void)
{
	random_shuffle(m_cards.begin(), m_cards.end());
}