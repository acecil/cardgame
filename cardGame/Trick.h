#pragma once

#include <list>
#include <utility>
#include <string>

#include "Card.h"

class Player;
class Settings;
class Card;

class Trick
{
public:
	Trick(const Settings* settings, std::list<Player*> players, Suit trumps=(Suit)0);
	virtual ~Trick(void);

	void Play(Player* player, Card* card);
	Player* Score(void);
	bool Complete(void) const;

	unsigned int GetNumCards(void) const;
	Suit GetFirstSuit(void) const;

	std::string ToString(void) const;

private:
	std::list<std::pair<Player*, Card*> > m_cards;
	const Settings* m_settings;
	std::list<Player*> m_players;
	Player* m_winningPlayer;
	Card* m_winningCard;
	Suit m_trumps;
};

