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
#pragma once

#include <vector>

class Card;

class Deck
{
public:
	typedef std::vector<Card*>::iterator CardIt;
	Deck(void);
	virtual ~Deck(void);

	void Shuffle(void);

	CardIt Begin(void) { return m_cards.begin(); }
	CardIt End(void) { return m_cards.end(); }


private:
	std::vector<Card*> m_cards;

	static const unsigned int m_cardsInSuit = 13;
};

