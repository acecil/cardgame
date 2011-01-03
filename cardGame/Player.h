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

#include <string>

class Hand;
class Trick;
class Card;

class Player
{
public:
	Player(void);
	Player(std::string name);
	~Player(void);

	void Reset(void) { m_score = 0; }

	void Deal(Hand* hand);

	Card* PlayCard(Trick* trick);

	int GetScore(void) const;
	void AddScore(int score);

	unsigned int GetNumCards(void) const;

	std::string ToString(void) const { return m_name; }

	bool operator<(Player*& other){ return other->m_name < m_name; }

private:
	std::string m_name;
	int m_score;
	Hand* m_hand;
	
};
