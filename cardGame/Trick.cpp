

#include <cassert>

#include "Trick.h"

#include "Settings.h"
#include "Player.h"
#include "Card.h"

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
