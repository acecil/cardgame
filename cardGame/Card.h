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
#include <cassert>
#include <list>

enum Suit
{
	FirstSuit = 0,
	Clubs = 0,
	Diamonds,
	Hearts,
	Spades,
	LastSuit
};

Suit SuitFromChar(char ch);
char SuitToChar(Suit suit);
std::string SuitToString(Suit suit);

class Card;

class CardEqual
{
public:
	bool operator()(Card* lhs, Card* rhs);
};

class CardLess
{
public:
	bool operator()(Card* lhs, Card* rhs);
};

class Card
{
public:
	Card(void);
	Card(Suit suit, unsigned int number);
	virtual ~Card(void);

	Suit GetSuit(void) const { return m_suit; }
	unsigned int GetNumber(void) const { return m_number; }

	std::string ToString(void) const;

	bool Beats(Card*& other, Suit trumps, bool useTrumps) const;

	static Card* FromString(std::string &str);
	static void SetAcesHigh(bool acesHigh) { m_acesHigh = acesHigh; }
	static bool GetAcesHigh(void) { return m_acesHigh; }

private:
	unsigned int m_number;
	Suit m_suit;

	static bool m_acesHigh;
};

