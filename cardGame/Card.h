#pragma once

#include <string>
#include <cassert>
#include <list>

enum Suit
{
	FirstSuit = 0,
	Clubs = 0,
	Diamonds,
	Hearts,
	Spades,
	LastSuit
};

Suit SuitFromChar(char ch);
char SuitToChar(Suit suit);
std::string SuitToString(Suit suit);

class Card
{
public:
	Card(void);
	Card(Suit suit, unsigned int number);
	virtual ~Card(void);

	Suit GetSuit(void) const { return m_suit; }
	unsigned int GetNumber(void) const { return m_number; }

	std::string ToString(void) const;

	bool Beats(Card*& other, Suit trumps, bool useTrumps) const;

	bool operator<(const Card*& other) const;
	bool operator<(const Card& other) const;
	bool operator==(const Card& other) const { return ((m_number == other.m_number) && (m_suit == other.m_suit)); }

	static Card* FromString(std::string &str);

private:
	unsigned int m_number;
	Suit m_suit;
};

