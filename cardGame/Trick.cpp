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

#include <cassert>

#include "Trick.h"

#include "Settings.h"
#include "Player.h"
#include "Card.h"
#include "Hand.h"

Trick::Trick(const Settings* settings, std::list<Player*> players, Suit trumps)
{ 
	m_settings = settings;
	m_players = players;
	m_trumps = trumps;
}

Trick::~Trick(void)
{
}

void Trick::Play(Player* player, Card* card)
{
	if(m_cards.empty())
	{
		m_winningPlayer = player;
		m_winningCard = card;
	}
	else
	{
		if(card->Beats(m_winningCard, m_trumps, m_settings->Trumps))
		{
			m_winningPlayer = player;
			m_winningCard = card;
		}
	}

	m_cards.push_back(std::pair<Player*, Card*>(player, card));

}

Player* Trick::Score(void)
{
	std::list<Player*>::iterator p;

	for(p = m_players.begin(); p != m_players.end(); ++p)
	{
		/* This currently only works for whist. */
		if(*p == m_winningPlayer)
		{
			(*p)->AddScore(1);
			return *p;
		}
	}

	assert(true);

	return NULL;
}

bool Trick::Complete(void) const
{
	/* This needs to depend on settings. */
	return (m_cards.size() == m_players.size());
}

bool Trick::IsValidCardToPlay(Hand *hand, Card *card)
{
	if(!m_settings->FollowSuit || (GetNumCards() == 0)
		|| (GetFirstSuit() == card->GetSuit())
		|| (hand->CountOfSuit(GetFirstSuit()) == 0))
	{
		return true;
	}

	return false;
}

unsigned int Trick::GetNumCards(void) const
{ 
	return m_cards.size(); 
}

Suit Trick::GetFirstSuit(void) const
{
	return m_cards.front().second->GetSuit();
}

std::string Trick::ToString(void) const
{
	std::string str;

	std::list<std::pair<Player*, Card*> >::const_iterator i;
	for(i = m_cards.begin(); i != m_cards.end(); ++i)
	{
		if(i != m_cards.begin())
		{
			str += ", ";
		}
		str += i->first->ToString() + ": " + i->second->ToString();
	}

	return str;
}
