#pragma once

#include <string>
#include <cassert>
#include <list>

#include "Player.h"

namespace Suit
{
	enum Suit
	{
		FirstSuit = 0,
		Clubs = 0,
		Diamonds,
		Hearts,
		Spades,
		LastSuit
	};
	inline Suit Next(Suit suit) { return (Suit)(suit + 1); }
	inline Suit Begin(void) { return FirstSuit; }
	inline Suit End(void) { return LastSuit; }
	Suit FromChar(char ch);
}

class Card
{
public:
	Card(void);
	Card(Suit::Suit suit, unsigned int number);
	virtual ~Card(void);

	std::string ToString(void) const;

	bool Beats(Card*& other) const;

	bool operator<(const Card*& other) const;
	bool operator==(const Card*& other) const { return ((other->m_number == m_number) && (other->m_suit == m_suit)); }

private:
	unsigned int m_number;
	Suit::Suit m_suit;
};

