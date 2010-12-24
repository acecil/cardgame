#pragma once

#include <vector>

class Card;

class Deck
{
public:
	typedef std::vector<Card*>::iterator CardIt;
	Deck(void);
	virtual ~Deck(void);

	void Shuffle(void);

	CardIt Begin(void) { return m_cards.begin(); }
	CardIt End(void) { return m_cards.end(); }


private:
	std::vector<Card*> m_cards;

	static const unsigned int m_cardsInSuit = 13;
};

