#pragma once

#include <set>
#include <string>

class Card;
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
	std::set<Card*> m_cards;
};

