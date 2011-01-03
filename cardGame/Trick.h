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
#include <utility>
#include <string>

#include "Card.h"

class Player;
class Settings;
class Card;
class Hand;

class Trick
{
public:
	Trick(const Settings* settings, std::list<Player*> players, Suit trumps=(Suit)0);
	virtual ~Trick(void);

	void Play(Player* player, Card* card);
	Player* Score(void);
	bool Complete(void) const;

	bool IsValidCardToPlay(Hand *hand, Card *card);

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

