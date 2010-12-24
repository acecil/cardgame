#include "StdAfx.h"

#include "Trick.h"

#include "Settings.h"
#include "Player.h"
#include "Card.h"

Trick::Trick(const Settings* settings, std::list<Player*> players)
{ 
	m_settings = settings;
	m_players = players;
}

Trick::~Trick(void)
{
}

void Trick::Play(Player* player, Card* card)
{
	if(m_cards.empty())
	{
		m_winningPlayer = player;
	}
	else
	{
		if(card->Beats(m_cards.front().second))
		{
			m_winningPlayer = player;
		}
	}

	m_cards.push_back(std::pair<Player*, Card*>(player, card));

}

std::list<Player*>::iterator Trick::Score(void)
{
	std::list<Player*>::iterator p;
	std::list<Player*>::iterator winnerIt;

	for(p = m_players.begin(); p != m_players.end(); ++p)
	{
		/* This currently only works for whist. */
		if(*p == m_winningPlayer)
		{
			winnerIt = p;
			(*p)->AddScore(1);
		}
	}

	return winnerIt;
}

bool Trick::Complete(void) const
{
	/* This needs to depend on settings. */
	return (m_cards.size() == m_players.size());
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