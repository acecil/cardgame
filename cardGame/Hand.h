#pragma once

#include <set>
#include <string>

class Card;

class Hand
{
public:
	Hand(void);
	virtual ~Hand(void);

	void Deal(Card* card);
	bool Find(Card* card) const;
	void Remove(Card* card);

	std::string ToString(void) const;

private:
	std::set<Card*> m_cards;
};

