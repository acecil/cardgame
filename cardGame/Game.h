#pragma once

#include <list>

class Player;
class Trick;
class Deck;
class Settings;

class Game
{
public:
	Game(const Settings* settings);
	virtual ~Game(void);

	void AddPlayer(Player* player);
	void Play(void);
	void PlayTrick(void);

	Player* GetWinner(void);

private:
	void reset(void);

	bool m_gameOver;
	std::list<Player*> m_players;
	Deck *m_deck;
	const Settings *m_settings;
	std::list<Player*>::iterator m_lastWinnerIt;
	std::list<Trick*> m_tricks;

};

