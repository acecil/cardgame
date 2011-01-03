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

#include <set>
#include <string>

#include "Card.h"

class Card;
class CardLess;
enum Suit;

class Hand
{
public:
	Hand(void);
	virtual ~Hand(void);

	void Deal(Card* card);
	bool Find(Card* card) const;
	void Remove(Card* card);

	unsigned int GetNumCards(void) const;
	unsigned int CountOfSuit(Suit suit) const;

	std::string ToString(void) const;

private:
	std::set<Card*, CardLess> m_cards;
};

