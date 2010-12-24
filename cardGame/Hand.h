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

