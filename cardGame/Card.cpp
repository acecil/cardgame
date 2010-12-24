#include "StdAfx.h"

#include <sstream>
#include <cassert>
#include <list>

#include "Card.h"

Suit::Suit Suit::FromChar(char ch)
{
	switch(ch)
	{
	case 'c':
	case 'C':
		return Clubs;
	case 'd':
	case 'D':
		return Diamonds;
	case 'h':
	case 'H':
		return Hearts;
	case 's':
	case 'S':
		return Spades;
	default:
		assert(true);
	}

	return (Suit)0;
}

Card::Card(void)
{
}

Card::Card(Suit::Suit suit, unsigned int number)
{
	m_suit = suit;
	m_number = number;
}

Card::~Card(void)
{
}

std::string Card::ToString(void) const
{
	std::stringstream ss;
	ss << m_number;

	switch(m_suit)
	{
	case Suit::Clubs:
		ss << "C";
		break;
	case Suit::Diamonds:
		ss << "D";
		break;
	case Suit::Hearts:
		ss << "H";
		break;
	case Suit::Spades:
		ss << "S";
		break;
	default:
		assert(true);
	}

	std::string str;
	ss >> str;

	return str;
}


bool Card::Beats(Card*& other) const
{
	if(m_suit == other->m_suit)
	{
		if(m_number > other->m_number)
		{
			return true;
		}
	}

	return false;
}

bool Card::operator<(const Card*& other) const
{
	if(other->m_suit == this->m_suit)
	{
		return(other->m_number < this->m_number);
	}
	return(other->m_suit < this->m_suit);
}