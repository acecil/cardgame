#pragma once

#include <list>
#include <utility>
#include <string>

class Player;
class Settings;
class Card;

class Trick
{
public:
	Trick(const Settings* settings, std::list<Player*> players);
	virtual ~Trick(void);

	void Play(Player* player, Card* card);
	std::list<Player*>::iterator Score(void);
	bool Complete(void) const;

	std::string ToString(void) const;

private:
	std::list<std::pair<Player*, Card*> > m_cards;
	const Settings* m_settings;
	std::list<Player*> m_players;
	Player* m_winningPlayer;
};

