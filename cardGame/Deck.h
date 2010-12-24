#pragma once

#include <list>

class Card;

class Deck
{
public:
	typedef std::list<Card*>::iterator CardIt;
	Deck(void);
	virtual ~Deck(void);

	void Shuffle(void);

	CardIt Begin(void) { return m_cards.begin(); }
	CardIt End(void) { return m_cards.end(); }


private:
	std::list<Card*> m_cards;

	static const unsigned int m_cardsInSuit = 13;
};

