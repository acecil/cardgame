#include "StdAfx.h"

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
