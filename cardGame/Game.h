#pragma once

#include <list>

class Player;
class Trick;
class Deck;
class Settings;

class Game
{
public:
	Game(const Settings* settings, unsigned int numRounds=1);
	virtual ~Game(void);

	void AddPlayer(Player* player);
	void Play(void);
	void PlayRound(void);
	void PlayTrick(void);

	Player* GetWinner(void) const;

private:
	void reset(void);
	unsigned int count_cards(void) const;

	bool m_gameOver;
	std::list<Player*> m_players;
	Deck* m_deck;
	const Settings *m_settings;
	Player* m_lastWinner;
	std::list<Trick*> m_tricks;
	unsigned int m_numRounds;
	unsigned int m_roundsPlayed;

};

