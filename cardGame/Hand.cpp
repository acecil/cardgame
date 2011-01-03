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

#include <set>

#include "Hand.h"

#include "Card.h"

Hand::Hand(void)
{
}


Hand::~Hand(void)
{
}

void Hand::Deal(Card* card)
{
	m_cards.insert(card);
}

bool Hand::Find(Card* card) const
{
	std::set<Card*, CardLess>::iterator c;
	for(c = m_cards.begin(); c != m_cards.end(); ++c)
	{
		if(CardEqual()(*c, card))
		{
			return true;
		}
	}
	return false;
}

void Hand::Remove(Card* card)
{
	std::set<Card*, CardLess>::iterator c;
	for(c = m_cards.begin(); c != m_cards.end(); ++c)
	{
		if(CardEqual()(*c, card))
		{
			m_cards.erase(c);
			return;
		}
	}
}

unsigned int Hand::GetNumCards(void) const
{ 
	return m_cards.size(); 
}

unsigned int Hand::CountOfSuit(Suit suit) const
{
	unsigned int num_cards = 0;
	std::set<Card*, CardLess>::iterator c;
	for(c = m_cards.begin(); c != m_cards.end(); ++c)
	{
		if((*c)->GetSuit() == suit)
		{
			num_cards++;
		}
	}

	return num_cards;
}


std::string Hand::ToString(void) const
{
	std::string str;

	std::set<Card*, CardLess>::const_iterator c;

	for(c = m_cards.begin(); c != m_cards.end(); ++c)
	{
		str += (*c)->ToString() + " ";
	}

	return str;
}
