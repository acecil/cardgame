#include "StdAfx.h"

#include <iostream>

#include "Game.h"

#include "Deck.h"
#include "Player.h"
#include "Hand.h"
#include "Card.h"
#include "Settings.h"
#include "Trick.h"

Game::Game(const Settings* settings)
{
	m_settings = settings;

	m_deck = new Deck();
}


Game::~Game(void)
{
	if(m_deck) delete m_deck;

	while(!m_players.empty())
	{
		delete m_players.front();
		m_players.pop_front();
	}

	while(!m_tricks.empty())
	{
		delete m_tricks.front();
		m_tricks.pop_front();
	}
}

void Game::AddPlayer(Player* player)
{
	m_players.push_back(player);
}

void Game::Play(void)
{
	reset();

	while(!m_gameOver)
	{
		PlayTrick();
	}
}

void Game::PlayTrick(void)
{
	/* Shuffle */
	m_deck->Shuffle();

	/* Deal */
	unsigned int numPlayers = m_players.size();
	std::list<Hand*> hands;

	for(unsigned int i = 0; i < numPlayers; i++)
	{
		hands.push_back(new Hand());
	}
	
	std::list<Card*>::iterator c = m_deck->Begin();
	std::list<Hand*>::iterator h;
	for(unsigned int i = 0; i < m_settings->CardsPerPlayer; i++)
	{
		for(h = hands.begin(); h != hands.end(); ++h)
		{
			(*h)->Deal(*c);
			c++;
		}
	}

	std::list<Player*>::iterator p;
	for(p = m_players.begin(), h = hands.begin(); p != m_players.end(), h != hands.end(); ++p, ++h)
	{
		(*p)->Deal(*h);
	}

	/* Play */
	std::list<Player*>::iterator playerIt = m_players.begin();
	if(m_settings->LastWinnerPlaysFirst)
	{
		if(m_lastWinnerIt != m_players.end())
		{
			playerIt = m_lastWinnerIt;
		}
	}
	
	Trick *trick = new Trick(m_settings, m_players);

	while(!trick->Complete())
	{
		trick->Play(*playerIt, (*playerIt)->PlayCard(trick));

		if(m_settings->PlayInOrder)
		{
			playerIt++;			
		}
		else
		{
			/* Determine next player by some other means here. */
			playerIt++;
		}
	}

	/* Score */
	m_lastWinnerIt = trick->Score();

	for(p = m_players.begin(); p != m_players.end(); ++p)
	{
		std::cout << (*p)->ToString() << ": " << (*p)->GetScore() << std::endl;
	}

	m_tricks.push_back(trick);
}

Player* Game::GetWinner(void)
{
	Player* winner;
	int maxScore = 0;

	std::list<Player*>::iterator i;
	for(i = m_players.begin(); i != m_players.end(); ++i)
	{
		if((*i)->GetScore() > maxScore)
		{
			winner = *i;
			maxScore = (*i)->GetScore();
		}
	}

	return winner;
}

void Game::reset(void)
{
	std::list<Trick*>::iterator t;
	for(t = m_tricks.begin(); t != m_tricks.end(); ++t)
	{
		delete m_tricks.front();
		m_tricks.pop_front();
	}

	m_gameOver = false;

	m_lastWinnerIt = m_players.end();

	std::list<Player*>::iterator p;
	for(p = m_players.begin(); p != m_players.end(); ++p)
	{
		(*p)->Reset();
	}
}
