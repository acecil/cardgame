#include "StdAfx.h"

#include <sstream>
#include <cassert>
#include <list>

#include "Card.h"

Suit SuitFromChar(char ch)
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

	return FirstSuit;
}

Card::Card(void)
{
}

Card::Card(Suit suit, unsigned int number)
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
	
	switch(m_number)
	{
	case 1:
		ss << "A";
		break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		ss << m_number;
		break;
	case 11:
		ss << "J";
		break;
	case 12:
		ss << "Q";
		break;
	case 13:
		ss << "K";
		break;
	default:
		assert(true);
	}

	switch(m_suit)
	{
	case Clubs:
		ss << "C";
		break;
	case Diamonds:
		ss << "D";
		break;
	case Hearts:
		ss << "H";
		break;
	case Spades:
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

bool Card::operator<(const Card& other) const
{
	if(other.m_suit == this->m_suit)
	{
		return(other.m_number < this->m_number);
	}
	return(other.m_suit < this->m_suit);
}