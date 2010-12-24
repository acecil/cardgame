#include "StdAfx.h"

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
	return (m_cards.find(card) != m_cards.end());
}

void Hand::Remove(Card* card)
{
	m_cards.erase(card);
}

std::string Hand::ToString(void) const
{
	std::string str;

	std::set<Card*>::iterator c;

	for(c = m_cards.begin(); c != m_cards.end(); ++c)
	{
		str += (*c)->ToString() + " ";
	}

	return str;
}
