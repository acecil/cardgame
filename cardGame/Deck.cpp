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
