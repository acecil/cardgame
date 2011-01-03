/*
 * (c) Copyright 2010, 2011, Andrew Gascoyne-Cecil, Winni Lam.
 *
 * This file is part of CardGame.
 *
 * CardGame is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CardGame is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CardGame.  If not, see <http://www.gnu.org/licenses/>.
 */

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
	void PrintResult(void) const;

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

