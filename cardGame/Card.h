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

class Card;

class CardEqual
{
public:
	bool operator()(Card* lhs, Card* rhs);
};

class CardLess
{
public:
	bool operator()(Card* lhs, Card* rhs);
};

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

	static Card* FromString(std::string &str);
	static void SetAcesHigh(bool acesHigh) { m_acesHigh = acesHigh; }
	static bool GetAcesHigh(void) { return m_acesHigh; }

private:
	unsigned int m_number;
	Suit m_suit;

	static bool m_acesHigh;
};

