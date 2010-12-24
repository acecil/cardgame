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

char SuitToChar(Suit suit)
{
	switch(suit)
	{
	case Clubs:
		return 'C';
	case Diamonds:
		return 'D';
	case Hearts:
		return 'H';
	case Spades:
		return 'S';
	default:
		assert(true);
		return 0;
	}
}

std::string SuitToString(Suit suit)
{
	switch(suit)
	{
	case Clubs:
		return "Clubs";
	case Diamonds:
		return "Diamonds";
	case Hearts:
		return "Hearts";
	case Spades:
		return "Spades";
	default:
		assert(true);
		return "";
	}
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

	ss << SuitToChar(m_suit);

	std::string str;
	ss >> str;

	return str;
}


bool Card::Beats(Card*& other, Suit trumps, bool useTrumps) const
{
	if(m_suit == other->m_suit)
	{
		if(m_number > other->m_number)
		{
			return true;
		}
	}
	if(useTrumps && (other->m_suit != trumps) && (m_suit == trumps))
	{
		return true;
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

Card* Card::FromString(std::string &str)
{
	std::stringstream ss;
	ss << str;

	if(str.size() < 2)
	{
		return NULL;
	}
	
	unsigned int num;
	Suit suit;
	char dummy;

	switch(str[0])
	{
	case 'A':
	case 'a':
		num = 1;
		ss >> dummy;
		break;
	case 'K':
	case 'k':
		num = 13;
		ss >> dummy;
		break;
	case 'Q':
	case 'q':
		num = 12;
		ss >> dummy;
		break;
	case 'J':
	case 'j':
		num = 11;
		ss >> dummy;
		break;
	default:
		{
			ss >> num;
		}
	}

	if(num < 1 || num > 13)
	{
		return NULL;
	}

	ss >> dummy;
	suit = SuitFromChar(dummy);

	return new Card(suit, num);
}