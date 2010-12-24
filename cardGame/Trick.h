#pragma once

#include <list>
#include <utility>
#include <string>

class Player;
class Settings;
class Card;
enum Suit;

class Trick
{
public:
	Trick(const Settings* settings, std::list<Player*> players);
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
};

